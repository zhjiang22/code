Var a,b:array[0..31,0..31]of longint;
c:array[0..31,0..31]of boolean;
bi:array[1..4]of record no1,no2,ini:longint;End;
pan1,pan2,p1,p2,q1,q2,o,i,j,n,m,p,q,k1,k2,l1,l2:longint;
l,k:qword;
lp:boolean;
procedure big(a1,a2:longint);
Var i,l:longint;
Begin
bi[1].ini:=a[a1-1,a2];
bi[1].no1:=a1-1;
bi[1].no2:=a2;
bi[2].ini:=a[a1,a2+1];
bi[2].no1:=a1;
bi[2].no2:=a2+1;
bi[3].ini:=a[a1+1,a2];
bi[3].no1:=a1+1;
bi[3].no2:=a2;
bi[4].ini:=a[a1,a2-1];
bi[4].no1:=a1;
bi[4].no2:=a2-1;
l:=maxlongint;
For i:=1 to 4 do
if (bi[i].ini>0)and(not(c[bi[i].no1,bi[i].no2]))and(bi[i].ini<l) Then Begin l:=bi[i].ini;p1:=bi[i].no1;p2:=bi[i].no2;End;
End;
Begin
readln(k1,k2);
For i:=1 to k1 do
For j:=1 to k2 do Begin
read(a[i,j]);
if a[i,j]=0 Then Begin p1:=i;p2:=j;End;
End;
readln(l1,l2);
For i:=l1 downto 1 do
For j:=1 to l2 do Begin
read(b[i,j]);
if b[i,j]=0 Then Begin q1:=i;q2:=j;End;
End;
readln(o);
For i:=1 to q1-1 do
For j:=1 to l2 do inc(l,b[i,j]);
if o=0 Then Begin if q1 mod 2=0 Then For i:=l2 downto q2 do inc(l,b[q1,i])
                                Else For i:=1 to q2 do inc(l,b[q1,i]);
                                End
       else Begin if q1 mod 2=0 Then For i:=1 to q2 do inc(l,b[q1,i])
                                Else For i:=l2 downto q2 do inc(l,b[q1,i])
                                End;
while k<=l do Begin
inc(n);
pan1:=p1;pan2:=p2;
c[p1,p2]:=true;
inc(k,a[p1,p2]);
big(p1,p2);
if n>=k1*k2 Then break;
if (pan1=p1)and(pan2=p2) Then Begin lp:=true;break;End;
End;
if not(lp) Then writeln(n) else writeln('Error!');
writeln(p1,',',p2);
End.
