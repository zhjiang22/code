 var m,n,k,v,i,j,ans:longint;
    a,sum:array[0..61,0..61]of longint;
    g:array[0..61,0..3610]of longint;
    f:array[0..61,0..61,0..3610]of longint;
function min(a,b:longint):longint;
begin if a<b then exit(a)else exit(b);end;
begin
  reset(input);rewrite(output);
  readln(m,n,v);sum[0,0]:=0;
  for i:=1 to n do
   begin
     sum[i,0]:=0;
     for j:=1 to m do
      begin
        read(a[i,j]);
        sum[i,j]:=sum[i,j-1]+a[i,j];
      end;
     readln;
   end;
  for i:=0 to n do
   for j:=0 to m do
    for k:=0 to v do f[i,j,k]:=2000000000;
  for j:=0 to m do f[1,j,j]:=sum[1,j];
  for k:=0 to v do
   begin
     g[m,k]:=f[1,m,k];
     for j:=m-1 downto 0 do g[j,k]:=min(f[1,j,k],g[j+1,k]);
   end;
  ans:=2000000000;
  if v<=m then ans:=f[1,v,v];
  for i:=2 to n do
   begin
     for j:=0 to m do
       begin
         for k:=j to v do
          if g[j,k-j]=2000000000 then f[i,j,k]:=g[j,k-j]
                               else f[i,j,k]:=g[j,k-j]+sum[i,j];
         ans:=min(ans,f[i,j,v]);
       end;
     fillchar(g,sizeof(g),0);
     for k:=0 to v do
       begin
         g[m,k]:=f[i,m,k];
         for j:=m-1 downto 0 do g[j,k]:=min(f[i,j,k],g[j+1,k]);
       end;
   end;
  writeln(ans);
  close(input);close(output);
end.