program zjc_set;
type arr=array[0..500]of longint;
     arr2=array[0..10000]of longint;
var i,j,o,n,m,ls:longint; s:ansistring;
    k:arr;ans,kk:arr2;
    p,ss:array[0..4010]of arr;
procedure cheng(var c:arr;a:arr;b:longint);
var i:longint;
begin
   c:=a;
   for i:=1 to c[0] do
    c[i]:=c[i]*b;
   for i:=1 to c[0] do
   begin
    c[i+1]:=c[i+1]+c[i] div 1000000;
    c[i]:=c[i] mod 1000000;
   end;
   while c[c[0]+1]>0 do
   begin
    inc(c[0]);
    c[c[0]+1]:=c[c[0]] div 1000000;
    c[c[0]]:=c[c[0]] mod 1000000;
   end;
end;
procedure jia(var c:arr;b:longint);
var i:longint;
begin
   c[1]:=c[1]+b;
   for i:=1 to c[0] do
   begin
     c[i+1]:=c[i+1]+c[i] div 1000000;
     c[i]:=c[i] mod 1000000;
   end;
   while c[c[0]+1]>0 do
   begin
    inc(c[0]);
    c[c[0]+1]:=c[c[0]] div 1000000;
    c[c[0]]:=c[c[0]] mod 1000000;
   end;
end;
procedure jia2(var c:arr2;b:longint);
var i:longint;
begin
   c[1]:=c[1]+b;
   for i:=1 to c[0] do
   begin
     c[i+1]:=c[i+1]+c[i] div 1000;
     c[i]:=c[i] mod 1000;
   end;
   while c[c[0]+1]>0 do
   begin
    inc(c[0]);
    c[c[0]+1]:=c[c[0]] div 1000;
    c[c[0]]:=c[c[0]] mod 1000;
   end;
end;
function xiao(a,b:arr):boolean;
var i:longint;
begin
   if a[0]<b[0] then exit(true);
   if a[0]>b[0] then exit(false);
   for i:=a[0] downto 1 do
   if a[i]<b[i] then exit(true)
    else if a[i]>b[i] then exit(false);
   exit(false);
end;
procedure jian(var c:arr;a:arr);
var i:longint;
begin
   for i:=1 to c[0] do
   c[i]:=c[i]-a[i];
   for i:=1 to c[0] do
   begin
     if c[i]<0 then begin dec(c[i+1]);c[i]:=c[i]+1000000;end;
   end;
   while (c[c[0]]=0)and(c[0]>1) do dec(c[0]);
end;
procedure jiajia(var c:arr;a:arr);
var i:longint;
begin
   if a[0]>c[0] then c[0]:=a[0];
   for i:=1 to c[0] do
   c[i]:=c[i]+a[i];
   for i:=1 to c[0] do
   begin
     c[i+1]:=c[i+1]+c[i] div 1000000;
     c[i]:=c[i] mod 1000000;
   end;
   while c[c[0]+1]>0 do
   begin
    inc(c[0]);
    c[c[0]+1]:=c[c[0]] div 1000000;
    c[c[0]]:=c[c[0]] mod 1000000;
   end;
end;
procedure gjcheng(var c:arr2;a,b:arr2);
var i,j:longint;
begin
   fillchar(c,sizeof(c),0);
   for i:=1 to a[0] do
    for j:=1 to b[0] do
    c[i+j-1]:=c[i+j-1]+a[i]*b[j];
   c[0]:=a[0]+b[0]-1;
   for i:=1 to c[0] do
   begin
    c[i+1]:=c[i+1]+c[i] div 1000;
    c[i]:=c[i] mod 1000;
   end;
   while c[c[0]+1]>0 do
   begin
    inc(c[0]);
    c[c[0]+1]:=c[c[0]] div 1000;
    c[c[0]]:=c[c[0]] mod 1000;
   end;
end;
begin
   assign(input,'set.in');reset(input);
   assign(output,'set.out');rewrite(output);
   readln(n,s);
   if n<3 then begin writeln(-1);close(input);close(output);halt;end;
   if n=3 then
   begin
     val(s,m);
     n:=m mod 3;
     if n=0 then begin n:=3;m:=m div 3;end
     else m:=m div 3+1;
     kk[1]:=2;kk[0]:=1;
     ans[1]:=1;ans[0]:=1;
     while m>0 do
     begin
       if odd(m) then gjcheng(ans,ans,kk);
       gjcheng(kk,kk,kk);
       m:=m div 2;
     end;
     jia2(ans,n-2);
     for i:=ans[0] downto 1 do
     begin
      if i=ans[0] then
       write(ans[i]) else
      begin
       str(ans[i],s);
       o:=3-length(s);
       for o:=o downto 1 do write(0);
       write(ans[i]);
      end;
     end;
     writeln;
     close(input);close(output);halt;
   end;
   while s[1]=' ' do delete(s,1,1);
   ls:=length(s); o:=0;
   while length(s)>6 do
   begin
      inc(k[0]);
      val(copy(s,length(s)-5,6),k[k[0]]);
      delete(s,length(s)-5,6);
   end;
   inc(k[0]);
   val(s,k[k[0]]);
   p[0,0]:=1;p[0,1]:=1;
   for i:=1 to 1000000 do
   begin
     cheng(p[i],p[i-1],2);
     if xiao(k,p[i]) then break;
   end;
   o:=i;
   for i:=1 to o do p[i,1]:=p[i,1]-1;
   for i:=1 to o do
    cheng(ss[i],p[i],n-3);
   for i:=1 to o do
    jia(ss[i],3*i);
   for i:=o downto 1 do
   if xiao(ss[i],k) then break;
   jia(ss[i],1);
   jian(k,ss[i]);
   jiajia(k,p[i+1]);
   for i:=k[0] downto 1 do
   begin
    if i=k[0] then
     write(k[i]) else
    begin
     str(k[i],s);
     o:=6-length(s);
     for o:=o downto 1 do write(0);
     write(k[i]);
    end;
   end;
   writeln;
   close(input);close(output);
end.
