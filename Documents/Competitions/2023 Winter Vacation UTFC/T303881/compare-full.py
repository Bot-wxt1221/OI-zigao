#!/usr/bin/env python

from cyaron import *

while True:
    print("started generating")
    test_data = IO(file_prefix="compare")
    n=1000
    m=1000
    max=10000000
    dx=100
    k1=randint(1,9)
    k2=randint(1,9)
    b1=randint(max//2,max)
    b2=randint(max//2,max)
    test_data.input_writeln(n,m,k1,b1,k2,b2)
    xq=1
    xp=1
    for j in range(0,n):
        test_data.input_writeln(xq,xp)
        xq=xq+randint(1,dx)
        xp=xp+randint(1,dx)
    print("finished generating")
    print("started running",k1,b1,k2,b2)
    # break
    Compare.program("C:\\Users\\Administrator\\Desktop\\OI\\Documents\\Problems\\T303881\\exe\\std.exe","C:\\Users\\Administrator\\Desktop\\OI\\Documents\\Problems\\T303881\\exe\\std-wxt.exe",input=test_data,std_program="C:\\Users\\Administrator\\Desktop\\OI\\Documents\\Problems\\T303881\\std-int128.exe")
    print("finished running")