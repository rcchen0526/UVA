def valid(s):
    for i in range(len(s)-1):
        if (ord(s[i+1])-ord(s[i]) )<=0:
            return 0
    return 1

def C(m, n):
    ans=1
    if n>m/2:
        n=m-n
    for i in range(n):
        ans*=(m-i)
        ans/=(i+1)
    return int(ans)

while True:
    try:
        data=input()
    except:
        break
    if not valid(data):
        print('0')
        continue

    index=1
    for i in range(1, len(data)):
        index+=C(26,i)

    m=25
    for n in range(len(data)):
        c = chr(ord(data[n-1])+1) if n else 'a'
        while c < data[n]:
            index+=C(m, len(data)-1-n)
            m-=1
            c=chr(ord(c)+1)
        m-=1

    print(index)