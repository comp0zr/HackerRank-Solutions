import itertools

def f(x):
    return x**2

k, M = list(map(int, input().split()))
lists = []

for i in range(k):
    lists.append(list(map(int, input().split()))[1::])    
    
sums = [0]
    
for i in range(k):
    temp = []
    nextSums = []
    L = lists[i]    
    L = list(map(lambda x: x**2, L))
    
    for j in range(len(L)):        
        temp.append(L[j])
    
    for s in sums:
        for j in temp:
            nextSums.append((s + j) % M)
    sums = nextSums

sums = sorted(sums)
print(sums[-1])
