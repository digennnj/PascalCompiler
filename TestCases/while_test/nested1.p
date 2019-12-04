PROGRAM
VAR
    INTEGER a := 1, b:=1, c, d, fact:=1;
BEGIN
    whILE a <= 5 do 
    BEGIN
        RepEat
        begin
            c := b;
            d := 0;
            while c>0 do begin
                d := d + fact;
                c := c-1;
            end
            fact := d;
            b := b+1;
        end
        Until b > a
        b := 1;
        write(a);
        write(fact);
        fact := 1;
        a := a + 1;
    end
END.
