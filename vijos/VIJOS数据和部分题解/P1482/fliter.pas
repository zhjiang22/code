program Fliter_YoungBoy;
var
  n,time:longint;

procedure InitInfo;
begin
  readln(n);
end;

procedure Online;
var
  i,x1,x2,x3,x4,l:longint;
  st:string;
begin
  readln(st);
  l:=length(st);
  for x1:=1 to l-3 do
  for x2:=x1+1 to l-2 do
  for x3:=x2+1 to l-1 do
  for x4:=x3+1 to l do
    if ((st[x1]=st[x2]) and (st[x3]=st[x4])) or
       ((st[x1]=st[x4]) and (st[x2]=st[x3])) then
    begin
      writeln('de1ete');
      exit;
    end;
  writeln('safe');
end;

begin
  InitInfo;
  randomize;
  for time:=1 to n do Online;
end.

