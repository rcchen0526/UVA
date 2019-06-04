MAX=1000000
prime=[True for _ in range(MAX)]
digit_prime=[0 for _ in range(MAX)]
def is_digit_prime(n):
    SUM=0
    while n:
        SUM+=n%10
        n=int(n/10)
    if prime[SUM]:
        return True
    else:
        return False

for i in range(2, MAX):
    if prime[i]:
        j=2*i
        while j<MAX:
            prime[j]=False
            j+=i
        if is_digit_prime(i):
            digit_prime[i]=digit_prime[i-1]+1
    if not digit_prime[i]:
        digit_prime[i]=digit_prime[i-1]

num=int(input())
for i in range(num):
    data=input().split()
    print(digit_prime[int(data[1])]-digit_prime[int(data[0])-1])
