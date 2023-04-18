import random
import turtle

t = turtle.Turtle()
times = random.randint(1, 50)
for x in range(0, times):
    t.lt(random.randint(0, 18) * 10)
    t.fd(random.randint(1, 9) * 10)

input()
