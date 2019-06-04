data, stack, ans=[], [], []
t=0
def comp(a, b):
    global data
    if len(a)!=len(b):
        return True
    for i in range(len(a)):
        if data[a[i]]!=data[b[i]]:
            return True
    return False

def comb(curi):
    global data, stack, ans, t
    ans_temp=0
    for i in range(len(stack)):
        ans_temp+=data[stack[i]]
    if ans_temp==t:
        check=True
        for item in ans:
            check=comp(item, stack)
            if not check:
                return 0
        if check:
            ans.append(stack)
        return 0
    elif curi>=len(data) or ans_temp>t:
        return 0
    stack.append(curi)
    comb(curi+1)
    stack=stack[:-1]
    comb(curi+1)

while True:
    try:
        input_s=input().split()
    except:
        break
    t, n=int(input_s[0]), int(input_s[1])
    if not t and not n:
        break
    data, stack, ans=[], [], []
    for i in range(2, len(input_s)):
        data.append(int(input_s[i]))
    comb(0)
    print("Sums of {}:".format(t))
    for List in ans:
        for i in range(len(List) ):
            print(data[List[i]], end='')
            if i!=len(List)-1:
                print('+', end='')
        print('')
    if len(ans)==0:
        print('NONE')
