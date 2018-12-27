const
     maxn=100;
     maxh=20;
var
     n,m,h,i,j,k,l,x,y,ans:longint;
     a:array[0..maxn]of longint;
     g,f:array[0..1,0..maxh,1..maxn,1..maxn]of longint;
     function max(x,y:longint):longint;
     begin
         if x>y then exit(x) else exit(y);
     end;
begin
     read(n,m,h);
     k:=0;
     for i:=1 to n do
     begin
        k:=1-k;
        for j:=1 to m do
        begin
            read(a[j]);
            inc(a[j],a[j-1]);
        end;
        for j:=1 to h do
        begin
        	if i<j then break;
            for l:=j+j-1 to m do
              for x:=1 to m+1-l do
              begin
              	 y:=x+l-1;
                 if l>=3 then g[k,j,x,y]:=max( f[k,j,x+1,y-1] , max(g[k,j,x,y-1],g[k,j,x+1,y]) );
                 if (a[y]-a[x-1]=0)and( (j=1)or(g[1-k,j-1,x,y]>0) ) then begin
                      f[k,j,x,y]:=max( f[1-k,j,x,y] , g[1-k,j-1,x,y] )+l;
                      if j=h then ans:=max( ans , f[k,j,x,y] );
                 end else f[k,j,x,y]:=0;
              end;
              
        end;
     end;
     writeln(ans);
end.
