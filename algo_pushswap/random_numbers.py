
import random as prng

n = int(input("Number of unique random numbers: "))

numbers = []

rand = prng.randint(0, n - 1)
numbers.append(rand)

for i in range(0, n - 1):
    while rand in numbers:
        rand = prng.randint(0, n - 1)
    numbers.append(rand)

print "ARG=\"",
for i in range(0, n):
    print numbers[i],
print "\"; ./push_swap $ARG | ./checker $ARG",
