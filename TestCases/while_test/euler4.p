PROGRAM
VAR
    INTEGER a,b,c,d,e,f;
    INTEGER x:=999,y:=999, product, digits;
BEGIN
    repeat begin
        y := 999;
        repeat begin
            product := x*y;
            digits := product;
            if product<100000 then begin
                e:=digits%10; digits:=digits/10;
                d:=digits%10; digits:=digits/10;
                c:=digits%10; digits:=digits/10;
                b:=digits%10; digits:=digits/10;
                a:=digits%10; digits:=digits/10;
                if a=e and b=d then write(product);
            end else begin
                f:=digits%10; digits:=digits/10;
                e:=digits%10; digits:=digits/10;
                d:=digits%10; digits:=digits/10;
                c:=digits%10; digits:=digits/10;
                b:=digits%10; digits:=digits/10;
                a:=digits%10; digits:=digits/10;
                if a=f and b=e and c=d then write(product);
            end
            y := y-1;
        end until y<100
        x := x-1;
    end until x<100
END.
