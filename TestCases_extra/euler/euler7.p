PROGRAM
VAR
    INTEGER n:=2, i:=0, factor;
    boolean isPrime := true;
BEGIN
    while i < 101 do begin
        isPrime := true;
        factor := 2;
        while isPrime and factor <= n/2 do begin
            if n%factor = 0 then isPrime := false;
            else factor := factor+1;
        end
        if isPrime then i := i+1;
        n := n+1;
    end 
    write(n-1);
END.
