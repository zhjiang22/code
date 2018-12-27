var
  aA,aB : array[1..100000] of longint;
  aPair : array[0..100000] of int64;
  iNum1,iNum2,iNum3,iNum4,iNum5,iNum6,iNum7 : int64;
  iI,iJ,iTmp,iTotal : longint;
procedure qsortA(iLeft,iRight : longint);
  var
    iX,left,right : longint;
  begin
    if iLeft < iRight then
      begin
        left := iLeft; right := iRight; iX := aA[(iLeft + iRight) div 2];
        repeat
          while aA[iLeft] < iX do inc(iLeft);
          while aA[iRight] > iX do dec(iRight);
          if iLeft <= iRight then
            begin
              if iLeft <> iRight then
                begin
                  aA[iLeft] := aA[iLeft] xor aA[iRight]; aA[iRight] := aA[iLeft] xor aA[iRight]; aA[iLeft] := aA[iLeft] xor aA[iRight];
                end;
              inc(iLeft); dec(iRight);
            end;
        until iLeft > iRight;
        if iLeft < right then qsortA(iLeft,right); if left < iRight then qsortA(left,iRight);
      end;
  end;
procedure qsortB(iLeft,iRight : longint);
  var
    iX,left,right : longint;
  begin
    if iLeft < iRight then
      begin
        left := iLeft; right := iRight; iX := aB[(iLeft + iRight) div 2];
        repeat
          while aB[iLeft] < iX do inc(iLeft);
          while aB[iRight] > iX do dec(iRight);
          if iLeft <= iRight then
            begin
              if iLeft <> iRight then
                begin
                  aB[iLeft] := aB[iLeft] xor aB[iRight]; aB[iRight] := aB[iLeft] xor aB[iRight]; aB[iLeft] := aB[iLeft] xor aB[iRight];
                end;
              inc(iLeft); dec(iRight);
            end;
        until iLeft > iRight;
        if iLeft < right then qsortB(iLeft,right); if left < iRight then qsortB(left,iRight);
      end;
  end;
begin
    readln(iTotal);
    for iI := 1 to iTotal do
      readln(aA[iI],aB[iI]);
    if (iTotal = 1) and (aA[iI] = aB[iI]) then
      begin
        writeln('-1');
        halt;
      end;
  qsortA(1,iTotal);
  qsortB(1,iTotal);
  if aA[1] <> aB[1] then
    begin
      aPair[1] := abs(aA[1] - aB[1]);
      if aA[2] <> aB[2] then aPair[2] := aPair[1] + abs(aA[2] - aB[2])
                        else
      if (aA[1] <> aB[2]) and (aA[2] <> aB[1]) then aPair[2] := abs(aA[1] - aB[2]) + abs(aA[2] - aB[1]);
    end
                    else
    if (aA[1] <> aB[2]) and (aA[2] <> aB[1]) then aPair[2] := abs(aA[1] - aB[2]) + abs(aA[2] - aB[1]);
  for iI := 3 to iTotal do
    begin
      if (aA[iI - 2] <> aB[iI - 2]) and (aA[iI - 1] <> aB[iI]) and (aA[iI] <> aB[iI - 1]) and ((aPair[iI - 3] <> 0) or (iI - 3 = 0)) then
        iNum1 := aPair[iI - 3] + abs(aA[iI - 2] - aB[iI - 2]) + abs(aA[iI - 1] - aB[iI]) + abs(aA[iI] - aB[iI - 1])
                                                                                                                                     else iNum1 := 0;
      if (aA[iI - 2] <> aB[iI - 1]) and (aA[iI - 1] <> aB[iI]) and (aA[iI] <> aB[iI - 2]) and ((aPair[iI - 3] <> 0) or (iI - 3 = 0)) then
        iNum2 := aPair[iI - 3] + abs(aA[iI - 2] - aB[iI - 1]) + abs(aA[iI - 1] - aB[iI]) + abs(aA[iI] - aB[iI - 2])
                                                                                                                                      else iNum2 := 0;
      if (aA[iI - 2] <> aB[iI]) and (aA[iI - 1] <> aB[iI - 2]) and (aA[iI] <> aB[iI - 1]) and ((aPair[iI - 3] <> 0) or (iI - 3 = 0)) then
        iNum3 := aPair[iI - 3] + abs(aA[iI - 2] - aB[iI]) + abs(aA[iI - 1] - aB[iI - 2]) + abs(aA[iI] - aB[iI - 1])
                                                                                                                                      else iNum3 := 0;
      if (aA[iI - 2] <> aB[iI - 1]) and (aA[iI - 1] <> aB[iI - 2]) and (aA[iI] <> aB[iI]) and ((aPair[iI - 3] <> 0) or (iI - 3 = 0)) then
        iNum4 := aPair[iI - 3] + abs(aA[iI - 2] - aB[iI - 1]) + abs(aA[iI - 1] - aB[iI - 2]) + abs(aA[iI] - aB[iI])
                                                                                                                                      else iNum4 := 0;
      if (aA[iI - 2] <> aB[iI - 2]) and (aA[iI - 1] <> aB[iI - 1]) and (aA[iI] <> aB[iI]) and ((aPair[iI - 3] <> 0) or (iI - 3 = 0)) then
        iNum5 := aPair[iI - 3] + abs(aA[iI - 2] - aB[iI - 2]) + abs(aA[iI - 1] - aB[iI - 1]) + abs(aA[iI] - aB[iI])
                                                                                                                                      else iNum5 := 0;
      if (aA[iI - 1] <> aB[iI]) and (aA[iI] <> aB[iI - 1]) and ((aPair[iI - 2] <> 0) or (iI - 2 = 0)) then
        iNum6 := aPair[iI - 2] + abs(aA[iI - 1] - aB[iI]) + abs(aA[iI] - aB[iI - 1])
                                                                                                      else iNum6 := 0;
      if (aA[iI] <> aB[iI]) and ((aPair[iI - 1] <> 0) or (iI - 1 = 0)) then
        iNum7 := aPair[iI - 1] + abs(aA[iI] - aB[iI])
                                                                       else iNum7 := 0;
      if ((iNum1 <= iNum2) or (iNum2 = 0)) and ((iNum1 <= iNum3) or (iNum3 = 0)) and ((iNum1 <= iNum4) or (iNum4 = 0)) and ((iNum1 <= iNum5) or (iNum5 = 0)) and ((iNum1 <= iNum6) or (iNum6 = 0)) and ((iNum1 <= iNum7) or (iNum7 = 0)) and (iNum1 > 0) then
        aPair[iI] := iNum1;
      if ((iNum2 <= iNum1) or (iNum1 = 0)) and ((iNum2 <= iNum3) or (iNum3 = 0)) and ((iNum2 <= iNum4) or (iNum4 = 0)) and ((iNum2 <= iNum5) or (iNum5 = 0)) and ((iNum2 <= iNum6) or (iNum6 = 0)) and ((iNum2 <= iNum7) or (iNum7 = 0)) and (iNum2 > 0) then
        aPair[iI] := iNum2;
      if ((iNum3 <= iNum1) or (iNum1 = 0)) and ((iNum3 <= iNum2) or (iNum2 = 0)) and ((iNum3 <= iNum4) or (iNum4 = 0)) and ((iNum3 <= iNum5) or (iNum5 = 0)) and ((iNum3 <= iNum6) or (iNum6 = 0)) and ((iNum3 <= iNum7) or (iNum7 = 0)) and (iNum3 > 0) then
        aPair[iI] := iNum3;
      if ((iNum4 <= iNum1) or (iNum1 = 0)) and ((iNum4 <= iNum2) or (iNum2 = 0)) and ((iNum4 <= iNum3) or (iNum3 = 0)) and ((iNum4 <= iNum5) or (iNum5 = 0)) and ((iNum4 <= iNum6) or (iNum6 = 0)) and ((iNum4 <= iNum7) or (iNum7 = 0)) and (iNum4 > 0) then
        aPair[iI] := iNum4;
      if ((iNum5 <= iNum1) or (iNum1 = 0)) and ((iNum5 <= iNum2) or (iNum2 = 0)) and ((iNum5 <= iNum3) or (iNum3 = 0)) and ((iNum5 <= iNum4) or (iNum4 = 0)) and ((iNum5 <= iNum6) or (iNum6 = 0)) and ((iNum5 <= iNum7) or (iNum7 = 0)) and (iNum5 > 0) then
        aPair[iI] := iNum5;
      if ((iNum6 <= iNum1) or (iNum1 = 0)) and ((iNum6 <= iNum2) or (iNum2 = 0)) and ((iNum6 <= iNum3) or (iNum3 = 0)) and ((iNum6 <= iNum4) or (iNum4 = 0)) and ((iNum6 <= iNum5) or (iNum5 = 0)) and ((iNum6 <= iNum7) or (iNum7 = 0)) and (iNum6 > 0) then
        aPair[iI] := iNum6;
      if ((iNum7 <= iNum1) or (iNum1 = 0)) and ((iNum7 <= iNum2) or (iNum2 = 0)) and ((iNum7 <= iNum3) or (iNum3 = 0)) and ((iNum7 <= iNum4) or (iNum4 = 0)) and ((iNum7 <= iNum5) or (iNum5 = 0)) and ((iNum7 <= iNum6) or (iNum6 = 0)) and (iNum7 > 0) then
        aPair[iI] := iNum7;
    end;
    writeln(aPair[iTotal]);
end.
