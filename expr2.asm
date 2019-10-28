declare a, char
declare b, char
declare c, char
store a, c
declare x, real
store 0, x
declare y, real
store 1, y
declare k, integer
store 1, k
declare j, integer
store 2.5, j
declare m, integer
declare &tempr1, real
radd x, y, &tempr1
write &tempr1
write b
declare &tempr2, real
declare &tempi1, integer
store 1, &tempi1
itor &tempi1, &tempr2
declare &tempr3, real
rsub k, y, &tempr3
declare &tempi2, integer
iadd &tempr3, j, &tempi2
declare &tempr4, real
declare &tempi3, integer
store , &tempi3
itor &tempi3, &tempr4
store &tempr4, x
declare &tempi4, integer
isub j, k, &tempi4
declare &tempr5, real
declare &tempi5, integer
store , &tempi5
itor &tempi5, &tempr5
declare &tempr6, real
radd y, &tempi4, &tempr6
store &tempr6, m
store c, a
read a, 2
read y, 1
read k, 0
read m, 0
halt
