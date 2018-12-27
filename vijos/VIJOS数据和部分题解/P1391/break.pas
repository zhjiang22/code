program PrisonBreak_lolanvsFantasy;
  //by lolanv
const maxln=2000;
var
  l,a:array[0..maxln] of longint;
  ud:array[1..maxln] of boolean;
  w:array[1..maxln,1..maxln] of longint;
  i,j,n,t,f,s:longint;
function take:longint;
begin
  if f=s then exit(0);
  f:=(f+1) mod n;
  take:=l[f];
  ud[take]:=false
end;
procedure ins(a:longint);
begin s:=(s+1) mod n; l[s]:=a; ud[a]:=true end;
function min(a,b:longint):longint;
begin if a>b then exit(b) else exit(a) end;
begin
  fillchar(w,sizeof(w),0); fillchar(ud,sizeof(ud),0); fillchar(a,sizeof(a),0);
  read(n); readln(i,j,t);
  repeat w[i,j]:=t;readln(i,j,t); until i=0;
  a[1]:=maxlongint; f:=0; s:=0; i:=1;
  repeat
    for j:=2 to n do
    if i<>j then
      begin
        t:=min(a[i],w[i,j]);
        if t>a[j] then
          begin
            a[j]:=t;
            if not ud[j] then ins(j)
          end
      end;
    i:=take;
  until i=0;
  for i:=2 to n do writeln(a[i]);
end.