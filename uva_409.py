Case=0
while True:
    try:
        K, E=input().split()
        K, E=int(K), int(E)
    except:
        break
    max_num=0
    raw_data, data, keyword, excuse_num=[], [], [], []
    for _ in range(K):
        keyword.append(input())
    for _ in range(E):
        raw_data.append(input())
    for item in raw_data:
        new_word=True
        word=''
        for i in range(len(item)):
            if item[i].isalpha():
                word+=item[i].lower()
                new_word=True
                if i==len(item)-1:
                    data.append(word)
            elif new_word:
                new_word=False
                data.append(word)
                word=''
        excuse_num.append(0)
        for data_item in data:
            for keyword_item in keyword:
                if data_item==keyword_item:
                    excuse_num[-1]+=1
        max_num=max(max_num, excuse_num[-1])
        data=[]
    Case+=1
    print('Excuse Set #{}'.format(Case))
    for i in range(len(excuse_num)):
        if excuse_num[i]==max_num:
            print(raw_data[i])
    print('')