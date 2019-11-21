PROGRAM
VAR
    INTEGER a,b,amax,bmax;
BEGIN
    read(amax);
    read(bmax);
    a := 1;
    while a<=amax do begin
        b := 1;
        while b<=bmax do begin
            write(a,b);
            b := b+1;
        end
        a := a+1;
    end 
END.
