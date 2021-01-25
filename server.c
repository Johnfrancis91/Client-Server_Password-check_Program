// defines in_addr structure 
#include <arpa/inet.h> 

// contains constants and structures 
// needed for internet domain addresses 
#include <netinet/in.h> 

// standard input and output library 
#include <stdio.h> 

// contains string functions 
#include <string.h> 

// for socket creation 
#include <sys/socket.h> 

// contains constructs that facilitate getting 
// information about files attributes. 
#include <sys/stat.h> 

// contains a number of basic derived types 
// that should be used whenever appropriate 
#include <sys/types.h> 
#include<time.h>

void waitFor (unsigned int secs) 
{
	    unsigned int retTime = time(0) + secs;   // Get finishing time.
    	while (time(0) < retTime);               // Loop until it arrives.
}
main() 
{ 
	struct sockaddr_in client, server; 
	int s, n, sock,flag; 
	char b1[20]; 
	char password [] ="johnfrancis";

	// creating socket 
	s = socket(AF_INET, SOCK_STREAM, 0); 

	// assign IP, PORT 
	server.sin_family = AF_INET; 

	// this is the port number of running server 
	server.sin_port = 2000; 
	server.sin_addr.s_addr = inet_addr("127.0.0.1"); 

	// Binding newly created socket 
	// to given IP and verification 
	bind(s, (struct sockaddr*)&server, sizeof server); 
	listen(s, 1); 
	n = sizeof(client); 
	sock = accept(s, (struct sockaddr*)&client, &n); 
	recv(sock, b1, sizeof(b1), 0); 

		// whenever a request from a client came. 
		// It will be processed here. 
		printf("\nThe string received is:%s\n", b1); 
		if ((strcmp(password,b1)) == 0) 
		{
			flag = 1;
			send(sock, &flag, sizeof(int), 0); 
			waitFor(10);
		}	 
		else 
		{
			flag =0;
			send(sock, &flag, sizeof(int), 0); 

		} 

	// close the socket 
	close(sock); 
	close(s); 
} 
