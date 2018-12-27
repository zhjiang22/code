program xx;
var n,m,r:real;
    s:real;
begin
  readln(m,n,r);
  if m<n then
   begin
     writeln(r:0:3);
     exit;
   end;
  s:=sqrt(sqr(r)+sqr(n-m));
  writeln(s:0:3);
end.