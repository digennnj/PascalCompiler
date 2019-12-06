PROGRAM
VAR
    integer a:=1,b:=2,c:=3;
    procedure bar;
    var
        integer b:=4,c:=5,d:=6;
    BEGIN
        write("Hello computer");
        read(c);
        write(a+b+c);
    END;
BEGIN
    bar;
    write(a+b+c);
;
END.
