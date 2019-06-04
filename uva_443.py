def create_table():
    table=[]
    table.append(1)
    it_2, it_3, it_5, it_7 = 0, 0, 0, 0
    for i in range(1, 5842):
        for _ in range(len(table)):
            if (2*table[it_2]<=table[-1]):
                it_2+=1
            else:
                break
        for _ in range(len(table)):
            if (3*table[it_3]<=table[-1]):
                it_3+=1
            else:
                break
        for _ in range(len(table)):
            if (5*table[it_5]<=table[-1]):
                it_5+=1
            else:
                break
        for _ in range(len(table)):
            if (7*table[it_7]<=table[-1]):
                it_7+=1
            else:
                break
        table.append(min(2*table[it_2], 3*table[it_3], 5*table[it_5], 7*table[it_7]) )
    return table

table=create_table()
while True:
    rank=input()
    rank=int(rank)
    if not rank:
        break
    if (rank%10)==1 and ((rank%100)>20 or (rank%100)<10):
        order="st humble number is ";
    elif (rank%10)==2 and ((rank%100)>20 or (rank%100)<10):
        order="nd humble number is ";
    elif (rank%10)==3 and ((rank%100)>20 or (rank%100)<10):
        order="rd humble number is ";
    else:
        order="th humble number is ";
    print("The {}{}{}.".format(rank, order, table[rank-1]) )
