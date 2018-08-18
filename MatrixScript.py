import re
n, m = map(int, input().strip().split(' '))

matrix = []
matrix_i = 0

for matrix_i in range(n):
    matrix_t = input() 
    matrix.append(matrix_t)

sentence = ''

for i in range(m):
    for j in range(n):
        if(len(matrix[j]) > i):
            sentence += matrix[j][i]

r = re.compile('([a-zA-Z0-9])(\s*)([!@#$%& ]+)(\s*)([a-zA-Z0-9])')
s = r.sub(r'\1' + ' ' + r'\5', sentence)
print(s)
