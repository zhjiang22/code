const
 big=100000;
var
 a:array[1..500,1..500]of longint;
 b:array[1..500,1..500]of boolean;
 pre,gap,d,now,que:array[0..500]of longint;
 i,j,k,n,m,tot:longint;
 c:char;
procedure sap;
 var
  x,y,i,j,k,r:longint;
  flag:boolean;
 begin
  fillchar(gap,sizeof(gap),0);
  fillchar(d,sizeof(d),3);
  x:=1;y:=1;que[1]:=tot;
  d[tot]:=0;gap[0]:=1;now[tot]:=1;
  repeat
   j:=que[x];
   for i:=1 to tot do
    if(a[i,j]>0)and(d[i]>10000)then
     begin
      d[i]:=d[j]+1;  inc(gap[d[i]]);
      inc(y);        que[y]:=i;
      now[i]:=1;
     end;
   inc(x);
  until x>y;
  r:=tot-1;
  while d[tot-1]<tot do
   begin
    flag:=false;
    for i:=now[r] to tot do
     if(a[r,i]>0)and(d[r]=d[i]+1)then
      begin
       pre[i]:=r; flag:=true;
       now[r]:=i; r:=i;
       if r=tot then
        begin
         y:=tot; k:=maxlongint;
         while y<>tot-1 do
          begin
           x:=pre[y];
           if a[x,y]<k then k:=a[x,y];
           y:=x;
          end;
         y:=tot;
         while y<>tot-1 do
          begin
           x:=pre[y];
           dec(a[x,y],k);  inc(a[y,x],k);
           y:=x;
          end;
         r:=tot-1;
        end;
       break;
      end;
    if flag then continue;
    
    dec(gap[d[r]]); if gap[d[r]]=0 then break;
    k:=tot-1; y:=tot;
    for i:=1 to tot do
     if(a[r,i]>0)and(d[i]<k)then
      begin k:=d[i];y:=i; end;
    now[r]:=y; d[r]:=k+1;
    inc(gap[d[r]]);
    if r<>tot-1 then r:=pre[r];
   end;
 end;
function can(x:longint):boolean;
 var
  i,j:longint;
 begin
  can:=true;
  if x=0 then exit;
  fillchar(a,sizeof(a),0);
  
  for i:=1 to n do
   begin
     a[tot-3,i]:=big-x;
     a[i,i+n<<1]:=m;
     for j:=1 to n do
      if b[i,j] then  a[i,j+n+n+n]:=1
                else  a[i+n<<1,j+n]:=1;
   end;

  for j:=1+n to n+n do
   begin
     a[j,j+n<<1]:=m;
     a[j+n<<1,tot-2]:=big-x;
   end;

  a[tot-3,tot-2]:=big; a[tot-2,tot-3]:=big;
  for i:=1 to n do
     a[tot-1,i]:=x;
  for j:=n+n+n+1 to tot-4 do
     a[j,tot]:=x;
  a[tot-1,tot-2]:=n*x;
  a[tot-3,tot]:=n*x;
  
  sap;
  for i:=1 to tot do
   if a[tot-1,i]<>0 then exit(false);
        
 end;
begin
 fillchar(b,sizeof(b),0);
 readln(n,m); tot:=n<<2+4;
 for i:=1 to n do
  begin
   for j:=1 to n do
    begin
     read(c);
     if c='Y' then b[i,j]:=true;
    end;
   readln;
  end;
 i:=0;j:=n+1;
 while i<j do
  begin
   k:=(i+j)>>1;
   if can(k) then i:=k+1 else j:=k;
  end;
 writeln(i-1);
end.