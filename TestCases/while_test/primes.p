PROGRAM
VAR
    INTEGER n:=2, max, factor;
    boolean isPrime := true;
BEGIN
    read(max);
    while n <= max do begin
        isPrime := true;
        factor := 2;
        while isPrime and factor <= n/2 do begin
            if n%factor = 0 then isPrime := false;
            else factor := factor+1;
        end
        if isPrime then write(n);
        n := n+1;
    end 
END.
