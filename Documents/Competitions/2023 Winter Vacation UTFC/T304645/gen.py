#!/usr/bin/env python

from cyaron import *

for i in range(1,11):
    print("started generating")
    test_data = IO(file_prefix="recording", data_id=i)
    max=500
    if i<=2:
        n=1000000
        m=10
    elif i<=4:
        n=1000000
        m=randint((10**18)//2,10**18)
        max=50
    else:
        n=1000000
        m=randint((10**18)//2,10**18)
    test_data.input_writeln(n,m,max)
    for j in range(0,n):
        test_data.input_write(randint(1,max))
    print("finished generating")
    print("started running")
    test_data.output_gen("C:\\Users\\Administrator\\Desktop\\OI\\Documents\\Problems\\T304645\\exe\\std-pol-qpow.exe")
    print("finished running")