prOgraM
   vAr
       BOOLEAN less := true, more;
{ try storing 1.1 into more - error }
       character a, b, c :='a';
{ try storing a character into no }
       Real x := 0, y:=1;
       inteGER k, j := 2.5, m;
       String hello:="hi!", bye := "goodbye", no; { used "=" in original}
Begin
    Write( x + y, b, not less );
    x := k- y + j;
    m := y + ( j - k );
    a := c;
{ here is a multiline comment on a single line }
   reAd( a, y, k, no );
   bye := hello + bye;
//   bye := bye + c; { does not work currently }
   bye := "byebye";
   x := m + k * x;
   j := k / j % m;
// try a mod with a real operand
   y := k * x + 3;
   m := x * (y - j) / k;
   more := j-m >= x; { >= doesn't work?? }
   less := not more;
   more := less and more or x < y;
// error should be raised when assigning a char to a string and visa versa\
END.

