const
  maxx=1000;
  maxy=1000;
  ch1=chr(43);
  ch2=chr(45);
  ch3=chr(47);
  ch4=chr(124);
var
  m,n,h,i,j,k,a,b,maxh:longint;
  map:array [1..50,1..50,1..100] of boolean;
  s:array [1..maxx,1..maxy] of char;
procedure draw(x,y:longint);
  var
    i:longint;
  begin
    s[x,y]:=ch1;
    for i:=1 to 3 do s[x,y+i]:=ch2;
    s[x,y+4]:=ch1;
    s[x+1,y]:=ch4;
    for i:=1 to 3 do s[x+1,y+i]:=' ';
    s[x+1,y+4]:=ch4;
    s[x+1,y+5]:=ch3;
    s[x+2,y]:=ch4;
    for i:=1 to 3 do s[x+2,y+i]:=' ';
    s[x+2,y+4]:=ch4;
    s[x+2,y+5]:=' ';
    s[x+2,y+6]:=ch1;
    s[x+3,y]:=ch1;
    for i:=1 to 3 do s[x+3,y+i]:=ch2;
    s[x+3,y+4]:=ch1;
    s[x+3,y+5]:=' ';
    s[x+3,y+6]:=ch4;
    s[x+4,y+1]:=ch3;
    for i:=2 to 4 do s[x+4,y+i]:=' ';
    s[x+4,y+5]:=ch3;
    s[x+4,y+6]:=ch4;
    s[x+5,y+2]:=ch1;
    for i:=3 to 5 do s[x+5,y+i]:=ch2;
    s[x+5,y+6]:=ch1;
    if x+5>a then a:=x+5;
    if y+6>b then b:=y+6;
  end;
begin
  a:=0;
  b:=0;
  maxh:=0;
  fillchar(map,sizeof(map),false);
  fillchar(s,sizeof(s),chr(46));
  for i:=1 to m do
    begin
      for j:=1 to n do
        begin
          read(h);
          for k:=1 to h do map[i,j,k]:=true;
          if h>maxh then maxh:=h;
        end;
      readln;
    end;
  for i:=1 to maxh do for j:=1 to m do for k:=1 to n do if map[j,k,i] then draw(i*3+(m-j)*2-2,k*4+(m-j)*2-3);
  for i:=a downto 1 do
    begin
      for j:=1 to b do write(s[i,j]);
      writeln;
    end;
end.
