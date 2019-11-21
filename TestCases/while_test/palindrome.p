PROGRAM
VAR
    INTEGER a,b,c,d,e,f;
    INTEGER n;
BEGIN
    repeat begin
        read(n);
        if n<0 then begin
            write("number is too small");
        end else if n<10 then begin
            write("palindrome");
        end else if n<100 then begin
            b:=n%10; n:=n/10;
            a:=n%10; n:=n/10;
            if a=b then write("palindrome");
            else write("not a palindrome");
        end else if n<1000 then begin
            c:=n%10; n:=n/10;
            b:=n%10; n:=n/10;
            a:=n%10; n:=n/10;
            if a=c then write("palindrome");
            else write("not a palindrome");
        end else if n<10000 then begin
            d:=n%10; n:=n/10;
            c:=n%10; n:=n/10;
            b:=n%10; n:=n/10;
            a:=n%10; n:=n/10;
            if a=d and b=c then write("palindrome");
            else write("not a palindrome");
        end else if n<100000 then begin
            e:=n%10; n:=n/10;
            d:=n%10; n:=n/10;
            c:=n%10; n:=n/10;
            b:=n%10; n:=n/10;
            a:=n%10; n:=n/10;
            if a=e and b=d then write("palindrome");
            else write("not a palindrome");
        end else if n<1000000 then begin
            f:=n%10; n:=n/10;
            e:=n%10; n:=n/10;
            d:=n%10; n:=n/10;
            c:=n%10; n:=n/10;
            b:=n%10; n:=n/10;
            a:=n%10; n:=n/10;
            if a=f and b=e and c=d then write("palindrome");
            else write("not a palindrome");
        end else write("number is too big");
    end until n<0
END.
