#!/usr/bin/env python

from cyaron import *

while True:
    print("started generating")
    test_data = IO(file_prefix="recording")
    max=500
    n=1000000
    m=10
    for j in range(0,n):
        test_data.input_write(randint(1,max))
    print("finished generating")
    print("started running")
    Compare.program("C:\\Users\\Administrator\\Desktop\\OI\\Documents\\Problems\\T304645\\exe\\std-pol.exe",input=test_data,std_program="C:\\Users\\Administrator\\Desktop\\OI\\Documents\\Problems\\T304645\\exe\\std-pol-qpow.exe")
    print("finished running")