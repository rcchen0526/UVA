import math
def prime_list(Max):
    prime=[]
    for i in range(1, Max+1):
        check_prime=True
        for j in range(2, int(math.sqrt(i))+1 ):
            if not i%j:
                check_prime=False
                break
        if check_prime:
            prime.append(i)
    return prime

while True:
    try:
        input_data= input()
    except:
        break
    Max, Mid = input_data.split()
    Max, Mid = int(Max), int(Mid)
    print("{} {}:".format(Max, Mid), end='')
    ans = prime_list(Max)
    if 2*Mid >= len(ans):
        for i in ans:
            print(" {}".format(i), end='')
        print('')
    else:
        ans_mid = int(len(ans)/2)
        start = ans_mid-Mid+(len(ans)%2)
        end = ans_mid+Mid-1
        for i in range(start, end+1):
            print(" {}".format(ans[i]), end='')
        print('')
    print('')
