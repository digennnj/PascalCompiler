PROGRAM
VAR
integer a;
procedure bar; BEGIN
    write("Bye computer");
END;
function foo : integer; BEGIN
    write("Hello world");
    foo := 3;
END;
BEGIN
    bar;
    write(foo);
    a := foo+2;
    write(a);
;
END.
