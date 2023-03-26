/* 
 * -------------------------------------------------
 * Port Scanner given an IP address and a port range
 * -------------------------------------------------
 * Project done by Manittas
 * -------------------------------------------------
 */

#include "Header.h"

arguments_t *arguments;
struct addrinfo *server_add = NULL;
int sockfd = 0;

// Signal handling, closes the script safely
void close_script(int status) {

   // Closes socket and server if open
   freeaddrinfo(server_add);
   close(sockfd);

   // Prints message
   fprintf(stderr,"\nClosing script..\n");
   exit(status);
}

// Scanning function
void scanner(void) {

   // Iteration argument
   int port = 0;
   
   // Iterates through each port
   for(port = arguments->first_port; port <= arguments->last_port; port++) {

      // Networking variables from netdb
      struct addrinfo hints;
      memset(&hints, 0, sizeof(hints));
      hints.ai_family = AF_INET;
      hints.ai_socktype = SOCK_STREAM;

      // Convert port to char to ask for network info
      char port_value[6]={0};
      sprintf(port_value, "%d", port);

      // Checks if addrinfo is reachable and tries to get the connection of the port
      if(getaddrinfo(arguments->IP, port_value, &hints, &server_add) == 0) {

         struct addrinfo *temp = NULL;
         int status = 0;

         for(temp = server_add; temp != NULL; temp = temp->ai_next) {

            // Checks socket
            sockfd = socket(temp->ai_family, temp->ai_socktype, temp->ai_protocol);
            if(sockfd < 0) {
               printf("Port %d Closed.\n", port);
               continue;
            }

            // Checks connection
            status = connect(sockfd, temp->ai_addr, temp->ai_addrlen);
            if(status < 0) {
               printf("Port %d Closed.\n", port);
               close(sockfd);
               continue;
            }

            // Connection done with success, tells the port is open
            printf("Port %d OPEN.\n", port);
            close(sockfd);
         }

         freeaddrinfo(server_add);
      } else {

         // Frees address and says Port is not available
         freeaddrinfo(server_add);
         printf("Port %d Closed.\n", port);
      }
   }
}

// main function
int main(int argc, char *argv[]) {

   // Signal handling for anytime the script is closed (Ctrl + C)
   signal(SIGINT, close_script);

   printf("-------------------------\n");
   printf(">> Port Scanner Script <<\n");
   printf("-------------------------\n");

   // Check if correct number of arguments were given and ends in case not
   if(argc != 4) {
      fprintf(stderr, "ERROR <PortScanner.c>: Incorrect number of arguments given. Provide: <IPv4> <First_Port> <Last_Port>\n");
      return -1;
   }

   // Allocate size for the structure containing the IP and Ports
   arguments = (arguments_t*)malloc(sizeof(arguments_t));

   // Copy values of the args to respective arguments and verify if they are in correct length
   if(strlen(argv[1]) > 16 || strlen(argv[2]) > 6 || strlen(argv[3]) > 6) {
      fprintf(stderr, "ERROR <PortScanner.c>: Incorrect argument values. maximum 16 chars for IP address and 6 chars for Ports.\n");
      return -1;
   }

   strcpy(arguments->IP, argv[1]);
   arguments->first_port = atoi(argv[2]);
   arguments->last_port = atoi(argv[3]);

   // Calls scanning function
   scanner();
   
   return 0;
}