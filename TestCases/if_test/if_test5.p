PROGRAM
var
integer in;
BEGIN
    read(in);
    IF 1 <= in THEN
        IF 2 <= in THEN
            IF 3 <= in THEN BEGIN
                IF 4 <= in THEN write("Oh no! too far!");
            END ELSE write("This works though.");
END.
