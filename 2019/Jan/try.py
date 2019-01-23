class father:
    def __init__(self):
        print('aaaaa')
    def work(self):
        print('bbbbb')

class child(father):
    def __init__(self):
        super().__init__()
        self.a = 1
        self.b = 2
    def work(self):
        print('ccccc')

p = child
q = p()
q.work()
print(len(q.__dict__))