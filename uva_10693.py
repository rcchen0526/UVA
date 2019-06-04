import math
while True:
    try:
        l, f=input().split()
        l, f=float(l), float(f)
    except:
        break
    if not l and not f:
        break
    v=math.sqrt(2*l*f)
    t=v/f
    v, t='%.8f'%v, '%.8f'%(3600./t)
    print("{} {}".format(v, t))