PROGRAM
VAR
    INTEGER res := 1, n, i := 2, factor;
BEGIN
    repeat begin
        factor := 2;
        n := i;
        while n>1 do begin
            if n%factor = 0 then begin
                n := n/factor;
                { remove common factors }
                if res%factor = 0 then begin
                    res := res/factor;
                end
            end else begin
                factor := factor+1;
            end
        end
        res := res*i;
        i := i+1;
    end until i>20
    write(res);
END.
