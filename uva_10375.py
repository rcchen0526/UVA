while True:
    try:
        input_s=input().split()
    except:
        break
    data=[]
    for item in input_s:
        data.append(float(item))
    if data[1]>data[0]/2:
        data[1]=data[0]-data[1]
    if data[3]>data[2]/2:
        data[3]=data[2]-data[3]
    index=0
    ans=1.
    while index<data[1] or index<data[3]:
        if index<data[1]:
            ans=ans*float(data[0]-index)/float(1+index)
        if index<data[3]:
            ans=ans/float(data[2]-index)*float(1+index)
        index+=1
    ans='%.5f'%ans
    print(ans)