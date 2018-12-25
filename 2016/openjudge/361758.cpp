#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int R, C, W, Y, X,ty, tx;
char m[41][41];

struct Pos
{
	int y, x;
};

char get(Pos &p)
{
	return m[p.y][p.x];
}

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

queue<Pos> q, f;

int bfs()
{
	int sq, sf;
	int dis = 1;
	
	Pos pos, np;
	while (!q.empty())
	{
		sq = q.size();
		while (sq--)
		{
			pos = q.front(); q.pop();
			if (pos.y == ty && pos.x == tx)
				return dis;
			if (get(pos) != '@')	continue;
			m[pos.y][pos.x] = 'r';
			for (int i = 0; i < 4; i++)
			{
				np = pos;
				np.y += dy[i];
				np.x += dx[i];
				
				if (np.y>0 && np.y<=R && np.x>0 && np.x<=C)
					if(get(np) == '@') 
						q.push(np);
			}
		}

		sf = f.size();
		while (sf--)
		{
			pos = f.front(); f.pop();
			if (pos.y == ty && pos.x == tx)
				return -1;
			m[pos.y][pos.x] = '#';
			for (int i = 0; i < 4; i++)
			{
				np = pos;
				np.y += dy[i];
				np.x += dx[i];

				if (np.y>0 && np.y <= R && np.x>0 && np.x <= C) 
					if(get(np) != '#')
						f.push(np);
			}
		}
		dis++;
	}
	return -1;
}

int main()
{
	scanf("%d%d%d", &R, &C, &W);
	getchar();
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			scanf("%c", &m[i][j]);
		}
		getchar();
	}

	while (W--)
	{
		scanf("%d%d", &Y, &X);
		m[Y][X] = '#';
		f.push(Pos{ Y,X });
	}

	scanf("%d%d", &Y, &X);
	q.push(Pos{ Y,X });
	scanf("%d%d", &ty, &tx);

	int ans = bfs();
	
	if (ans < 0) printf("No Answer");
	else
		printf("%d", ans);
}