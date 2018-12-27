program Test;
var
  ga:array[1..100,1..100] of longint;
  n,ans:longint;

function min(a,b:longint):longint;
  begin
    if a<b then min:=a else min:=b;
  end;

function max_flow(s,t:longint):longint;
  var
    flow,pre:array[1..100] of longint;
    used:array[1..100] of boolean;
    max,max_loc,i,k,total:longint;
  begin
    total:=0;
    while true do
      begin
        fillchar(used,sizeof(used),false);
        fillchar(flow,sizeof(flow),0);
        fillchar(pre,sizeof(pre),0);
        flow[s]:=maxlongint;
        pre[s]:=-1;
        while true do
          begin
            max:=0;
            max_loc:=-1;
            for i:=1 to n+1 do
              if (not used[i]) and (flow[i]>max) then
                begin
                  max:=flow[i];
                  max_loc:=i;
                end;
            if (max_loc=-1) or (max_loc=t) then break;
            used[max_loc]:=true;
            for i:=1 to n+1 do
              if min(flow[max_loc],ga[max_loc,i])>flow[i] then
                begin
                  flow[i]:=min(flow[max_loc],ga[max_loc,i]);
                  pre[i]:=max_loc;
                end;
          end;
        if max_loc=-1 then
          exit(total);
        total:=total+flow[t];
        i:=t;
        while pre[i]<>-1 do
          begin
            k:=pre[i];
            dec(ga[k,i],flow[t]);
            inc(ga[i,k],flow[t]);
            i:=k;
          end;
      end;
  end;

procedure init;
  var
    i,a,b,e,m,x,w:longint;
  begin
    readln(n,e);
    fillchar(ga,sizeof(ga),0);
    for i:=1 to e do
      begin
        readln(a,b,w);
        ga[a,b]:=w;
        ga[b,a]:=w;
      end;
    readln(m);
    for i:=1 to m do
      begin
        read(x);
        ga[x,n+1]:=maxlongint;
      end;
  end;

procedure work;
  var
    i:longint;
  begin
    ans:=max_flow(1,n+1);
  end;

procedure print;
  begin
    writeln(ans);
  end;

begin
  init;
  work;
  print;
end.
