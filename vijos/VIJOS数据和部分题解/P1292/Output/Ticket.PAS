{$M 65520,0,655360}
{$r-,s-,q-,n+}
Const Infns                 = 'ticket.in';
      Outfns                = 'ticket.out';
      Maxn                  = 10000;
      MaxCost               = 99999999999.0;
Var n, Start, Last          : Integer;
    f                       : array[1 .. Maxn] of ^Comp;
    L, C                    : array[1 .. 3] of Longint;

Procedure Getf;
var i       : integer;
begin
  for i :=1 to Maxn do begin
    new(f[i]);
    f[i]^ :=0;
  end;{for i}
end;{Getf}

Procedure Main;
var Inf      : Text;
    i, j     : Integer;
    Dist     : array[1 .. Maxn] of Longint;
    k        : array[1 .. 3] of Integer;
    p        : array[1 .. 3] of Longint;
    Distance : Longint;
begin
  Assign(Inf, Infns);
  Reset(Inf);
    readln(Inf, L[1], L[2], L[3], C[1], C[2], C[3]);
    readln(Inf, n);
    readln(Inf, Start, Last);
    Dist[1] :=0;
    for i :=2 to n do readln(Inf, Dist[i]);
  Close(Inf);
  p[1] :=L[1];  p[2] :=L[2];  p[3] :=L[3];
  k[1] :=Start; k[2] :=Start; k[3] :=Start;
  for i :=Start + 1 to Last do begin
    Distance :=Dist[i] - Dist[i - 1];
    f[i]^ :=MaxCost;
    for j :=1 to 3 do
      if Distance <= p[j] then begin
        Dec(p[j], Distance);
        if f[k[j]]^ + C[j] < f[i]^ then f[i]^ :=f[k[j]]^ + C[j];
      end{then}
      else
        begin
          while k[j] < i do begin
            inc(k[j]);
            if Dist[i] - Dist[k[j]] <= L[j] then break;
          end;{while}
          if (k[j] <= i) and (Dist[i] - Dist[k[j]] <= L[j]) then begin
            p[j] :=L[j] - (Dist[i] - Dist[k[j]]);
            if C[j] + f[k[j]]^ < f[i]^ then f[i]^ :=C[j] + f[k[j]]^;
          end{then}
          else
            p[j] :=L[j];
        end;{else}
  end;{for i}
end;{Main}

Procedure Out;
var Outf     : Text;
begin
  Assign(Outf, Outfns);
  Rewrite(Outf);
    writeln(Outf, f[Last]^ : 0 : 0);
  Close(Outf);
end;{Out}

Begin
  Getf;
  Main;
  Out;
End.