import random
import sys

file = open('arg_test', 'w+')
l = random.sample(range(-3000,3000), int(sys.argv[1]))
for item in l:
    file.write(str(item) + ' ')
file.close
#./push_swap.exe $(cat arg_test)