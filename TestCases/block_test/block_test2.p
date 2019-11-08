PROGRAM
var
integer b,c:=3;
;
BEGIN
    b := 1;
    BEGIN
        b := c;
        BEGIN
            write(b);
        END
    END
    write(b);
END.
