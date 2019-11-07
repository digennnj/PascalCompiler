PROGRAM
var
integer in;
BEGIN
    read(in);
    IF 1 <= in THEN
        IF 2 <= in THEN
            IF 3 <= in THEN
                IF 4 <= in THEN write("Oh no! too far!");
            ELSE write("Oh no! this might not do what you think it does...");
            { ELSE will always match with the previous THEN? }
END.
