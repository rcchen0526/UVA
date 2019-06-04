f=[0, 0]
for _ in range(999999):
    f.append(1)
for i in range(2, 1000001):
    if f[i]==1:
        j=2
        while i*j<1000001:
            f[i*j]=f[i]+f[j]
            j+=1
for i in range(2, 1000001):
    f[i]+=f[i-1]
while True:
    try:
        n=int(input())
        print(f[n])
    except:
        break