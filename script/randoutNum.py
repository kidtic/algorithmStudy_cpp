import random
 
print("[")
for line in range(0,1000):
    s=""
    for i in range(0,40):
        s=s+str(random.randint(0,100000))+","
    print(s)
print("0]")

