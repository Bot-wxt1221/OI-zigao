#!/usr/bin/env python

from cyaron import *

for i in range(1, 11):
    print("started generating")
    test_data = IO(file_prefix="square", data_id=i)
    if i<=2:
        n=1000
        m=2
    elif i<=4:
        n=100
        m=100
    else:
        n=1000
        m=1000
    max=10000000
    dx=100
    k1=randint(i-1,9)
    k2=randint(i-1,9)
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
    print("started running")
    test_data.output_gen("C:\\Users\\Administrator\\Desktop\\OI\\Documents\\Problems\\T303881\\exe\\std-int128.exe")
    print("finished running")