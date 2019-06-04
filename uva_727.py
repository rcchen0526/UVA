def op2num(op):
    if op=="(":
        return 0
    elif op=="+" or op=="-":
        return 1
    else:
        return 2

op=[]
N = int(input())
temp = input()
while N:
    N=N-1
    output=''
    while True:
        try:
            input_data=input()
        except:
            break
        if len(input_data)==0:
            break
        if input_data[0]=='(':
            op.append(input_data)
        elif input_data[0]==')':
            while op[-1]!='(':
                output+=op.pop()
            op.pop()
        elif not input_data.isdigit():
            if len(op)==0 :
                op.append(input_data)
            elif (op2num(input_data) > op2num(op[-1]) ):
                op.append(input_data)
            else:
                while op2num(op[-1]) >= op2num(input_data):
                    output+=op.pop()
                    if len(op)==0:
                        break
                op.append(input_data)
        else:
            output+=input_data
    while len(op):
        output+=op.pop()
    print(output)
    if N:
        print('')
