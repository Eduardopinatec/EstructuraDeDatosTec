a = int(input("Dame un año: "))
if (a%4 == 0):
    if (a%100 == 0):
        if (a%400 == 0):
            print("Es año bisiesto", end="")
        else:
            print("No es año bisiesto", end="")
    else:
        print("Es año bisiesto", end="")
else:
    print("No es año bisiesto")