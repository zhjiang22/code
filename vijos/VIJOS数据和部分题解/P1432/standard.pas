program sxjzm;
const eighteen:int64=181818181818;
var k,o,p:int64;
    i,n,m:longint;
    f:array[1..100000]of int64;
begin
  readln(n,m);
  case n of
    1:writeln(0);
    2:if m=1 then writeln(1)else writeln(-18);
    else
    begin
      n:=n-3;
      f[0]:=0;
      k:=1;
      o:=1;
      p:=o;
      for i:=1 to m do
      begin
        f[i]:=(f[i-1]+k)mod eighteen;
        dec(p);
        if p=0 then
        begin
          k:=(k*2)mod eighteen;
          o:=o+n;
          p:=o;
        end;
      end;
      writeln(f[m]mod eighteen);
    end;
  end;
end.
