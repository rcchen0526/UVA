v=[[0], [1], [4, 6], [7, 3], [6], [5], [6], [3, 7], [6, 4], [9]]
while True:
    try:
        N=input()
    except:
        break
    if not (ord(N[0])-ord('0')):
        break
    if len(N)==1:
        n=ord(N[0])-ord('0');
    else:
        n=(ord(N[-2])-ord('0'))*10+(ord(N[-1])-ord('0'))
    Sum=0
    for i in range(1, n+1):
        Sum+=v[i%10][int(i/10) % len(v[i%10])]
    print(Sum%10)