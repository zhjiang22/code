const maxn=20000;
      maxt=100000;
type re=record
       data,pos:int64;
end;
var e,e2,i,n,t,t2,heapsize:longint;
    a:array [0..maxn,1..3] of int64;
    f:array [0..maxt] of int64;
    heap:array [0..maxn] of re;
procedure change(var a,b:re);
var temp:re;
begin
  temp:=a;
  a:=b;
  b:=temp;
end;
procedure insert(pos,data:int64);
var now,next:longint;
begin
  inc(heapsize);
  heap[heapsize].pos:=pos;
  heap[heapsize].data:=data;
  now:=heapsize;
  while now<>1 do
    begin
      next:=now div 2;
      if heap[now].data>=heap[next].data then exit;
      change(heap[now],heap[next]);
      now:=next;
    end;
end;
procedure delete;
var now,next:longint;
begin
  heap[1]:=heap[heapsize];
  heap[heapsize].data:=0;
  heap[heapsize].pos:=0;
  dec(heapsize);
  now:=1;
  while now*2<=heapsize do
    begin
      next:=now*2;
      if (next<heapsize)and(heap[next+1].data<heap[next].data) then inc(next);
      if heap[now].data<=heap[next].data then exit;
      change(heap[now],heap[next]);
      now:=next;
    end;
end;
procedure work;
var i:longint;
begin
  heapsize:=1;
  heap[1].data:=0;
  heap[1].pos:=0;
  fillchar(f,sizeof(f),0);
  for i:=1 to n do
    begin
      while (heapsize>0)and(heap[1].pos<a[i,1]-1) do delete;
       	if heapsize=0 then
          begin
            writeln(-1);
            exit;
          end;
        if (heap[1].data+a[i,3]<f[a[i,2]])or(f[a[i,2]]=0) then
          begin
            f[a[i,2]]:=heap[1].data+a[i,3];
            insert(a[i,2],heap[1].data+a[i,3]);
          end;
      end;
  if f[t]=0 then writeln(-1)
  else writeln(f[t]);
end;
procedure sor(x,y:longint);
var i,k:longint;
begin
  for i:=1 to 3 do
    begin
      k:=a[x,i];
      a[x,i]:=a[y,i];
      a[y,i]:=k;
    end;
end;
procedure sort(l,r:longint);
var i,j:longint;
begin
  i:=l;
  j:=r;
  while i<j do
    begin
      while (i<j)and((a[i,1]<a[j,1])or(a[i,1]=a[j,1])and(a[i,2]<=a[j,2])) do j:=j-1;
      sor(i,j);
      while (i<j)and((a[i,1]<a[j,1])or(a[i,1]=a[j,1])and(a[i,2]<=a[j,2])) do i:=i+1;
      sor(i,j);
    end;
  if l<i-1 then sort(l,i-1);
  if j+1<r then sort(j+1,r);
end;
begin
  readln(n,e2,t2);
  e:=e2-1;
  t:=t2-e;
  for i:=1 to n do
    begin
      readln(a[i,1],a[i,2],a[i,3]);
      if a[i,1]<e2 then a[i,1]:=e2;
      if a[i,2]>t2 then a[i,2]:=t2;
      a[i,1]:=a[i,1]-e;
      a[i,2]:=a[i,2]-e;
    end;
  sort(1,n);
  work;
end.
