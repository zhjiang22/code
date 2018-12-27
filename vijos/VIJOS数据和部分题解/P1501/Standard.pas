var
n:longint;
u,d:longint;
max:int64;
function run(ceng:integer):char;
var
ch,ch1,ch2:char;
begin
if ceng=0 then
read(ch)
else begin
ch1:=run(ceng-1);
ch2:=run(ceng-1);
if ch1=ch2 then ch:=ch1 else ch:='-';
end;
if (ceng<=u)and(ceng>=d) Then
case ch of
'1':inc(max,2);
'-':inc(max,1);
'0':inc(max,5);
End;
run:=ch;
end;
begin
readln(n);
readln(u,d);
run(n);
writeln(max);
end.
