try:
    with open('in1.txt', 'r') as fin:
        a = fin.read()
        print('fasfasdf')
except FileNotFoundError:
    pass
else:
    print(a)

print('fdadfa')