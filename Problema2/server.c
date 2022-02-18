#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Funcion de error que termina el programa
void error(const char *msg){
	perror(msg);
	exit(1);	
}

int main(int argc, char *argv[]){ // Ocupamos de dos parametros, el nombre del archivo y el numero de puerto

	// En caso de que no nos de el puerto
	if(argc < 2){
		fprintf(stderr, "Numero de puerto no valido\n");
		exit(1);
	}

	int sockfd, newsockfd, portno, n;
	char buffer[255];

	// Proporciona informacion sobre la direccion de internet
	struct sockaddr_in serv_addr, cli_addr;
	socklen_t clilen;

	sockfd = socket(AF_INET, SOCK_STREAM, 0); // Creamos el socket
	if(sockfd < 0)
		error("Error al abrir el Socket");

	bzero((char *) &serv_addr, sizeof(serv_addr)); // Borramos el area de memoria
	portno = atoi(argv[1]); // Convertimos la cadena a su valor numerico

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);

	// Asignamos una direccion local del socket
	if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
		error("Enlace fallido");

	// Escuchamos quien esta tratando de conectarse al mismo puerto
	listen(sockfd, 5);
	clilen = sizeof(cli_addr);

	// Aceptamos la conexion
	newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

	if(newsockfd < 0)
		error("Error en la aceptacion");

	int num, ans;
	
	S : n = write(newsockfd, "Introduzca un numero: ", strlen("Introduzca un numero: "));
	if(n < 0)
		error("Error al escribir al socket");
	read(newsockfd, &num, sizeof(int));
	printf("Cliente - Numero 1 es: %d\n", num);

	if(num == 0)
		goto Q;

	ans = num+1;

	write(newsockfd, &ans, sizeof(int));

	if(num != 0)
		goto S;

	Q : close(newsockfd);
	close(sockfd);
	return 0;
}