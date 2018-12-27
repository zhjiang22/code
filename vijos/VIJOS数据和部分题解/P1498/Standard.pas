program pp;
  var
    i,j,k,m,n,d,l,tot,ans:longint;
    x1,y1,x2,y2:longint;
    a,b:array[0..5000,0..1] of longint;
    c,d1:array[0..2000] of longint;
  function min(x,y:longint):longint;
    begin
      if x<y then min:=x else min:=y;
    end;
  procedure quick1(x,y:longint);
    var
      i,j:longint;
      t:array[0..1] of longint;
    begin
      i:=x;j:=y;t:=a[i];
      repeat
        while (t[1]>=a[j,1])and(i<j) do dec(j);
        if i<j then a[i]:=a[j];
        while (t[1]<=a[i,1])and(i<j) do inc(i);
        if i<j then a[j]:=a[i];
      until i=j;
      a[i]:=t;
      if i<y then quick1(i+1,y);
      if j>x then quick1(x,j-1);
    end;
  procedure quick2(x,y:longint);
    var
      i,j:longint;
      t:array[0..1] of longint;
    begin
      i:=x;j:=y;t:=b[i];
      repeat
        while (t[1]>=b[j,1])and(i<j) do dec(j);
        if i<j then b[i]:=b[j];
        while (t[1]<=b[i,1])and(i<j) do inc(i);
        if i<j then b[j]:=b[i];
      until i=j;
      b[i]:=t;
      if i<y then quick2(i+1,y);
      if j>x then quick2(x,j-1);
    end;
  begin
    
    readln(m,n,k,l,d);
    for i:=1 to m do a[i,0]:=i;
    for i:=1 to n do b[i,0]:=i;
    for i:=1 to d do
      begin
        read(x1,y1,x2,y2);
        tot:=abs(x1-x2);
        if tot=0 then begin inc(b[min(y1,y2),1]);end
                 else begin inc(a[min(x1,x2),1]);end;
      end;
    quick1(1,m);
    quick2(1,n);
    for i:=1 to k do inc(c[a[i,0]]);
    for i:=1 to l do inc(d1[b[i,0]]);
    ans:=1;
    for i:=1 to m do if c[i]>=1 then begin if ans=1 then write(i) else write(' ',i);inc(ans);end;
    writeln;ans:=1;
    for i:=1 to n do if d1[i]>=1 then begin if ans=1 then write(i) else write(' ',i);inc(ans);end;
    writeln;
   
  end.
