PROGRAM
VAR
    INTEGER prev:=0, cur:=1, tmp, max;
BEGIN
    read(max);
    while cur <= max do begin
        write(cur);
        tmp := cur;
        cur := cur + prev;
        prev := tmp;
    end 
END.
