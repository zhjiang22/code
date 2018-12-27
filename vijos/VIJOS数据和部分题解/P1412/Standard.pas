  var
    i,j,k,m,n,t,a,b,v,p,sum:longint;
    w,c:array[0..256] of longint;
    up:array[0..64] of longint;
    fn:array[0..5001] of longint;
    f:array[0..5001,0..64] of longint;
  begin
    read(k,v,n);
    for i:=0 to n-1 do
      read(w[i],c[i]);
    fn[0]:=1;
    for i:=0 to n-1 do
      for j:=v-w[i] downto 0 do
        begin
          if fn[j]=0 then continue;
          t:=j+w[i];m:=0;a:=0;b:=0;
          while m<k do
            begin
              if (a<fn[j])and(f[j,a]+c[i]>f[t,b]) then
                begin
                  up[m]:=f[j,a]+c[i];
                  inc(m);inc(a);
                end
                else begin
                       if b<fn[t] then
                         begin
                           up[m]:=f[t,b];
                           inc(m);inc(b);
                         end
                         else break;
                     end;
            end;
          fn[t]:=m;
          for p:=0 to m-1 do
            f[t,p]:=up[p];
        end;
    for i:=0 to k-1 do
      begin
        sum:=sum+f[v,i]
      end;
    writeln(sum);
  end.