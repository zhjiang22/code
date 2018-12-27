type
  xx=record
    d,t,v:integer;
    nu:longint;
  end;
var
  b:array[1..10000]of boolean;
  a:array[1..100]of integer;
  w:array[1..100,1..100]of xx;
  i,j,k,m,n,t,v,h,l:longint;
  ans,sum:longint;
procedure find(h,tt,vv:longint);
var
  i,j:integer;
begin
  if h=n then begin
    if (vv>ans)or((vv=ans)and(tt<sum)) then begin
      ans:=vv;
      sum:=tt;
    end;
    exit;
  end;
  for i:=1 to a[h] do
    if not b[w[h,i].nu] then
      if (tt+w[h,i].t<=t)and(vv+w[h,i].v<=v) then begin
        b[w[h,i].nu]:=true;
        find(w[h,i].d,tt+w[h,i].t,vv+w[h,i].v);
        b[w[h,i].nu]:=false;
      end;
end;
begin
  readln(n,m,t,v);
  for i:=1 to m do begin
    readln(j,k,h,l);
    inc(a[j]);
    inc(a[k]);
    w[j,a[j]].d:=k;
    w[j,a[j]].t:=h;
    w[j,a[j]].v:=l;
    w[j,a[j]].nu:=i;
    w[k,a[k]].d:=j;
    w[k,a[k]].t:=h;
    w[k,a[k]].v:=l;
    w[k,a[k]].nu:=i;
  end;
  fillchar(b,sizeof(b),0);
  sum:=10000;
  find(1,0,0);
  writeln(sum,' ',v-ans);
end.
