PROGRAM
VAR
    INTEGER sum_of_squares, sum, i;
BEGIN
    i := 0;
    repeat begin
        i := i+1;
        sum_of_squares := sum_of_squares + i*i;
        sum := sum + i;
    end until i>=100
    write(sum*sum - sum_of_squares);
END.
