import math
def cal(n, k):
    root1=(-3*k+math.sqrt(12*n/k-3*pow(k, 2)) )/6;
    root2=(-3*k-math.sqrt(12*n/k-3*pow(k, 2)) )/6;
    if root1<0:
        return int(root2)
    else:
        return int(root1)
while True:
    n=int(input())
    if not n:
        break
    k=int(math.ceil(pow(n, 1./3.)))+1
    solution=False
    for i in range(k):
        y=int(cal(float(n), float(i+1)))
        x=y+i+1
        if x>=0 and y>=0 and x*x*x-y*y*y==n:
            print('{} {}'.format(x, y))
            solution=True
            break
    if not solution:
        print('No solution')