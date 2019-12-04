PROGRAM
VAR
    INTEGER n:=600851475143, factor;
BEGIN
    factor := 2;
    whILE n>1 do
    BEGIN
        if n%factor = 0 then
        BEGIN
            n := n/factor;
        END
        else factor := factor + 1;
    END
    write(factor);
END.
