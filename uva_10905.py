import functools
def comp(a, b):
    if a+b > b+a:
        return -1
    else:
        return 1
while True:
    num=input()
    if num=='0':
        break
    input_data=[]
    data=input()
    data = data.split()
    for item in data:
        input_data.append(item)
    input_data=sorted(input_data, key=functools.cmp_to_key(comp))
    output=""
    for item in input_data:
        output+=item
    print(output)
