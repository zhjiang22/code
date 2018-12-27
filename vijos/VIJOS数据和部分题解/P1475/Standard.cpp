var
  map:array[0..1010,0..2010]of char;
  f:array[0..2100]of boolean;
  ans:array[0..1100]of longint;
  n,m,limit,t:longint;

procedure init;
  var
    i,j:longint;
  begin

    readln(n,m,limit);
    for i:=1 to n do
      begin
        for j:=1 to m+m do
          read(map[i,j]);
        readln;
      end;
  end;

procedure out_data;
  var
    i:longint;
  begin

    for i:=1 to m do
      writeln(ans[i]);
    
  end;

function check(r:longint):boolean;
  var
    i,j,used,now,cover:longint;
  begin
    cover:=r+1;
    used:=1;
    now:=0;
    check:=false;
    for i:=2 to n+n-r do
      begin
        if i>cover+1 then
          if now=0 then
            exit
          else
            begin
              cover:=now;
              now:=0;
              inc(used);
              if (used>limit)or(i>cover+1) then
                exit;
            end;
        if (f[i+r]) then
          now:=i+r+r;
        if (f[i])and(i+r>now) then now:=i+r;
      end;
    if cover<n+n-r then
      if (now<n+n-r)or(used+1>limit) then
        exit;
    check:=true;
  end;

function find:longint;
  var
    l,r,k:longint;
  begin
    find:=-1;
    l:=0;
    r:=n shr 1;
    repeat
      k:=(l+r)shr 1;
      if check(k) then
        begin
          find:=k;
          r:=k-1;
        end
      else
        l:=k+1;
    until l>r;
  end;

procedure push(c:char);
  begin
    inc(t);
    f[t]:=c='1';
  end;

procedure main;
  var
    i,j:longint;
  begin
    for i:=1 to m do
      begin
        t:=0;
        for j:=(n+1) shr 1 to n do push(map[j,i]);
        for j:=n downto 1 do push(map[j,i+m]);
        for j:=1 to n shr 1 do push(map[j,i]);
        ans[i]:=find;
      end;
  end;

begin
  init;
  main;
  out_data;
end.
