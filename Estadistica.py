import random


def mean(data):
    return sum(data)/len(data)

N=10

data = [random.randint(0,100) for _ in range (N) ]

print("Data: ", data)
print(mean(data))
