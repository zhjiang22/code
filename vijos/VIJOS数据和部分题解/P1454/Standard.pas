program rprp;
 var
  n,i,j,k,l,l0,m,max,rp:longint;
  s,st,cow:ansistring;
  ch:char;
 begin
  readln(n);
  l:=maxlongint; max:=0;
  for i:=1 to n do
   begin
    readln(st);
    s:=st;
    m:=length(st);
    l0:=m;
    for j:=1 to m div 2 do
     begin
      ch:=st[j];
      st[j]:=st[m-j+1];
      st[m-j+1]:=ch;
     end;
    k:=pos('jszxoier',st);
    if k>0 then
     begin
      k:=1; rp:=0;
      while k>0 do
       begin
        k:=pos('cow',st);
        if k=0 then continue;
        delete(st,k,3);
        rp:=rp+5;
        dec(m,3);
       end;
      for j:=1 to m do
       begin
        if st[j]='r' then inc(rp,5);
        if st[j]='p' then inc(rp,5);
        if (j>1)and(st[j]='p')and(st[j-1]='r') then inc(rp,20);
       end;
      if (rp>max)or((rp=max)and(m<l))then
       begin
        cow:=s;
        l:=l0;
        max:=rp;
       end;
     end;
   end;
 writeln(cow);
 writeln(max);
end.