program xx;
const st='123456789ABCDEFGHIJ';
var s:string;
    i,j,n,k,m,d:longint;
begin
 while not eof do
  begin
   readln(n,k);
   s:='';
   write(n,'=');
   while n<>0 do
    begin
      m:=n mod k;
      n:=n div k;
      if m<0 then
       begin
        m:=m-k;
        inc(n);
       end;
      if m<>0 then
       s:=s+st[m]
       else s:=s+'0';
    end;
   for i:=length(s) downto 1 do
    write(s[i]);
   writeln('(base ',k,')');
  end;
end.