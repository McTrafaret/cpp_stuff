import random

matrix = [[random.randint(0, 9) for j in range(10)] for i in range(10)]
file_ = open('input.txt', 'w')
for string in matrix:
    for element in string:
        file_.write(str(element)+' ')
    file_.write('\n')

file_.close()
