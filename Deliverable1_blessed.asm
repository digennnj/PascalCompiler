declare a, character
declare b, character
declare &tempc1, character
store 'a', &tempc1
declare c, character
store &tempc1, c
declare &tempi1, integer
store 0, &tempi1
declare x, real
declare &tempr1, real
declare &tempi2, integer
store &tempi1, &tempi2
itor &tempi2, &tempr1
store &tempr1, x
declare &tempi3, integer
store 1, &tempi3
declare y, real
declare &tempr2, real
declare &tempi4, integer
store &tempi3, &tempi4
itor &tempi4, &tempr2
store &tempr2, y
declare k, integer
declare &tempr3, real
store 2.5, &tempr3
declare j, integer
declare &tempi5, integer
declare &tempr4, real
store &tempr3, &tempr4
rtoi &tempr4, &tempi5
store &tempi5, j
declare m, integer
declare &tempr5, real
radd x, y, &tempr5
write &tempr5
write b
declare &tempr6, real
declare &tempi6, integer
store k, &tempi6
itor &tempi6, &tempr6
declare &tempr7, real
rsub &tempr6, y, &tempr7
declare &tempr8, real
declare &tempi7, integer
store j, &tempi7
itor &tempi7, &tempr8
declare &tempr9, real
radd &tempr7, &tempr8, &tempr9
store &tempr9, x
declare &tempi8, integer
isub j, k, &tempi8
declare &tempr10, real
declare &tempi9, integer
store &tempi8, &tempi9
itor &tempi9, &tempr10
declare &tempr11, real
radd y, &tempr10, &tempr11
declare &tempi10, integer
declare &tempr12, real
store &tempr11, &tempr12
rtoi &tempr12, &tempi10
store &tempi10, m
store c, a
read a
read y
read k
halt
