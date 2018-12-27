const maxn=200000;
var x,y,s:array[1..maxn]of longint;
    n,i:longint;
    l,r,m:extended;
function check(v:extended):boolean;
var i:longint;
    t:extended;
begin
  t:=0;
  for i:=1 to n do
  begin
    t:=t+s[i]/v;
    if t<x[i] then
      t:=x[i]
    else if t>y[i] then
    begin
      check:=false;
      exit;
    end;
  end;
  check:=true;
end;
begin
  readln(n);
  for i:=1 to n do
    readln(x[i],y[i],s[i]);
  l:=0;
  r:=1e8;
  repeat
    m:=(l+r)/2;
    if check(m) then r:=m else l:=m;
  until r-l<1e-3;
  writeln(m:0:2);
end.
