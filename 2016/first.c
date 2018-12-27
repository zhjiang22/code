#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

typedef struct Point
{
	int x, y;
	struct Point *nxt;
} Point;
char g[12][12];
int food_x = -1, food_y = -1;
Point *front, *rear;
int score;

void game_begin_print()
{
	system("cls");
	printf("This is snake game \n\n\n");
	printf("Enter 'W' 'S' 'A' 'D' to control the snake's movement\n\n\n");
	printf("Enter 'Z' to end the game\n");
	printf("Once you eat 3 apples,you will become quicker\n");
	printf("Don't eat yourself or get out of the graph\n\n");
	printf("Enjoy the game\n");
	system("pause");
}

void free_queue(Point *front)
{
	Point *p = front->nxt;
	while (front != rear)
	{
		free(front);
		front = p;
		p = front->nxt;
	}
	free(rear);
}

void End_game()
{
	printf("Game is over!!!\n\n\n");
	printf("You finally score is : %d\n\n", score);
	printf("Welcome to play again\n");
	printf("\n\n\n\n\n");
	system("pause");
	free_queue(front);
	exit(0);
}

void radom_food()
{
	srand((unsigned)time(NULL));
	int fx, fy;
	for (;;)
	{
		fx = rand() % 10 + 1;
		fy = rand() % 10 + 1;
		printf("%d %d\n", fx, fy);
		if (fx == food_x && fx == food_y)
			continue;
		Point *p = front->nxt;
		int ok = 1;
		while (p != NULL)
		{
			if (p->x == fx && p->y == fy)
			{
				ok = 0;
				break;
			}
			p = p->nxt;
		}
		if (ok)
			break;
	}
	food_x = fx;
	food_y = fy;
}

void print(Point *Front, Point *Rear)
{
	system("cls");
	printf("Your score is :     %d\n", score);
	printf("\n\n\n\n\n");
	memset(g, 0, sizeof(g));
	Point *p = Front;
	p = p->nxt;
	while (p != rear)
	{
		g[p->x][p->y] = 'X';
		p = p->nxt;
	}
	g[p->x][p->y] = 'H';
	g[food_x][food_y] = '*';
	for (int i = 0; i <= 11; i++)
		g[i][0] = g[i][11] = g[0][i] = g[11][i] = '#';
	for (int i = 0; i <= 11; i++)
	{
		for (int j = 0; j <= 11; j++)
			if (!g[i][j])
				putchar('-');
			else
				putchar(g[i][j]);
		putchar('\n');
	}
}

Point *add(Point *Rear, int fx, int fy)
{
	Point *p = (Point *)malloc(sizeof(Point));
	p->x = fx;
	p->y = fy;
	p->nxt = NULL;
	Rear->nxt = p;
	return p;
}

Point *delete (Point *Front)
{
	Point *p = Front->nxt;
	free(Front);
	return p;
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void snake_move(int idx)
{
	Point *p = rear;
	int nx = p->x + dx[idx], ny = p->y + dy[idx];
	if (nx < 1 || nx > 10 || ny < 1 || ny > 10)
	{
		End_game();
		return;
	}
	if (nx == food_x && ny == food_y)
	{
		rear = add(rear, nx, ny);
		score++;
		radom_food();
		return;
	}
	Point *q = front->nxt;
	while (q != rear)
	{
		if (q->x == nx && q->y == ny)
		{
			End_game();
			return;
		}
		q = q->nxt;
	}
	rear = add(rear, nx, ny);
	front = delete (front);
}

void init()
{
	game_begin_print();
	front = (Point *)malloc(sizeof(Point));
	front->nxt = NULL;
	rear = front;
	for (int i = 1; i <= 5; i++)
	{
		int fx = 1, fy = i;
		rear = add(rear, fx, fy);
	}
	radom_food();
	print(front, rear);
}

void work()
{
	char ch;
	int k = 3;
	int first = 1;
	int cnt = 600;
	while (1)
	{
		Sleep(cnt);
		if (kbhit())
			ch = _getch();
		else
		{
			snake_move(k);
			print(front, rear);
			continue;
		}
		if (ch == 'S' || ch == 's')
			k = 0;
		else if (ch == 'W' || ch == 'w')
			k = 1;
		else if (ch == 'A' || ch == 'a')
			k = 2;
		else if (ch == 'D' || ch == 'd')
			k = 3;
		else if (ch == 'Z' || ch == 'z')
			break;
		else
			continue;
		snake_move(k);
		if(score % 3 == 0 && score != 0 && cnt > 100)
			cnt -= 100;
		print(front, rear);
		first = 1;
	}
}

int main()
{
	init();
	work();
	return 0;
}