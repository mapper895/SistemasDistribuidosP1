# Sistemas Distribuidos Práctica 1 - Introducción al Manejo de Sockets

## Problema 1
Codifique dos programas usando sockets, en el enfoque cliente-servidor, que
permita el intercambio de mensajes de texto.
- El programa Servidor debe ser codificado en java
- El cliente debe ser codificado en C

### Funcionamiento
Cuando se conecten entre si, el cliente enviará una cadena de
texto cualquiera, por ejemplo Hola y el Servidor debe responder con algún otro
mensaje, por ejemplo, Hola que tal

Para compilar el servidor se utiliza el comando
```sh
javac Server.java
```
Para correr el servidor se ocupa el comando
```sh
java Server <numerodepuerto>
# Por ejemplo
java Server 5000
```
Mientras que para el lado del cliente, para compilarlo se ocupa el comando
```sh
gcc client.c -o client
```
Para ejecutar el cliente, se ocupa el comando
```sh
./client <host> <numerodepuerto>
# Por ejemplo
./client 127.0.0.1 5000
```

## Problema 2
Codifique dos programas usando sockets, en el enfoque cliente-servidor, que
permita que se envien números enteros entre si.
- El programa Servidor debe ser codificado en C
- El programa cliente debe ser codificado en Java

### Funcionamiento
Cuando se conecten entre si, el cliente enviará un entero y el
servidor lo incrementara en uno. Ejemplo, el cliente envía un 5 y el servidor
contestará con un 6, el programa terminara cuando el cliente escriba un cero.

Para compilar el servidor se utiliza el comando
```sh
gcc server.c -o server
```
Para correr el servidor se ocupa el comando
```sh
./server <numerodepuerto>
# Por ejemplo
./server 5000
```
Mientras que para el lado del cliente, para compilarlo se ocupa el comando
```sh
javac Client.java
```
Para ejecutar el cliente, se ocupa el comando
```sh
java Client <host> <numerodepuerto>
# Por ejemplo
java Client 127.0.0.1 5000
```
