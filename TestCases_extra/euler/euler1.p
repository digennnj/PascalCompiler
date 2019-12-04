PROGRAM
VAR
    INTEGER sum, i:=0;
BEGIN
    repeat begin
        if i%3 = 0 or i%5 = 0 then
            sum := sum + i;
        i:=i+1;
    end
    until i>=1000
    write(sum);
END.
