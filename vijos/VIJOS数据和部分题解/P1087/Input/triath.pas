program triath;
  const maxn=10000;
        maxt=3*maxn;
        zero=1e-9;
        maxre=1e50;
  type re=extended;
       point=record
               x,y:re;
             end;
       line=record
              a,b,c:re;
            end;
       arr=array[1..maxt] of point;
  var n,tot,tt:longint;
      v,u,w:array[1..maxn] of re;
      pc:array[1..maxn] of longint;
      p,q:arr;
      l:line;
  procedure init;
    var i:longint;
    begin
      readln(n);
      for i:=1 to n do readln(v[i],u[i],w[i]);
    end;
  function compare(a,b:re):longint;
    begin
      if abs(a-b)<=zero then compare:=0 else
        if a>b then compare:=1 else compare:=-1;
    end;
  function poi2lin(a,b:point):line;
    var l:line;
    begin
      l.a:=a.x-b.x;
      l.b:=a.y-b.y;
      l.c:=a.x*b.y-a.y*b.x;
      poi2lin:=l;
    end;
  function compoi(a,b:point;l:line):point;
    var p:point;
        m:line;
    begin
      m:=poi2lin(a,b);
      p.x:=(l.a*m.c-m.a*l.c)/(m.a*l.b-l.a*m.b);
      p.y:=(l.c*m.b-m.c*l.b)/(l.a*m.b-m.a*l.b);
      compoi:=p;
    end;
  function last(i:longint):longint;
    begin
      if i=1 then last:=tot else last:=i-1;
    end;
  function next(i:longint):longint;
    begin
      if i=tot then next:=1 else next:=i+1;
    end;
  procedure cut(a,b,c:re);
    var i,j,orig:longint;
    begin
      if compare(a,0)=0 then
        if compare(b,0)=0 then begin
          if compare(c,0)<=0 then tot:=0;
          exit;
        end;
      tt:=0;
      l.a:=a;
      l.b:=b;
      l.c:=c;
      for i:=1 to tot do pc[i]:=compare(l.a*p[i].y,l.b*p[i].x+l.c);
      case tot of
        1:if pc[1]<=0 then begin
            inc(tt);
            q[tt]:=p[1];
          end;
        2:begin
            if pc[1]<=0 then begin
              inc(tt);
              q[tt]:=p[1];
            end else
              if pc[2]<0 then begin
                inc(tt);
                q[tt]:=compoi(p[2],p[1],l);
              end;
            if pc[2]<=0 then begin
              inc(tt);
              q[tt]:=p[2];
            end;
          end;
        else begin
          for i:=1 to tot do begin
            if pc[i]<=0 then begin
              inc(tt);
              q[tt]:=p[i];
            end else begin
              if pc[last(i)]<0 then begin
                inc(tt);
                q[tt]:=compoi(p[last(i)],p[i],l);
              end;
              if pc[next(i)]<0 then begin
                inc(tt);
                q[tt]:=compoi(p[i],p[next(i)],l);
              end;
            end;
          end;
        end;
      end;
      tot:=tt;
{      for i:=1 to tt do p[i]:=q[i];}
      move(q[1],p[1],sizeof(point)*tt);
    end;
  procedure main;
    var i,j:longint;
    begin
      for i:=1 to n do begin
        tot:=4;
        fillchar(p,sizeof(p),0);
        p[1].x:=0;p[1].y:=0;
        p[2].x:=maxre;p[2].y:=0;
        p[3].x:=maxre;p[3].y:=maxre;
        p[4].x:=0;p[4].y:=maxre;
        for j:=1 to n do
          if i<>j then
            cut(1/v[i]-1/v[j],1/u[j]-1/u[i],1/w[j]-1/w[i]);
        if tot>=3 then writeln('Yes') else writeln('No');
      end;
    end;
begin
  assign(input,'triath.in');reset(input);
  assign(output,'triath.out');rewrite(output);
  init;
  main;
  close(input);
  close(output);
end.
