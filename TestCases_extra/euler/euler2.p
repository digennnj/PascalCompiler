PROGRAM
VAR
    INTEGER prev:=0, cur:=1, tmp, sum:=0;
BEGIN
    while cur < 4000000 do begin
        if cur%2 = 0 then sum := sum + cur;
        tmp := cur;
        cur := cur + prev;
        prev := tmp;
    end 
    write(sum);
END.
