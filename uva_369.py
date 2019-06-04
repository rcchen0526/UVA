while True:
    m, n = input().split()
    m, n = int(m), int(n)
    if not m and not n:
        break
    _n=n
    ans=1
    if n>m/2:
        _n=m-n
    for i in range(_n):
        ans*=(m-i)
        ans/=(1+i)
    print("{} things taken {} at a time is {} exactly.".format(m, n, int(ans)) )
