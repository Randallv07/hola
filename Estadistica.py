import random


def mean(data):
    return sum(data)/len(data)

N=10

data = [random.randint(0,100) for _ in range (N) ]


def dev_std(data):
    prom = mean(data)
    return ((sum([(x-prom)**2 for x in data]))**0.5)/len(data)

print("Data: ", data)
print("mean; ", mean(data))
print("Desvacion estandar: ", dev_std(data))
