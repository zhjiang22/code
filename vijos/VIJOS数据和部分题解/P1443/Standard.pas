const
        maxn    =30000;
var
        f,c,d   :array[1..maxn] of longint;
        t,i,x,y :longint;
        ch      :char;

        function getfather(x:longint):longint;
        var
                fa      :longint;
        begin
                if x=f[x] then exit(x);
                fa:=getfather(f[x]);
                d[x]:=d[f[x]]+d[x];
                f[x]:=fa;
                exit(f[x]);
        end;

begin
        assign(input,'galaxy.in');reset(input);
        assign(output,'galaxy.out');rewrite(output);

        readln(t);
        for i:=1 to maxn do
        begin
                f[i]:=i;
                c[i]:=1;
        end;
        for i:=1 to t do
        begin
                read(ch);
                readln(x,y);
                if ch='M' then
                begin
                        x:=getfather(x);
                        y:=getfather(y);
                        f[x]:=y;
                        d[x]:=c[y];
                        c[y]:=c[y]+c[x];
                end
                else
                begin
                        if getfather(x)<>getfather(y)
                        then    writeln(-1)
                        else    writeln(abs(d[x]-d[y])-1);
                end;
        end;

        close(input);close(output);
end.
