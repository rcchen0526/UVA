stack=[]
paper=[]
def comb(n, curi):
    global stack, paper
    if n==len(stack):
        for i in range(len(stack)):
            print(paper[stack[i]], end='')
            if i!=len(stack)-1:
                print(", ", end='')
        print('')
        return 0
    elif curi>=len(paper):
        return 0
    stack.append(curi)
    comb(n, curi+1)
    stack=stack[:-1]
    comb(n, curi+1)

num=int(input())
temp=input()
while num:
    num-=1
    stack=[]
    paper=[]
    r1, r2=-1, -1
    data=input().split()
    if data[0]=='*':
        r1=0
    elif len(data)==1:
        r1=r2=int(data[0])
    else:
        r1, r2=int(data[0]), int(data[1])
    while True:
        try:
            input_s=input()
        except:
            break
        if len(input_s)==0:
            break
        paper.append(input_s)
    if r1==0:
        r1, r2=1, len(paper)
    for i in range(r1, r2+1):
        print("Size {}".format(i))
        comb(i, 0)
        print('')
    if num:
        print('')
