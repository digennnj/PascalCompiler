prOgraM
   vAr
       BOOLEAN less := true, more;
{ try storing 1.1 into more - error }
       character a, b, c :='a';
{ try storing a string into b - error }
       Real x := 0, y:=1;
       inteGER k, j := 2.5, m;
       String hello:="hi!", bye := "goodbye", no;
{ try storing a character into no - error }
Begin
    Write( x + y, b, not less );
    x := k - y + j;
    m := y + ( j - k );
    a := c;
{ here is a multiline comment on a single line }
   reAd( a, y, k, no );
   bye := hello + bye;
   bye := bye + "ha";
   bye := "byebye";
   x := m + k * x;
   j := k / j % m;
// try a mod with a real operand - should raise an error
BEgin
   more := j-m >= x;
end
   if not more THEN
begin
 m := x * (y - j) / k;
   more := less and more or x < y;
end
Else
   y := k * x + 3;
if less = more then
   if x > m then
      j := k % 4;
else
   no := bye; 
END.

