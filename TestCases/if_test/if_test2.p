PROGRAM
var
integer in;
BEGIN
    read(in);
    IF 1 <= in THEN
        IF 2 <= in THEN
            IF 3 <= in THEN
                IF NOT in < 4 THEN
                    write("You have found the secret cave!");
                ELSE write("You took a wrong turn at 4...");
            ELSE write("You took a wrong turn at 3...");
        ELSE write("You took a wrong turn at 2...");
    ELSE write("You took a wrong turn at 1...");
END.
