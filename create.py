import random

for i in range(10):
    p=random.randint(2, 5800)
    q=random.randint(2, 100)
    s=random.randint(2, 100)
    r=random.randint(2, 100)
    if p<q:
        p, q=q, p
    if r<s:
        s, r=r, s
    print('{}'.format(p))
