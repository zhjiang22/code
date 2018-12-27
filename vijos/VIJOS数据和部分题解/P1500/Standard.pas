type sstype=record ss:string;dd:array[1..255]of integer;End;
Var a:array[1..1000]of sstype;
h:sstype;
i,j,n,m:longint;
b:array['a'..'z']of integer;
c:char;
huan:boolean;
p:integer;
procedure before(a,b:sstype;k:longint);
Begin
huan:=false;
if a.dd[k]=b.dd[k] Then before(a,b,k+1);
if a.dd[k]>b.dd[k] Then huan:=true;
End;
Begin
For i:=1 to 26 do Begin
read(c);
b[c]:=i;
End;
readln(n);
For i:=1 to n do Begin
readln(a[i].ss);
For j:=1 to length(a[i].ss) do a[i].dd[j]:=b[a[i].ss[j]];
End;
readln(p);
For i:=1 to n-1 do
For j:=i+1 to n do Begin
before(a[i],a[j],1);
if (huan)and(p=1) Then Begin h:=a[i];a[i]:=a[j];a[j]:=h;End;
if not(huan)and(p=0) Then Begin h:=a[i];a[i]:=a[j];a[j]:=h;End;
End;
For i:=1 to n do writeln(a[i].ss);
End.