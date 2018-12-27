const cai:array[0..9]of integer=(6,2,5,5,4,5,6,3,7,6);
Var i,j,k,l,n,m:longint;
function zhuan(a:integer):integer;
Begin
if a<=9 Then zhuan:=cai[a] else
if a<=99 Then zhuan:=cai[a div 10]+cai[a mod 10] else
zhuan:=cai[a div 100]+cai[a div 10 mod 10]+cai[a mod 10];
End;
Begin
readln(n);
For i:=0 to 777 do
For j:=0 to 777 do
if zhuan(i)+zhuan(j)+zhuan(i+j)+4=n Then inc(m);
writeln(m);
End.


