#include <iostream>
#include <cstdio>
#include <algorithm>
/*
#include <cstring>
#include <set>
#include <queue>
using namespace std;

typedef int stade[9];
stade start;
stade goal={0};
struct node
{
  stade x;
  vector<int> v;
};
stade l;
bool s[4][4][4][4][4][4][4][4][4];
queue<node> q;
int da[9][9] = { 
    {0, 1, 3, 4, -1 },
    {0, 1, 2, -1 }, 
    {1, 2, 4, 5, -1 },
    {0, 3, 6, -1 },
    {1,3,4,5,7,-1},
    {2,5,8,-1},
    {3,4,6,7,-1},
    {6,7,8,-1},
    {4,5,7,8,-1}
};

void change(node p,int x)
{
  memcpy(&l,&p.x,sizeof(p.x));
  for(int i=0;da[x][i]!=-1;i++)
  {
    l[da[x][i]]++;
    l[da[x][i]]%=4;
  }
}

bool check(stade po)
{
  if(s[po[0]][po[1]][po[2]][po[3]][po[4]][po[5]]
        [po[6]][po[7]][po[8]]==0)
    return 1;
  else 
    return 0;
}

void check1(stade po)
{
  s[po[0]][po[1]][po[2]][po[3]][po[4]][po[5]]
        [po[6]][po[7]][po[8]]=1;
}

void bfs()
{
  node a;
  memcpy(&a.x,&start,sizeof(start));
  a.v.clear();
  q.push(a);
  check1(a.x);
  while(!q.empty())
  {
    node p=q.front();
    if(memcmp(p.x,goal,sizeof(goal))==0)
    {
      for(int i=0;i<p.v.size();i++)
        cout<<p.v[i]+1<<" ";
        return;
    }
    for(int i=0;i<=8;i++)
    {
      change(p,i);
      if(check(l))
      {
        node newq;
        memcpy(&newq.x,&l,sizeof(l));
        newq.v=p.v;
        newq.v.push_back(i);
        q.push(newq);
        check1(l);
      }
    }
    q.pop();
  }
}

int main()
{
  for(int i=0;i<=8;i++)
    cin>>start[i];
  bfs();
  return 0;
}
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef int stade[9];
stade start;
int head,tail;
stade goal={0};
stade l;
int Rank[1000000];
int c[1000000];
bool s[4][4][4][4][4][4][4][4][4];
stade q[1000000];
int da[9][9] = { 
    {0, 1, 3, 4, -1 },
    {0, 1, 2, -1 }, 
    {1, 2, 4, 5, -1 },
    {0, 3, 6, -1 },
    {1,3,4,5,7,-1},
    {2,5,8,-1},
    {3,4,6,7,-1},
    {6,7,8,-1},
    {4,5,7,8,-1}
};

void Out(int x)
{
  if(x>1)
  {
    Out(Rank[x]);
    cout<<c[x]<<" ";
  }
}

void change(stade &p,int x)
{
  memcpy(&l,&p,sizeof(p));
  for(int i=0;da[x][i]!=-1;i++)
  {
    l[da[x][i]]++;
    l[da[x][i]]%=4;
  }
}

bool check(stade po)
{
  if(s[po[0]][po[1]][po[2]][po[3]][po[4]][po[5]]
        [po[6]][po[7]][po[8]]==0)
    return 1;
  else 
    return 0;
}

void check1(stade po)
{
  s[po[0]][po[1]][po[2]][po[3]][po[4]][po[5]]
        [po[6]][po[7]][po[8]]=1;
}

void bfs()
{
  memcpy(&q[head],&start,sizeof(start));
  tail++;
  check1(start);
  while(head<=tail)
  {
    stade &p=q[head];
    for(int i=0;i<=8;i++)
    {
      change(p,i);
      if(check(l))
      {
        memcpy(&q[tail],&l,sizeof(l));
        Rank[tail]=head;
        c[tail]=i+1;
        check1(l);
        if(memcmp(goal,l,sizeof(l))==0)
          {
            Out(tail);
            return;
          }
        tail++;
      }
    }
    head++;
  }
}

int main()
{
  for(int i=0;i<=8;i++)
  {
    int x;
    cin>>x;
    start[i]=(x/3)%4;
  }
  bfs();
  return 0;
}