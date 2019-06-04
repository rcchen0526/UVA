prime=[0 for _ in range(100001)]
for i in range(2, 100001):
    if not prime[i]:
        j=2*i
        while j<100001:
            prime[j]=1
            j+=i
while True:
    data=input()
    if data=='0':
        break
    ans=0
    for i in range(len(data)):
        j=i+1
        while j<=len(data):
            temp=int(data[i:j])
            if temp>100000:
                break
            elif not prime[temp]:
                ans=temp if temp>ans else ans
            j+=1
    print(ans)