while True:
    try:
        user_input = input()
    except:
        break
    check=True
    c=None
    output_s=""
    for i in range(len(user_input)):
        if user_input[i].isalpha():
            if check:
                down_c=user_input[i].lower()
                if down_c in ['a', 'e', 'i', 'o', 'u']:
                    c=None
                    output_s+=user_input[i]
                else:
                    c=user_input[i]
                check=False
            else:
                output_s+=user_input[i]
        else:
            if not check:
                if c!=None:
                    output_s+=c
                output_s+='ay'
                check=True
            output_s+=user_input[i]

    print(output_s)
