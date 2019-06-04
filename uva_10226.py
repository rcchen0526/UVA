from collections import OrderedDict 
num=int(input())
temp=input()
while num:
    num=num-1
    total=0.
    specy_map=OrderedDict() 
    while True:
        try:
            specy=input()
        except:
            break
        if len(specy)==0:
            break
        total=total+1.
        if specy_map.__contains__(specy):
            specy_map[specy]=specy_map[specy]+1
        else:
            specy_map[specy]=1

    for key, values in sorted(specy_map.items()):
        per="%.4f" % ((values/total)*100)
        print("{} {}".format(key, per) ) 
    if num:
        print('')