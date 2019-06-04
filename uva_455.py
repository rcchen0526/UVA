def check(s, k):
    for i in range(k):
        j=k
        while i+j<len(s):
            if s[i]!=s[i+j]:
                return False
            j+=k
    return True

num=int(input())
while num:
    num-=1
    data=input()
    data=input()
    for i in range(1, len(data)+1):
        if not len(data)%i:
            if check(data, i):
                print(i)
                if num:
                    print('')
                break