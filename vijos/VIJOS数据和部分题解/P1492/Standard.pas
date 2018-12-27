const
  inf='str.in';
  ouf='str.out';
var
  total:qword;
  n:integer;
  str2:string;

  procedure count60;
  var
    d:integer;
  begin
    for d:=2 to 60 do
    begin
      if d mod 2=0 then
        total:=total*2
      else total:=total*2+1;
      if d=n then exit;
    end;
  end;

  procedure countbigger;
  var
    str1,str3:string;
    a:array[1..250]of integer;
    i,j,k,l,s,o:integer;
  begin
    o:=0;
    str(total,str1);
    fillchar(a,sizeof(a),0);
    for i:=length(str1) downto 1 do
      val(str1[i],a[length(str1)-i+1]);
    for j:=61 to n do
      begin
        for k:=1 to length(str1)+o do
          a[k]:=a[k]*2;
        for l:=1 to length(str1)+o do
            if a[l]>=10 then
            begin
              a[l+1]:=a[l+1]+1;
              a[l]:=a[l] mod 10;
            end;
        if j mod 2<>0 then a[1]:=a[1]+1;
        if a[length(str1)+o+1]<>0 then inc(o);
      end;
    for s:=1 to length(str1)+o do
      begin
        str(a[s],str3);
        str2:=str3+str2;
      end;
  end;

  begin
    assign(input,inf);
    reset(input);
    assign(output,ouf);
    rewrite(output);
    readln(n);
    total:=1;
    count60;
    if n>60 then countbigger;
    if n<=60 then writeln(total)
    else
      begin
        writeln(str2);
      end;
    close(input);
    close(output);
    end.
