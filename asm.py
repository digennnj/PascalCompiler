#!/usr/bin/env python3
from sys import stdin,stdout, argv
from collections import defaultdict
symbols = {}
def parse(line):
    cmd, *rest = line.split()
    args = ''.join(rest).split(',')
    return (cmd, args)
def lit(term):
    try: return int(term)
    except ValueError: pass
    try: return float(term)
    except ValueError: pass
    if len(term)==3 and term[0]==term[-1]=="'": return term[1]
    if term.lower()=="true": return True
    if term.lower()=="false": return False
    raise ValueError("not a valid literal: {}".format(term))
def val(term):
    try: return lit(term)
    except ValueError: pass
    if term in symbols: return symbols[term]
    print("symbol table: ", symbols)
    raise ValueError("symbol not defined: {}".format(term))
def t(typ):
    if type(typ)==str: typ=typ.lower()
    types = {'integer':int, 'real':float, 'character':str, 'boolean':bool, int:int, float:float, str:str, bool:bool}
    return types[typ]
def expectType(typ, *terms):
    typ = t(typ)
    for term in terms:
        if type(val(term))!=typ:
            raise ValueError("expected {} but got ({}={!r})".format(typ, term, val(term)))
def dbg(term):
    print('{} = {!r}'.format(term, val(term)))
def exec(stmt):
    cmd, args = stmt
    if cmd=="declare":
        dst,typ = args
        typ=t(typ)
        if typ==int: res=0
        elif typ==float: res=0.0
        elif typ==str: res='\0'
        elif typ==bool: res=False
        else: raise ValueError("Invalid type: {}".format(typ))
        symbols[dst]=res; # dbg(dst)
    elif cmd=="read":
        dst, = args
        resp=input(dst+"> ")
        res=lit(resp)
        typ = type(symbols[dst])
        if type(res)!=typ: raise ValueError("expected {} but got lit {}".format(typ, resp))
        symbols[dst] = res; dbg(dst)
    elif cmd=="isub" or cmd=="rsub":
        a,b,dst = args
        if cmd=="isub": expectType(int, a,b,dst)
        elif cmd=="rsub": expectType(float, a,b,dst)
        symbols[dst] = val(a)-val(b); dbg(dst)
    elif cmd=="iadd" or cmd=="radd":
        a,b,dst = args
        if cmd=="iadd": expectType(int, a,b,dst)
        elif cmd=="radd": expectType(float, a,b,dst)
        symbols[dst] = val(a)+val(b); dbg(dst)
    elif cmd=="store":
        a,dst = args
        expectType(type(symbols[dst]), a)
        symbols[dst] = val(a); dbg(dst)
    elif cmd=="write":
        a, = args
        print("out({}): {!r}".format(a, val(a)))
    elif cmd=="itor":
        a,dst = args
        expectType(int, a); expectType(float, dst)
        symbols[dst] = float(val(a)); dbg(dst)
    elif cmd=="rtoi":
        a,dst = args
        expectType(float, a); expectType(int, dst)
        symbols[dst] = int(val(a)); dbg(dst)
    elif cmd=="halt":
        exit(0)
    else:
        raise ValueError("statement not recognized: {}".format(stmt))

with open(argv[1], "r") as f:
    for lineNum, line in enumerate(f):
        try: 
            exec(parse(line))
        except Exception:
            print("error on line {}: {}".format(lineNum, line.rstrip()))
            raise
