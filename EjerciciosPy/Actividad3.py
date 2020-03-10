cantidad = int(0)
frase = input("Dame una frase: ")
palabra = input("Que palabra deseas buscar: ")
if palabra in frase:
    cantidad += 1
print(f"La palabra {palabra} aparece {cantidad} veces.", end="")