program n_packback;
var
  a,v:array[1..200]of longint;
  b:array[1..200,1..10]of longint;
  f:array[0..5000000]of longint;
  s,c:array[0..10]of longint;
  i,j,k,m,n,l,r,ans:longint;
  xx:boolean;
begin
  readln(n,m);
  for i:=1 to m do begin
    read(c[i]);
    s[i]:=s[i-1]+trunc(ln(c[i])/ln(2))+1;
    k:=k+c[i] shl s[i-1];
  end;
  for i:=1 to n do begin
    read(a[i]);
    for j:=1 to m do begin
      read(b[i,j]);
      v[i]:=v[i]+b[i,j] shl s[j-1];
    end;
    readln;
  end;
  for i:=1 to n do
    for j:=k-v[i] downto 0 do begin
      if f[j+v[i]]>=f[j]+a[i] then continue;
      xx:=true;
      for l:=1 to m do
        if b[i,l]+(j-((j shr s[l])shl s[l]))shr s[l-1]>c[l] then begin
          xx:=false;
          break;
        end;
      if xx then
        f[j+v[i]]:=f[j]+a[i];
    end;
  writeln(f[k]);
end.
