import os
import signal
import random

class agendaV2:
    def menu(self):
        salir = "negativo"
        while salir != "afirmativo":
            print("Contactos actualmente cargados a la agenda: \n")
            with open("file01.txt", "r") as f:
                for contacto_cifrado in f:
                    print(self.descifrar_contacto(contacto_cifrado.strip()))
            print("\n____________________________________________________")
            print("Menú de opciones, qué deseas realizar?")
            print("1) Añadir contacto     2) Eliminar contacto     3) Modificar dato")
            opcion = input("Ingresa una opción: ")
            if opcion == "1":
                self.agregar_contacto()
            elif opcion == "2":
                self.eliminar_contacto()
            elif opcion == "3":
                self.modificar_contacto()
            elif opcion == "4":
                self.salir()
                salir = "afirmativo"
            else:
                print("Opción inválida, por favor intenta de nuevo.")

    def salir(self):
        print("Encpriptando tu información antes de cerrar...")
        cipher = VigenereCipher("Llavesecreta")
        infoEncriptada = open("file01.txt", "r")
        variable = infoEncriptada.read()
        infoEncriptada.close()
        ciphertext = cipher.encrypt(variable)
        infoEncriptada = open("file01.txt", "w")
        infoEncriptada.write(ciphertext)
        infoEncriptada.close()
    def agregar_contacto(self):
        nombre = input("Ingresa el nombre del contacto: ")
        telefono = input("Ingresa el teléfono del contacto: ")
        email = input("Ingresa el email del contacto: ")

        # Cifrar los datos del contacto usando el método César
        nombre_cifrado = ""
        for letra in nombre:
            if letra.isalpha():
                nueva_letra = chr((ord(letra.lower()) - 96 + 1) % 26 + 96)
                if letra.isupper():
                    nombre_cifrado += nueva_letra.upper()
                else:
                    nombre_cifrado += nueva_letra
            else:
                nombre_cifrado += letra

        telefono_cifrado = ""
        for letra in telefono:
            if letra.isnumeric():
                nueva_letra = str((int(letra) + 1) % 10)
                telefono_cifrado += nueva_letra
            else:
                telefono_cifrado += letra

        email_cifrado = ""
        for letra in email:
            if letra.isalpha():
                nueva_letra = chr((ord(letra.lower()) - 96 + 1) % 26 + 96)
                if letra.isupper():
                    email_cifrado += nueva_letra.upper()
                else:
                    email_cifrado += nueva_letra
            else:
                email_cifrado += letra

        contacto = f"{nombre_cifrado},{telefono_cifrado},{email_cifrado}"
        with open("file01.txt", "a") as f:
            f.write(contacto + "\n")
        print("Contacto agregado exitosamente.")

    def eliminar_contacto(self):
        nombre = input("Ingresa el nombre del contacto que deseas eliminar: ")
        lineas = []
        with open("file01.txt", "r") as f:
            for linea in f:
                # Descifrar el nombre del contacto usando el método César
                nombre_cifrado = linea.split(",")[0]
                nombre_descifrado = ""
                for letra in nombre_cifrado:
                    if letra.isalpha():
                        nueva_letra = chr((ord(letra.lower()) - 96 - 1) % 26 + 96)
                        if letra.isupper():
                            nombre_descifrado += nueva_letra.upper()
                        else:
                            nombre_descifrado += nueva_letra
                    else:
                        nombre_descifrado += letra

                if not nombre_descifrado.startswith(nombre):
                    lineas.append(linea)
        with open("file01.txt", "w") as f:
            for linea in lineas:
                f.write(linea)
        print("Contacto eliminado exitosamente.")



    def modificar_contacto(self):
        nombre = input("Ingresa el nombre del contacto que deseas modificar: ")

        # Cifrar el nombre del contacto para encontrar coincidencia
        nombre_descifrado = ""
        for letra in nombre:
            if letra.isalpha():
                nueva_letra = chr((ord(letra.lower()) - 96 + 1) % 26 + 96)
                if letra.isupper():
                    nombre_descifrado += nueva_letra.upper()
                else:
                    nombre_descifrado += nueva_letra
            else:
                nombre_descifrado += letra
        nuevo_nombre = input("Ingresa el nuevo nombre del contacto (deja en blanco para mantener el mismo): ")
        nuevo_telefono = input("Ingresa el nuevo teléfono del contacto (deja en blanco para mantener el mismo): ")
        nuevo_email = input("Ingresa el nuevo email del contacto (deja en blanco para mantener el mismo): ")

        # Cifrar los datos del contacto usando el método César
        nuevo_nombre_cifrado = ""
        for letra in nuevo_nombre:
            if letra.isalpha():
                nueva_letra = chr((ord(letra.lower()) - 96 + 1) % 26 + 96)
                if letra.isupper():
                    nuevo_nombre_cifrado += nueva_letra.upper()
                else:
                    nuevo_nombre_cifrado += nueva_letra
            else:
                nuevo_nombre_cifrado += letra

        nuevo_telefono_cifrado = ""
        for letra in nuevo_telefono:
            if letra.isnumeric():
                nueva_letra = str((int(letra) + 1) % 10)
                nuevo_telefono_cifrado += nueva_letra
            else:
                nuevo_telefono_cifrado += letra

        nuevo_email_cifrado = ""
        for letra in nuevo_email:
            if letra.isalpha():
                nueva_letra = chr((ord(letra.lower()) - 96 + 1) % 26 + 96)
                if letra.isupper():
                    nuevo_email_cifrado += nueva_letra.upper()
                else:
                    nuevo_email_cifrado += nueva_letra
            else:
                nuevo_email_cifrado += letra

        lineas = []
        with open("file01.txt", "r") as f:
            for linea in f:
                if not linea.startswith(nombre_descifrado + ","):
                    lineas.append(linea)
                else:
                    partes = linea.strip().split(",")
                    if nuevo_nombre == "":
                        nuevo_nombre_cifrado = partes[0]
                    if nuevo_telefono == "":
                        nuevo_telefono_cifrado = partes[1]
                    if nuevo_email == "":
                        nuevo_email_cifrado = partes[2]
                    nuevo_contacto = f"{nuevo_nombre_cifrado},{nuevo_telefono_cifrado},{nuevo_email_cifrado}"
                    lineas.append(nuevo_contacto + "\n")
        with open("file01.txt", "w") as f:
            for linea in lineas:
                f.write(linea)
        print("Contacto modificado exitosamente.")

    def descifrar_contacto(self, contacto_cifrado):
        # Descifrar los datos del contacto usando el método César
        nombre_descifrado = ""
        for letra in contacto_cifrado.split(",")[0]:
            if letra.isalpha():
                nueva_letra = chr((ord(letra.lower()) - 96 - 1) % 26 + 96)
                if letra.isupper():
                    nombre_descifrado += nueva_letra.upper()
                else:
                    nombre_descifrado += nueva_letra
            else:
                nombre_descifrado += letra

        telefono_descifrado = ""
        for letra in contacto_cifrado.split(",")[1]:
            if letra.isnumeric():
                nueva_letra = str((int(letra) - 1) % 10)
                telefono_descifrado += nueva_letra
            else:
                telefono_descifrado += letra

        email_descifrado = ""
        for letra in contacto_cifrado.split(",")[2]:
            if letra.isalpha():
                nueva_letra = chr((ord(letra.lower()) - 96 - 1) % 26 + 96)
                if letra.isupper():
                    email_descifrado += nueva_letra.upper()
                else:
                    email_descifrado += nueva_letra
            else:
                email_descifrado += letra

        # Mostrar el contacto descifrado en pantalla
        contacto = "Nombre: " + nombre_descifrado + "\n" +"Telefono: "+ telefono_descifrado + "\n" +"Correo electronico: " + email_descifrado + "\n"
        return contacto


class VigenereCipher:
    def __init__(self, key):
        self.key = key

    def encrypt(self, plaintext):
        ciphertext = ""
        key_idx = 0
        for c in plaintext:
            if c.isalpha():
                key_char = self.key[key_idx % len(self.key)]
                cipher_offset = ord(key_char.upper()) - ord('A')
                cipher_row = ""
                for i in range(26):
                    cipher_row += chr((i + cipher_offset) % 26 + ord('A'))
                if c.isupper():
                    ciphertext += cipher_row[ord(c) - ord('A')]
                else:
                    ciphertext += cipher_row[ord(c) - ord('a')].lower()
                key_idx += 1
            else:
                ciphertext += c
        return ciphertext

    def decrypt(self, ciphertext):
        plaintext = ""
        key_idx = 0
        for c in ciphertext:
            if c.isalpha():
                key_char = self.key[key_idx % len(self.key)]
                cipher_offset = ord(key_char.upper()) - ord('A')
                cipher_row = ""
                for i in range(26):
                    cipher_row += chr((i + cipher_offset) % 26 + ord('A'))
                if c.isupper():
                    plaintext += chr(cipher_row.index(c) + ord('A'))
                else:
                    plaintext += chr(cipher_row.index(c.upper()) + ord('a')).lower()
                key_idx += 1
            else:
                plaintext += c
        return plaintext

myAgenda = agendaV2()

vigenere = VigenereCipher("Llavesecreta")
infoEncriptada = open("file01.txt", "r")
guardarDatos = infoEncriptada.read()
infoEncriptada.close()
guardarDatos = vigenere.decrypt(guardarDatos)
infoEncriptada = open("file01.txt", "w")
infoEncriptada.write(guardarDatos)
infoEncriptada.close()

myAgenda.menu()

