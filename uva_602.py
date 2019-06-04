def decide_days(Y, M):
    if M==1 or M==3 or M==5 or M==7 or M==8 or M==10 or M==12:
        return 31
    elif M==4 or M==6 or M==9 or M==11:
        return 30
    elif M==2:
        day=28
        if Y<=1752:
            day+=0 if Y%4 else 1
            return day
        else:
            day+=0 if Y%4 else 1
            day-=0 if Y%100 else 1
            day+=0 if Y%400 else 1
            return day
    else:
        return 0
Month_voc={1:"January", 2:"February", 3:"March", 4:"April", 5:"May", 6:"June", \
7:"July", 8:"August", 9:"September", 10:"October", 11:"November", 12: "December" }

Day_voc={0:"Sunday", 1:"Monday", 2:"Tuesday", 3:"Wednesday", 4:"Thursday", 5:"Friday", 6:"Saturday"}

while True:
    try:
        input_data=input()
    except:
        break
    M, D, Y = input_data.split()
    M, D, Y = int(M), int(D), int(Y)
    if not M and not D and not Y:
        break
    if Y==1752 and M==9 and D>2 and D<14:
        print("{}/{}/{} is an invalid date.".format(M, D, Y))
    else:
        if not decide_days(Y, M):
            print("{}/{}/{} is an invalid date.".format(M, D, Y))
        elif decide_days(Y, M)-D < 0:
            print("{}/{}/{} is an invalid date.".format(M, D, Y))
        else:
            output=6
            output+=Y-1
            for i in range(1, M):
                output+=decide_days(Y, i)
            output+=D-1
            output+=int((Y-1)/4)
            if Y==1752:
                if M==9 and D>13:
                    output-=4
                elif M>9:
                    output-=4
            elif Y>1752:
                output-=4
                output-=int((Y-1701)/100)
                output+=int((Y-1601)/400)
            output%=7
            print("{} {}, {} is a {}".format(Month_voc[M], D, Y, Day_voc[output]) )

