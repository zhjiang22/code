{【算法】
1、求得m的二进制表示：f[r..1] 
2、根据输入数据得到n个灯泡的初始状态x[0,1],x[0,2],x[0,3],…,x[0,n]
        其中灯亮的取值1,不亮取值0;
3、C←0;//滚动数组，初始第0行
4、For k←1 to r do   //扫描m的二进制各位
5、   if f[k]=1 then begin
6、     C←1-c;
7、     For j←1 to n do
8、       x[c,j]←x[1-c,j] xor x[1-c,((j-2k-1-1) mod n+n)mod n+1];
      end
9、输出最终n个灯的状态:x[c,1],x[c,2],x[c,3],…,x[c,n]}
var
  i,j,p,m,n,c,jj:longint;
  ch:char;
  f:array[1..40] of longint;
  x:array[0..1,1..100000] of longint;
function fun(n:longint):longint;
  var i,s:longint;
  begin
    s:=1;
    for i:=1 to n do
      s:=s*2;
    fun:=s;
  end;
begin
  readln(n,m);
  for i:=1 to n do
  begin
    read(ch);
    if ch='b' then x[0,i]:=1
      else x[0,i]:=0;
  end;
  fillchar(f,sizeof(f),0);
  p:=0;
  while m>0 do
  begin
    p:=p+1;f[p]:=m mod 2;
    m:=m div 2;
  end;
  c:=0;
  for i:=1 to p do
    if f[i]=1 then begin
      for j:=1 to n do
      begin
        jj:=(j-1 shl (i-1)) mod n;
        if jj<1 then jj:=jj+n;
        x[1-c,j]:=x[c,j] xor x[c,jj];
      end;
      c:=1-c;
    end;
  for i:=1 to n do
    if x[c,i]=1 then write('b')
      else write('d');
end.
