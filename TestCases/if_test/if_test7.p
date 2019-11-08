PROGRAM
var
integer in;
BEGIN
    read(in);
    IF in < 5 THEN BEGIN
        IF in % 2 = 0 THEN BEGIN
            write("even small");
        END
        ELSE write("odd small");
        write("small");
    END
    ELSE BEGIN
        BEGIN
            IF in%2 = 0 THEN write("even big");
            ELSE BEGIN write("odd big"); END
        END
        BEGIN write("big"); END
    END
END.
