program isbn(input,ouput);
var
  p,i,m:integer;
  tt:longint;
  mch,s:string;
  ch:char;
  a:array[1..30] of integer;
begin
  p:=1;
  for i:= 1 to 13 do
  begin
    read(ch);
    s:=s+ch;
    if ch<>'-' then
    begin
      val(ch,a[p]);
      inc(p);
    end;
  end;
  tt:=0;
  for i := 1 to 9 do
    tt:=tt+a[i]*i;
  m:=tt mod 11;
  if m=10 then mch:='X'
   else str(m,mch);
  if mch=s[13] then writeln('Right')
   else begin
    for i:= 1 to 12 do write(s[i]);
    writeln(mch);
   end;
end.