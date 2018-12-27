const maxl=1200;
      tlen=100000000;
type num=array[0..maxl]of longint;
var k,one,three,now,next,st,ans,m:num;
    n,i,t:longint;
    s:ansistring;
function max(a,b:longint):longint;
begin
  if a>b then max:=a else max:=b;
end;
function min(a,b:longint):longint;
begin
  if a<b then min:=a else min:=b;
end;
function compare(var a,b:num):longint;
var i:longint;
begin
  if a[0]=b[0] then
    for i:=a[0] downto 1 do
      if a[i]>b[i] then
      begin
        compare:=1;
        exit;
      end
      else if a[i]<b[i] then
      begin
        compare:=-1;
        exit;
      end;
  compare:=0;
  if a[0]>b[0] then compare:=1
  else if a[0]<b[0] then compare:=-1;
end;
function plus(var a,b:num):num;
var i,l:longint;
begin
  l:=max(a[0],b[0]);
  fillchar(plus,(l+2)shl 2,0);
  plus[l+1]:=0;
  for i:=1 to l do
  begin
    if a[0]>=i then plus[i]:=plus[i]+a[i];
    if b[0]>=i then plus[i]:=plus[i]+b[i];
    plus[i+1]:=plus[i] div tlen;
    plus[i]:=plus[i] mod tlen;
  end;
  if plus[l+1]>0 then plus[0]:=l+1 else plus[0]:=l;
end;
function minus(a:num;var b:num):num;
var i:longint;
begin
  fillchar(minus,(a[0]+2)shl 2,0);
  for i:=1 to a[0] do
  begin
    minus[i]:=a[i]-b[i];
    if minus[i]<0 then
    begin
      minus[i]:=minus[i]+tlen;
      dec(a[i+1]);
    end;
  end;
  for i:=a[0] downto 1 do
    if minus[i]>0 then
    begin
      minus[0]:=i;
      break;
    end;
end;
procedure getk;
var i,l,t:longint;
    ch:char;
begin
  read(ch);
  readln(s);
  l:=length(s);
  t:=trunc(ln(tlen)/ln(10));
  k[0]:=(l-1)div t+1;
  for i:=1 to l do
    val(copy(s,max(1,l-i*t+1),min(t,l-(i-1)*t)),k[i]);
end;
begin
  read(n);
  getk;
  fillchar(one,sizeof(one),0);
  one[0]:=1;
  one[1]:=1;
  three:=one;
  three[1]:=3;
  now:=one;
  now[1]:=0;
  m:=one;
  m[1]:=n;
  next:=m;
  st:=one;
  if n=2 then
  begin
    if compare(k,next)>0 then
      writeln(-1)
    else
      writeln(k[1]);
  end
  else
  begin
    while compare(next,k)<0 do
    begin
      now:=next;
      m:=plus(m,m);
      m:=minus(m,three);
      next:=plus(next,m);
      st:=plus(st,st);
      st:=plus(st,one);
    end;
    ans:=minus(k,now);
    ans:=plus(ans,st);
    ans:=minus(ans,one);
    for i:=ans[0] downto 1 do
    begin
      t:=tlen div 10;
      while (i<ans[0])and(ans[i]<t)and(t>1) do
      begin
        write('0');
        t:=t div 10;
      end;
      write(ans[i]);
    end;
    writeln;
  end;
end.
