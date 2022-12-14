

import random


COUNT = 1000


c_str_op_a = "uint64_t op_a_pool[] = {"
c_str_op_b = "uint64_t op_b_pool[] = {"
for i in range(COUNT):
    if i% 10 ==0:
        c_str_op_a += "\n\t"
        c_str_op_b += "\n\t"
    c_str_op_a += hex(random.randrange(0x80000000 , 0xffffffff)) +", "
    c_str_op_b += hex(random.randrange(0x80000000 , 0xffffffff)) +", "


c_str_op_a += "\n};"
c_str_op_b += "\n};"
print(c_str_op_a)


file = open("random_inp_"+str(COUNT) + ".h","w")
file.write("\n\n");
file.write("int input_count="+str(COUNT)+ ";\n")
file.write("\n\n");
file.write(c_str_op_a);
file.write("\n\n");
file.write(c_str_op_b);
file.close()

