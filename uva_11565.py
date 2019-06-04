num=int(input())
while num:
    num-=1
    check=True
    A, B, C=input().split()
    A, B, C=int(A), int(B), int(C)
    x=-101
    while 3*x<A and check:
        x+=1
        if not x:
            continue
        if x*x>C or B%x:
            continue
        y=x
        while x+2*y<A and check:
            y+=1
            z=A-x-y
            if y < z and x*y*z == B and x*x+y*y+z*z == C:
                check=False
                print('{} {} {}'.format(x, y, z))
    if check:
        print('No solution.')