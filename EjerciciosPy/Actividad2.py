n = int(input("Cuantos numeros deseas sumar: "))
sum = int(0)
for i in range(n):
    num=int(input("Dame un numero: "))
    sum = sum+num
sum = sum/n
print(f"El promedio de los numeros dados es: {sum}", end="")