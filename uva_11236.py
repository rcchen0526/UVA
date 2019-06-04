i=8
while i*i*i*i<2e9:
    j=i
    while j*j*j<2e9/i:
        k=j
        while k*k<2e9/(i*j):
            if i*j*k>1e6:
                m=int(1e6*(i+j+k)/(i*j*k-1e6))
                if k<=m and i+j+k+m<=2000 and 1000000*(i+j+k+m)==i*j*k*m:
                    print('{:.2f} {:.2f} {:.2f} {:.2f}'\
                        .format(0.01*i, 0.01*j, 0.01*k, 0.01*m))
            k+=1
        j+=1
    i+=1