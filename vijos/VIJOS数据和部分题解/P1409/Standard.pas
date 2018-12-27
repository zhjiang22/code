Var  f:array[1..200] of longint;
 i,ans,m,n,w,max,min:longint;
begin
 readln(w); readln(n);
 max:=0;min:=maxlongint;
 for i:=1 to n do
  begin
   readln(m); inc(f[m]);
   if max<m then max:=m;
   if min>m then min:=m;
  end;
 while max>=min do
  begin
   if min+max>w then
    begin
     dec(f[max]);inc(ans);
    end
   else
    begin
     dec(f[max]);
     if f[min]>0 then dec(f[min]);
     inc(ans);
    end;
   while (f[max]=0)and(max>1) do dec(max);
   while (f[min]=0)and(min<200) do inc(min);
  end;
 writeln(ans);
end.
