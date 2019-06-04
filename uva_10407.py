def GCD(a, b):
    while b:
        temp=a%b
        if a>0 and temp<0:
            temp-=b
        a, b = b, temp
    return a

while True:
    d=[]
    data=input().split()
    if len(data)==1:
        break
    for item in data:
        d.append(abs(int(item)-int(data[0])))
    d=d[:-1]
    ans=0
    for item in d:
        ans=GCD(item, ans)
    print(ans)
