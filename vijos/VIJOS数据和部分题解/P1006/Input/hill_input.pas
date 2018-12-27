program hill_input;

var
    i,j,n:integer;

procedure check;
  var
      i,j:integer;

  begin
      randomize;
      n:=300;
      writeln(n);
      for i:=1 to n do
        begin
          write(random(10)+1);
          for j:=2 to i do
            write(' ',random(10)+1);
          writeln;
        end;
  end;

begin
    assign(output,'hill0.in');
    rewrite(output);

    check;

    close(output);
end.
