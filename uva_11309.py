def check(num):
    if num<10:
        return 0
    elif num<100:
        if int(num/10)==num%10:
            return 0
        else:
            return 1
    elif num<1000:
        if int(num/100)==num%10:
            return 0
        else:
            return 1
    else:
        h1, h2=int(num/1000), int(num/100)%10
        m=num%100
        if h2*10+h1==m:
            return 0
        else:
            return 1
num=int(input())
while num:
    num-=1
    data=input()
    h=int(data[0:2])
    m=int(data[3:])
    while True:
        m+=1
        if m==60:
            m, h=0, h+1
        if h==24:
            h=0
        if not check(h*100+m):
            break
    print('{:0>2}:{:0>2}'.format(h, m))