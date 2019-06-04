def mod(a, n):
    N=n
    ans=a if n%2 else 1
    while int(n/2):
        n=int(n/2)
        temp=(a*a)%N
        if n%2:
            ans=(ans*temp)%N
        a=temp
    return ans

def check(a, n):
    if mod(a, n)==a:
        return True
    else:
        return False

prime=[False for _ in range(65001)]
prime[0], prime[1] = True, True
for i in range(2, 65001):
    if not prime[i]:
        j=2*i
        while j<=65000:
            prime[j]=True
            j+=i

while True:
    try:
        n=int(input())
    except:
        break
    if not n:
        break
    isCarmichael = True
    if not prime[n]:
        isCarmichael = False

    for i in range(2, n):
        isCarmichael = isCarmichael and check(i, n)
        if not isCarmichael:
            break

    if isCarmichael:
        print("The number {} is a Carmichael number.".format(n))
    else:
        print("{} is normal.".format(n))