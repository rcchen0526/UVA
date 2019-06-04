from collections import OrderedDict
def str2int(c):
    if c=='A' or c=='B' or c=='C':
        return '2'
    elif c=='D' or c=='E' or c=='F':
        return '3'
    elif c=='G' or c=='H' or c=='I':
        return '4'
    elif c=='J' or c=='K' or c=='L':
        return '5'
    elif c=='M' or c=='N' or c=='O':
        return '6'
    elif c=='P' or c=='R' or c=='S':
        return '7'
    elif c=='T' or c=='U' or c=='V':
        return '8'
    elif c=='W' or c=='X' or c=='Y':
        return '9'

def Std(s):
    return s[0:3]+'-'+s[3:]

num=int(input())
while num:
    num-=1
    temp=input()
    N=int(input())
    number_dict={}
    for _ in range(N):
        temp=input()
        number=''
        for i in range(len(temp)):
            if temp[i].isdigit():
                number+=temp[i]
            elif temp[i].isalpha():
                number+=str2int(temp[i])
        if number in number_dict:
            number_dict[number]+=1
        else:
            number_dict[number]=1
    number_dict=OrderedDict(sorted(number_dict.items()))
    duplicates=True
    for item in number_dict:
        if number_dict[item]>1:
            duplicates=False
            print(Std(item), number_dict[item])
    if duplicates:
        print('No duplicates.')
    if num:
        print('')