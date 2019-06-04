import math
error=1e-10
while True:
    try:
        data=input().split()
    except:
        break
    x, y, c=float(data[0]), float(data[1]), float(data[2])
    upper=min(x, y)
    lower=0
    while upper>lower:
        l=(upper+lower)/2
        c_error=math.sqrt(x*x-l*l)*math.sqrt(y*y-l*l) /\
               (math.sqrt(x*x-l*l)+math.sqrt(y*y-l*l))
        if(abs(c_error-c)<error):
            break
        if c_error<c:
            upper=l
        else:
            lower=l
    print("%.3f" % l)