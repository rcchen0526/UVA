E=[0]
value=[1.]
for _ in range(1000001):
    value.append(value[-1]/2.)
    E.append(E[-1])
    if value[-1]<1:
        value[-1]*=10.
        E[-1]-=1
while True:
    try:
        num=int(input())
    except:
        break
    val='%.3f'%value[num]
    print("2^-{} = {}e{}".format(num, val, E[num]))