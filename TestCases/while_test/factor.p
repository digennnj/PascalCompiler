PROGRAM
VAR
    INTEGER n, factor;
BEGIN
    read(n);
    factor := 2;
    whILE n>1 do
    BEGIN
        if n%factor = 0 then
        BEGIN
            n := n/factor;
            write(factor);
        END
        else factor := factor + 1;
    END
END.
