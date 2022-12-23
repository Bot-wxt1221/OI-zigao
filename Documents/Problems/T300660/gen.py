#!/usr/bin/env python

from cyaron import *

for i in range(1, 11):
    test_data = IO(file_prefix="fib", data_id=i)
    n=randint(2**63-4000,2**63-1)
    test_data.input_write(randint(2**32-1000,2**32))
    print(n)
    test_data.output_gen("C:\\Users\\Administrator\\Desktop\\OI\\Documents\\Problems\\a\\std.exe")