#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Socket header files
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    struct hostent *host;       // hostent: host entry structure
    struct in_addr addr;        // in_addr: IPv4 address structure

    // Check command line arguments
    if (argc < 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    host = gethostbyname(argv[1]); // get host information
    if (!host) {
        printf("gethostbyname error\n");
        exit(1);
    }

    printf("Official name: %s\n", host->h_name);
    for (int i = 0; host->h_aliases[i]; i++) { // Aliases
        printf("Aliases %d: %s\n", i + 1, host->h_aliases[i]);
    }

    printf("Address type: %s\n", (host->h_addrtype == AF_INET) ? "AF_INET" : "AF_INET6");
    for (int i = 0; host->h_addr_list[i]; i++) { // IP addresses
        memcpy(&addr, host->h_addr_list[i], sizeof(struct in_addr));
        printf("IP addr %d: %s\n", i + 1, inet_ntoa(addr));
    }

    return 0;
}