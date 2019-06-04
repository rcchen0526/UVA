mod=0
class node():
    def __init__(self):
        self.a=[[0, 0], [0, 0]]

def mul(x, y):
    global mod
    ans=node()
    for i in range(2):
        for j in range(2):
            for k in range(2):
                ans.a[i][k]=(ans.a[i][k]+x.a[i][j]*y.a[j][k])%mod
    return ans

def find(a, n):
    ans=node()
    ans.a[0][0]=ans.a[1][1]=1
    while n:
        if(n%2):
            ans=mul(ans, a)
        a=mul(a, a)
        n=int(n/2)
    return ans
while True:
    try:
        data=input().split()
        n, m=int(data[0]), int(data[1])
    except:
        break
    temp=node()
    temp.a[0][0]=temp.a[1][0]=temp.a[0][1]=1
    mod=pow(2, m)
    ans=find(temp, n)
    print(ans.a[1][0])