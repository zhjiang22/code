const maxn=1000000;
var a:array[1..3,1..maxn]of longint;
    n,i,j:longint;
    c:char;
function get(x,y:longint):longint;
var t:longint;
begin
  t:=x-y;
  if t<-6 then t:=26+t
  else if t>6 then t:=t-26;
  get:=t;
end;
function compare(x,y:longint):longint;
var i,t:longint;
begin
  t:=get(a[x][1],a[y][1]);
  for i:=2 to n do
    if get(a[x][i],a[y][i])<>t then
    begin
      compare:=maxlongint;
      exit;
    end;
  compare:=t;
end;
procedure print(x:longint);
var i:longint;
begin
  for i:=n downto 1 do
    write(chr(a[x][i]));
  writeln;
end;
begin
  readln(n);
  for i:=1 to 3 do
  begin
    for j:=1 to n do
    begin
      read(c);
      a[i][j]:=ord(c);
    end;
    readln;
  end;
  for i:=1 to 3 do
    if abs(compare(i,i mod 3+1))=abs(compare(i,(i+1)mod 3+1)) then
    begin
      print(i);
      break;
    end;
end.
