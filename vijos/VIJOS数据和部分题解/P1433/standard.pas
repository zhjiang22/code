program rqnojbx10_3;
var a,b,c,d:integer;
begin
  readln(a,b,c,d);
  b:=trunc(sqrt(b));
  d:=trunc(sqrt(d));
  writeln(sqrt(sqr(c-a)+sqr(d+b)):0:3);
end.