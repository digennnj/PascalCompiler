PROGRAM
VAR
    function bar : integer;
    var
        integer b:=4,c:=5,d:=6;
    BEGIN
        bar := c;
    END;
BEGIN
    bar();
    write(bar());
;
END.
