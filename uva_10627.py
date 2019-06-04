def GCD(a, b):
    if a<b:
        a, b=b, a
    while b:
        temp=a%b
        a, b = b, temp
    return a
while True:
    try:
        data=input().split()
        L, u, v, t=int(data[0]), int(data[1]), int(data[2]), int(data[3])
    except:
        break
    if not L and not t:
        break
    if not u and not v:
        print(0)
        continue
    ans=0
    ans+=int( ((u+v)*t+L)//(2*L) )#confort, L means first distance
    ans+=int( (abs(u-v)*t+L)//(2*L) )#catch
    edge=GCD(u, v)
    if int(abs(u-v)//edge)%2:
        ans-=int((edge*t+L)//(2*L))
    print(ans)