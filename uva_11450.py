MAX_M =  200
MAX_C =  20
MAX_K =  20

test_num=int(input())

while True:
    if test_num==0:
        break
    test_num-=1
    kind = [ [0] for _ in range(MAX_C+1)]
    price = [ [0]*(MAX_C+1) for _ in range(MAX_M+2)]
    M, C = input().split()
    M, C = int(M), int(C)
    Max=0
    for __c in range(C):
        kind[__c].pop()
        for item in input().split():
            kind[__c].append(int(item))
    
    price[0][0]=1
    for __c in range(C):
        for k in range(1, kind[__c][0]+1):
            p=0
            while (p+kind[__c][k])<=M:
                if price[p][__c]:
                    price[p+kind[__c][k] ][__c+1]=1
                p+=1
    i=M
    while i>=0 and not price[i+1][C]:
        if price[i][C]:
            Max=i
        i-=1
    if Max:
        print(Max)
    else:
        print('no solution')
