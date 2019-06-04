def str2int(s):
    start, Sum=1, 0
    for i in range(len(s)):
        if ord(s[i])>=ord('0') and ord(s[i])<=ord('9'):
            if ord(s[i])-ord('0')>start:
                start=ord(s[i])-ord('0')
            Sum+=ord(s[i])-ord('0')
        elif ord(s[i])>=ord('A') and ord(s[i])<=ord('Z'):
            if ord(s[i])-ord('A')+10>start:
                start=ord(s[i])-ord('A')+10
            Sum+=ord(s[i])-ord('A')+10
        if ord(s[i])>=ord('a') and ord(s[i])<=ord('z'):
            if ord(s[i])-ord('a')+36>start:
                start=ord(s[i])-ord('a')+36
            Sum+=ord(s[i])-ord('a')+36
    return start, Sum
while True:
    try:
        input_s=input()
    except:
        break
    start, Sum=str2int(input_s)
    for i in range(start, 62):
        if not Sum%i:
            print(i+1)
            break
        elif i==61:
            print("such number is impossible!")