program LiarGame_lolanvsFantasy;
  //by lolanv
const maxn=30;
var
  n,m,i,j,t,al,ct,pn,now,old:longint; c:char;
  f:array[1..maxn] of longint;
begin
  readln(n,m,pn);
  repeat
  fillchar(f,sizeof(f),0); al:=1 shl n-1; ct:=0;
  for i:=1 to n do
  begin
    for j:=1 to m do
      begin read(c); if c='1' then inc(f[j],1 shl (i-1)) end;
    readln
  end;
  for i:=0 to al do
  begin
    now:=i; old:=0;
    for j:=1 to m do
    begin
      t:=now;
      now:=(now shr 1 xor now shr 2 xor now shl 1 xor now shl 2 xor now xor old xor f[j]) and al;
      old:=t;
    end;
    if now=0 then inc(ct);
  end;
  writeln(ct); readln; dec(pn)
  until pn=0;
end.