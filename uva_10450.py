f=[1, 1]
for i in range(2, 55):
    f.append(f[i-1]+f[i-2])
Case=int(input())
for i in range(Case):
    n=int(input())
    print("Scenario #{}:".format(i+1))
    print(f[n+1])
    print('')