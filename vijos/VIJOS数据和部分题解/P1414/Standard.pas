program xx;
var n:string;
    s,i,j,k,l,m:longint;
begin
  readln(n);
  readln(s);
  while s>0 do
   begin
    i:=1;
    while (i<length(n)) and (n[i]<=n[i+1]) do i:=i+1;
    delete(n,i,1);
    s:=s-1;
   end;
  while (length(n)>1) and (n[1]='0') do delete(n,1,1);
  writeln(n);
end.