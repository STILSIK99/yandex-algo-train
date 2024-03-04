x = int(input())
a = set()
b = set()
sum = 1
start = 0
for i in range(1, 10000000):
    el = sum + start
    a.add(el)
    if i < 100000:
        b.add(el * i)
    sum += 2
    start = el
c = sorted(a | b)
print(c[x - 1])