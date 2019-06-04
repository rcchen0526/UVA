days=[0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
months=["", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"]
def Find_Month(m):
    for i in range(1, 13):
        if m==months[i]:
            return i
    return 0
def leap(Y):
    day=0
    day+=0 if Y%4 else 1
    day-=0 if Y%100 else 1
    day+=0 if Y%400 else 1
    return day

num=int(input())
for N in range(num):
    data=input()
    add=int(input())
    year, day=0, 0
    M=''
    for i in range(4):
        year*=10
        year+=int(data[i])
    for i in range(5, len(data)-3):
        M+=data[i]
    month=Find_Month(M)
    for i in range(len(data)-2, len(data)):
        day*=10
        day+=int(data[i])
    while add:
        while month<=12 and add:
            l=days[month]
            if month==2:
                l+=leap(year)
            day+=1
            while day<=l:
                add-=1
                if not add:
                    print('Case {}: {}-{}-{:0>2}'.format(N+1, year, months[month], day))
                    break
                day+=1
            day=0
            month+=1
        month=1
        year+=1

