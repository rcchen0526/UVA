while True:
    try:
        setA=input().split()
        setB=input().split()
    except:
        break
    countA, countB=0, 0
    for itemA in setA:
        for itemB in setB:
            if itemA==itemB:
                countA+=1
                break
    for itemB in setB:
        for itemA in setA:
            if itemB==itemA:
                countB+=1
                break
    if countA==len(setA) and len(setA)<len(setB):
        print('A is a proper subset of B')
    elif countB==len(setB) and len(setB)<len(setA):
        print('B is a proper subset of A')
    elif not countA and not countB:
        print('A and B are disjoint')
    elif countA==len(setA) and countB==len(setB) and len(setA)==len(setB):
        print('A equals B')
    else:
        print('I\'m confused!')