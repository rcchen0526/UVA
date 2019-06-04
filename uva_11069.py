ans=[0 for _ in range(4)]
ans[1], ans[2], ans[3]=1, 2, 2
for i in range(4, 77):
    ans.append(ans[i-2]+ans[i-3])
while True:
    try:
        data=int(input())
        print(ans[data])
    except:
        break