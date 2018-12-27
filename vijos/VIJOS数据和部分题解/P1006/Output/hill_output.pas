program hill;

var
    a:array[1..500,1..500] of integer;
    b:array[1..500,1..500] of longint;
    n:longint;

procedure init;
  var
      i,j:integer;

  begin
      readln(n);
      for i:=1 to n do
        begin
          for j:=1 to i do
            read(a[i,j]);
          readln;
        end;
  end;

procedure check;
  var
      i,j,k:integer;
  begin
      for i:=2 to n do
        b[n,i]:=10000000;
      b[n,1]:=a[n,1];
      for i:=n downto 2 do
        begin
          for k:=1 to 2 do
            begin
              for j:=1 to i do
                if b[i,j]>b[i,(j+i-2) mod i+1]+a[i,j] then  b[i,j]:=b[i,(j+i-2) mod i+1]+a[i,j];
              for j:=i downto 1 do
                if b[i,j]>b[i,j mod i+1]+a[i,j] then  b[i,j]:=b[i,j mod i+1]+a[i,j];
            end;


          for j:=1 to i-1 do
            if b[i,j]<b[i,j mod i+1] then
              b[i-1,j]:=b[i,j]+a[i-1,j]
            else
              b[i-1,j]:=b[i,j mod i+1]+a[i-1,j];
          if b[i-1,1]>b[i,i]+a[i-1,1] then  b[i-1,1]:=b[i,i]+a[i-1,1];
          if b[i-1,i-1]>b[i,1]+a[i-1,i-1] then  b[i-1,i-1]:=b[i,1]+a[i-1,i-1];
        end;
      writeln(b[1,1]);
  end;

begin
    assign(input,'hill9.in');  reset(input);
    assign(output,'hill9.out');  rewrite(output);

    init;
    check;

    close(input);  close(output);
end.
