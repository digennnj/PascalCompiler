from sys import stdin,stdout, argv
from collections import defaultdict
symbols = defaultdict(int)
def parse(line):
    cmd, *rest = line.split()
    args = ''.join(rest).split(',')
    return (cmd, args)
def val(term):
    try: return int(term)
    except ValueError: pass
    try: return float(term)
    except ValueError: pass
    if term in symbols: return symbols[term]
    raise ValueError("symbol not defined: {}".format(term))
def exec(stmt):
    cmd, args = stmt
    if cmd=="declare":
        dst,type = args
        symbols[dst]=0
    elif cmd=="read":
        dst,type = args
        symbols[dst] = int(input(dst+"> "))
    elif cmd=="isub":
        a,b,dst = args
        #print(f'{dst} = {val(a)}-{val(b)}')
        symbols[dst] = val(a)-val(b)
    elif cmd=="iadd":
        a,b,dst = args
        #print(f'{dst} = {val(a)}+{val(b)}')
        symbols[dst] = val(a)+val(b)
    elif cmd=="store":
        a,dst = args
        #print(f'{dst} = {val(a)}')
        symbols[dst] = val(a)
    elif cmd=="write":
        a,type = args
        print(val(a))
    elif cmd=="itor":
        a,dst = args
        symbols[dst] = float(val(a))
    elif cmd=="rtoi":
        a,dst = args
        symbols[dst] = int(val(a))
    elif cmd=="halt":
        exit(0)

with open(argv[1], "r") as f:
    for line in f:
        exec(parse(line))
