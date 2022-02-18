#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void error(const char *msg){
	perror(msg);
	exit(1);	
}

int main(int argc, char *argv[]){  		// argv[0] nombre del archivo
										// argv[1] direccion ip del servidor
										// argv[2] numero de puerto
	int sockfd, portno, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;

	char buffer[255];
	if(argc < 3){
		fprintf(stderr, "Usando el puerto %s\n", argv[0]);
		exit(1);
	}

	portno = atoi(argv[2]); // Convertimos la cadena a su valor entero
	sockfd = socket(AF_INET, SOCK_STREAM, 0); // Creamos el socket
	if(sockfd < 0)
		error("Error al abrir el socket");

	server = gethostbyname(argv[1]); // Obtenenos los datos del servidor
	if(server == NULL)
		fprintf(stderr, "Error, el host no existe");

	bzero((char *) &serv_addr, sizeof(serv_addr)); // Borramos el area de memoria
	serv_addr.sin_family = AF_INET;
	bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length); // Copiamos enl numero de bytes
	serv_addr.sin_port = htons(portno); // Damos informacion sobre el puerto
	if(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) // Nos concetamos con el servidor
		error("La conexion fallo");

	while(1){
		bzero(buffer, 255);
		fgets(buffer, 255, stdin);
		n = write(sockfd, buffer, strlen(buffer));
		if(n < 0)
			error("Error on la escritura");
		
		bzero(buffer, 255);
		n = read(sockfd, buffer, 255);
		if(n < 0)
			error("Error en la lectura");
		printf("Servidor: %s", buffer);

		int i = strncmp("Adios", buffer, 5);
		if(i == 0)
			break;
	}

	close(sockfd); // Cerramos el descriptor de archivo
	return 0;

}