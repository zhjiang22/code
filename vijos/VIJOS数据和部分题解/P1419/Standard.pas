program xx;
var a,b:array[1..1000] of string;
    i,j,k,l,m,n,p,q,t:longint;
    ch:char;
procedure init;
begin
 readln(n);
 k:=1;
 repeat
  read(ch);
  while (ch<>' ') and (ch<>'!') do
   begin
    a[k]:=a[k]+ch;
    read(ch);
   end;
  inc(k);
 until ch='!';
 readln;
 for i:=1 to n do
  readln(b[i]);
end;
function compared(x,y:string):boolean;
var v:longint;
begin
 t:=0;
 for v:=1 to length(x) do
  if x[v]<>y[v] then inc(t);
 if t<=1 then exit(true);
 exit(false);
end;
begin
 init;
 dec(k);
 a[1][1]:=lowercase(a[1][1]);
 for i:=1 to k do
   for j:=1 to n do
    if compared(a[i],b[j]) then
     begin
      a[i]:=b[j];
      if t=1 then inc(m);
      break;
     end;
 writeln(m);
 a[1][1]:=upcase(a[1][1]);
 for i:=1 to k-1 do
  write(a[i],' ');
 writeln(a[k],'!');
end.




