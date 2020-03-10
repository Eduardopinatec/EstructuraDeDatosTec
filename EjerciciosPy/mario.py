again = False
while again == False:
    height = int(input("Height: "))
    if (height<= 8 and height>=1):
        again = True
num = height
for i in range (num):
    num-=1
    print(" "*num, end="")
    print("#"*(i+1), end ="")
    print("  ", end="")
    print("#"*(i+1))
    