PROGRAM
VAR
integer a;
procedure bar;
var integer a;
BEGIN
    write("Bye computer");
END;
function foo : integer;
var
integer a;
function qux : integer;
BEGIN qux := a+1; END;
BEGIN
    write("Hello world");
    foo := qux()*2;
END;
BEGIN
    bar();
    write(foo());
    a := foo()+2;
    write(a);
;
END.
