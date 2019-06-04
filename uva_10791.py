length=46345
prime=[False for _ in range(length)]
prime_list=[]
for i in range(2, length):
    prime[i]=True
for i in range(2, length):
    if prime[i]:
        prime_list.append(i)
        j=2*i
        while j<length:
            prime[j]=False
            j+=i
Case=0
while True:
    try:
        n=int(input())
    except:
        break
    if not n:
        break
    ans, temp_n=0, n
    Case+=1
    if n==2147483648 or n==1:
        print("Case {}: {}".format(Case, n+1))
    else:
        i=0
        while i<len(prime_list) and prime_list[i]<=n:
            temp=1
            while not(n%prime_list[i]):
                n/=prime_list[i]
                temp*=prime_list[i]
            if temp!=1:
                ans+=temp
            i+=1
        if ans==temp_n or not ans:
            ans+=1
        if n!=1:
            ans+=n
        print("Case {}: {}".format(Case, int(ans)) )
