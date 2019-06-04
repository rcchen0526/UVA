MAX=20000000
prime=[True for _ in range(MAX)]
twin=[]
for i in range(2, MAX):
    if prime[i]:
        j=2*i
        while j<MAX:
            prime[j]=False
            j+=i
    if prime[i-2] and prime[i]:
        twin.append(i-2)
while True:
    try:
        S=int(input())
    except:
        break
    print("({}, {})".format(twin[S+1], twin[S+1]+2))
