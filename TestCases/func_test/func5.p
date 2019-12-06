PROGRAM
VAR
    string greeting := "Hello", person := "world";
    procedure bar;
    var
        string greeting := "Salutations";
        integer b:=4,c:=5,d:=6;
    BEGIN
        write("What is your name?>");
        read(person);
        write(greeting);
        write(person);
    END;
BEGIN
    baz();
    write(greeting);
    write(person);
;
END.
