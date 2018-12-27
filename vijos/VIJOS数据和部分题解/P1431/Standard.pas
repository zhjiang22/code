var
f:array[0..250000,0..30]of longint;
g:array[0..250000,0..30]of boolean;
i,j,m,s,t,x,max,min:longint;

begin
readln(m,s,t);
fillchar(f,sizeof(f),0);
fillchar(g,sizeof(g),false);
i:=0; x:=0; max:=0; min:=maxlongint;
if m>=10 then
 begin
 while (m>=10)and(i<t) do
  begin
  inc(i);
  m:=m-10;
  x:=x+60;
  if x>s then begin
              writeln('Yes');
              writeln(i);
              halt;
              end;
  max:=x;
  end;
 f[i,m]:=x; f[i-1,m+10]:=x-60;
 g[i,m]:=true; g[i-1,m+10]:=true
 end
else g[0,m]:=true;
for i:=1 to t do
for j:=0 to 20 do
 begin
 if g[i-1,j+10] then
 if f[i,j]<f[i-1,j+10]+60 then begin
                               f[i,j]:=f[i-1,j+10]+60;
                               g[i,j]:=true;
                               end;

 if g[i-1,j] then
 if (f[i,j]<f[i-1,j]+17) then begin
                              f[i,j]:=f[i-1,j]+17;
                              g[i,j]:=true;
                              end;

 if (j>=4)and(g[i-1,j-4]) then
 if f[i,j]<f[i-1,j-4] then begin
                           f[i,j]:=f[i-1,j-4];
                           g[i,j]:=true;
                           end;

 if (f[i,j]>=s)and(i<min) then min:=i;
 if f[i,j]>max then max:=f[i,j];
 end;
if min=maxlongint then begin
                       writeln('No');
                       writeln(max)
                       end
                  else begin
                       writeln('Yes');
                       writeln(min);
                       end;
end.