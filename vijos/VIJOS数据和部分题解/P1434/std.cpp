#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAXWID 38
#define MAXHT 100

typedef struct Point Point;
struct Point {
	int r, c;
};

int wid, ht;
char maze[MAXHT*2+1][MAXWID*2+1+2];	/* extra +2 for "\n\0" */
int dist[MAXHT*2+1][MAXWID*2+1];

Point
Pt(int r, int c)
{
    Point p;

    p.r = r;
    p.c = c;
    return p;
}

typedef struct Queue Queue;
struct Queue {
    Point p;
    int d;
};

Queue floodq[MAXHT*MAXWID];
int bq, eq;

/* if no wall between point p and point np, add np to queue with distance d+1 */
void
addqueue(int d, Point p, Point np)
{
    if(maze[(p.r+np.r)/2][(p.c+np.c)/2] == ' ' && maze[np.r][np.c] == ' ') {
	maze[np.r][np.c] = '*';
	floodq[eq].p = np;
	floodq[eq].d = d+1;
	eq++;
    }
}

/* if there is an exit at point exitp, plug it and record a start point
 * at startp */

void
lookexit(Point exitp, Point startp)
{
    if(maze[exitp.r][exitp.c] == ' ') {
	addqueue(0, startp, startp);
	maze[exitp.r][exitp.c] = '#';
    }
}

int
main(void)
{
    Point p;
    int i, r, c, m, d;

    scanf("%d %d\n", &wid, &ht);
    wid = 2*wid+1;
    ht = 2*ht+1;

    for(i=0; i<ht; i++)
	gets(maze[i]);

    /* find exits */
    for(i=1; i<wid; i+=2) {
	lookexit(Pt(0, i), Pt(1, i));
	lookexit(Pt(ht-1, i), Pt(ht-2, i));
    }
    for(i=1; i<ht; i+=2) {
	lookexit(Pt(i, 0), Pt(i, 1));
	lookexit(Pt(i, wid-1), Pt(i, wid-2));
    }

    /* must have found at least one square with an exit */
    /* since two exits might open onto the same square, perhaps eq == 1 */
    assert(eq == 1 || eq == 2);	

    for(bq = 0; bq < eq; bq++) {
	p = floodq[bq].p;
	d = floodq[bq].d;
	dist[p.r][p.c] = d;

	addqueue(d, p, Pt(p.r-2, p.c));
	addqueue(d, p, Pt(p.r+2, p.c));
	addqueue(d, p, Pt(p.r, p.c-2));
	addqueue(d, p, Pt(p.r, p.c+2));
    }

    /* find maximum distance */
    m = 0;
    for(r=0; r<ht; r++)
    for(c=0; c<wid; c++)
	if(dist[r][c] > m)
	    m = dist[r][c];

    printf( "%d\n", m);

    exit(0);
}
