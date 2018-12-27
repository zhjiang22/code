program project1;
  var c:array[1..1024,1..1024]of longint;
      n,check,x,y,x1,y1,k:longint;
  function lowbit(x:longint):longint;
    begin
      exit(x and -x);
    end;
  procedure modify(x,y1,k:longint);
    var y:longint;
    begin
      while x<=n do
        begin
          y:=y1;
          while y<=n do
            begin
              inc(c[x,y],k);
              inc(y,lowbit(y));
            end;
          inc(x,lowbit(x));
        end;
    end;
  function query(x,y1:longint):longint;
    var y:longint;
    begin
      query:=0;
      while x>0 do
        begin
          y:=y1;
          while y>0 do
            begin
              inc(query,c[x,y]);
              dec(y,lowbit(y));
            end;
          dec(x,lowbit(x));
        end;
    end;
  begin
    assign(input,'in.txt');
    assign(output,'out.txt');
    reset(input);
    rewrite(output);
    fillchar(c,sizeof(c),0);
    readln(n);
    read(check);
    while check<>3 do
      begin
        case check of
          1:begin
              readln(x,y,k);
              inc(x);
              inc(y);
              modify(x,y,k);
            end;
          2:begin
              readln(x,y,x1,y1);
              inc(x1);
              inc(y1);
              k:=query(x1,y1);
              dec(k,query(x,y1));
              dec(k,query(x1,y));
              inc(k,query(x,y));
              writeln(k);
            end;
        end;
        read(check);
      end;
    close(input);
    close(output);
  end.