while True:
    num=int(input())
    if not num:
        break
    MAX, ans=1, 0
    Map={}
    while num:
        num-=1
        data=input().split()
        data.sort()
        temp=''
        for item in data:
            temp+=item
        try:
            Map[temp]+=1
            MAX=Map[temp] if Map[temp]>MAX else MAX
        except:
            Map[temp]=1
    for item in Map.values():
        if MAX==item:
            ans+=item
    print(ans)
