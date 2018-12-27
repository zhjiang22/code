const
  maxm=1000;

var
  n,m,k,i,j,d:longint;
  a:array [0..maxm+1,1..2] of extended;
  t:extended;

begin
  read(n,k,m);
  for i:=1 to m do read(a[i,1],a[i,2]);
  for i:=1 to m-1 do
    for j:=m downto i+1 do
      if a[j-1,1]>a[j,1] then begin
        a[0,1]:=a[j-1,1]; a[0,2]:=a[j-1,2];
        a[j-1,1]:=a[j,1]; a[j-1,2]:=a[j,2];
        a[j,1]:=a[0,1]; a[j,2]:=a[0,2];
      end;
  a[m+1,1]:=maxlongint*maxlongint;
  d:=1;
  t:=0;
  i:=1;
  repeat
    while a[i,1]+a[i,2]<=t do inc(i);
    if a[i,1]>=t+1 then begin
      if d<k then d:=d+d else d:=d+k;
      t:=t+1;
    end else begin
      t:=a[i,1]+a[i,2];
      inc(i);
    end;
  until d>=n;
  writeln(t:0:2);
end.
