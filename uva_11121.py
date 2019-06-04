def base_2(num):
    output=[]
    while num:
        mod=num%(-2)
        if num>0 and mod<0:
            mod=mod+2
        output.append(mod)
        num=num/(-2)
        num=int(num)
        if output[-1]<0:
            output[-1]+=2
            num+=1
    if not len(output):
        output.append(0)
    return output

input_num=input()
input_num=int(input_num)
for i in range(input_num):
    data=input()
    data=int(data)
    output=base_2(data)
    output.reverse()
    print("Case #{}: ".format(i+1), end='')
    for item in output:
        print(item, end='')
    print('')
