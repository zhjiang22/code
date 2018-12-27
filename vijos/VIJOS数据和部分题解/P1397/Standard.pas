program brute_force ;
 const
  maxN = 1000000 ;
 var
  n , m , total , top : longint ;
  s5 , s4 , s3 , s2 , s1 , s0 : longint ;
  a3 , a2 , a1 , b3 , b2 , b1 : longint ;
  i , j , x , y , head , tail : longint ;
  stack : array [ 1..maxN ] of record x , s , t : longint ; end ;
  queue : array [ 1..maxN ] of longint ;
  l , r : array [ 1..maxN ] of longint ;
  start , finish : array [ 1..maxN ] of longint ;
 function fs ( x : longint ) : longint ;
  var
   s : longint ;
  begin
   s := 0 ;
   x := x mod s0 ;
   s := ( ( s + s5 ) * x ) mod s0 ;
   s := ( ( s + s4 ) * x ) mod s0 ;
   s := ( ( s + s3 ) * x ) mod s0 ;
   s := ( ( s + s2 ) * x ) mod s0 ;
   s := ( ( s + s1 ) ) mod s0 ;
   exit ( s ) ;
  end ;
 function fx ( x : longint ) : longint ;
  var
   s : longint ;
  begin
   s := 0 ;
   x := x mod n ;
   s := ( ( s + a3 ) * x ) mod n ;
   s := ( ( s + a2 ) * x ) mod n ;
   s := ( ( s + a1 ) ) mod n ;
   exit ( s + 1 ) ;
  end ;
 function fy ( x : longint ) : longint ;
  var
   s : longint ;
  begin
   s := 0 ;
   x := x mod n ;
   s := ( ( s + b3 ) * x ) mod n ;
   s := ( ( s + b2 ) * x ) mod n ;
   s := ( ( s + b1 ) ) mod n ;
   exit ( s + 1 ) ;
  end ;
 procedure dfs ( x : longint ) ;
  var
   i : longint ;
  begin
   if x > n then
    exit ;
   inc ( total ) ;
   l[x] := total ;
   for i := start[x] to finish[x] do
    dfs ( i ) ;
   inc ( total ) ;
   r[x] := total ;
  end ;
 begin
  readln ( n , m ) ;
  readln ( s5 , s4 , s3 , s2 , s1 , s0 ) ;
  readln ( a3 , a2 , a1 , b3 , b2 , b1 ) ;
  head := 0 ;
  tail := 1 ;
  total := 1 ;
  queue[1] := 1 ;
  while head <> tail do
   begin
    inc ( head ) ;
    j := fs ( queue[head] ) ;
    if total + j <= n then
     finish[queue[head]] := total + j
     else
      finish[queue[head]] := n ;
    start[queue[head]]  := total + 1 ;
    for i := start[queue[head]] to finish[queue[head]] do
     begin
      inc ( tail ) ;
      queue[tail] := i ;
     end ;
    total := finish[queue[head]] ;
   end ;
  top := 1 ;
  total := 0 ;
  stack[1].x := 1 ;
  while top > 0 do
   begin
    if stack[top].s = 0 then
     begin
      inc ( total ) ;
      stack[top].s := start[stack[top].x] ;
      stack[top].t := finish[stack[top].x] ;
      l[stack[top].x] := total ;
     end ;
    if stack[top].s <= stack[top].t then
     begin
      stack[top+1].x := stack[top].s ;
      stack[top+1].s := 0 ;
      inc ( stack[top].s ) ;
      inc ( top ) ;
     end
     else
      begin
       inc ( total ) ;
       r[stack[top].x] := total ;
       dec ( top ) ;
      end ;
   end ;
  for i := 1 to m do
   begin
    x := fx ( i ) ;
    y := fy ( i ) ;
    if ( l[x] <= l[y] ) and ( r[y] <= r[x] ) then
     writeln ( 'Yes' )
     else
      writeln ( 'No' ) ;
   end ;
 end .