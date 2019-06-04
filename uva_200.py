ans=[]
DAG=[[0] for _ in range(30)]
visit=[[0] for _ in range(100)]
def dfs(n):
    global ans, DAG, visit
    if visit[n]==1:
        pass
    else:
        visit[n]=1
        for item in DAG[n]:
            if visit[item] != 2:
                dfs(item)
        visit[n]=2
        ans.append(chr(n+65) )  #65 means 'A'

while True:
    try:
        l1=input()
        check=[0 for _ in range(30)]
        visit=[[0] for _ in range(100)]
        DAG=[[0] for _ in range(30)]
        for i in range(30):
            DAG[i].pop()
        ans=[]
        check[ord(l1[0])-65]=1
        while True:
            l2=input()
            if l2=="#":
                for c in range(26):
                    if check[c]==1:
                        dfs(c)
                ans=ans[::-1]
                for item in ans:
                    print(item, end='')
                print('')
                break
            else:
                l=min(len(l1), len(l2))
                for i in range(l):
                    if not check[ord(l1[i])-65]:
                        check[ord(l1[i])-65]=1
                    if not check[ord(l2[i])-65]:
                        check[ord(l2[i])-65]=1
                    if l1[i]!=l2[i]:
                        DAG[ord(l1[i])-65].append(ord(l2[i])-65)
                        check[ord(l2[i])-65]=2
                        break
                l1=l2
    except:
        break