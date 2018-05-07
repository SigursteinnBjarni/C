#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
    struct addrinfo hints;
    struct addrinfo *result, *rp;
    int status, sfd;
    char ipstr[INET6_ADDRSTRLEN];

    if (argc < 2) {
        fprintf(stderr,"usage: hostname port\n");
        return 1;
    }

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC; // AF_INET or AF_INET6 to force version
    hints.ai_socktype = SOCK_STREAM;


    if ((status = getaddrinfo(argv[1],argv[2], &hints, &result)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return 2;
    }

    printf("IP addresses for %s:\n\n", argv[1]);
// Loop over linked list of ip numbers for host
    for(rp = result; rp != NULL; rp = rp->ai_next) {
        void *addr;
	char *ipver;
	//connect to port
	sfd = socket(rp->ai_family, rp->ai_socktype,rp->ai_protocol);
	if (connect(sfd, rp->ai_addr, rp->ai_addrlen) != -1){
		printf("Port %s open\n",argv[2]);
	}
	else {
		printf("Port %s closed\n",argv[2]);
	}
	close(sfd);
        // get the pointer to the address itself,
        // different fields in IPv4 and IPv6:
        if (rp->ai_family == AF_INET) { // IPv4
            struct sockaddr_in *ipv4 = (struct sockaddr_in *)rp->ai_addr;
            addr = &(ipv4->sin_addr);
            ipver = "IPv4";
        } else { // IPv6
            struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)rp->ai_addr;
            addr = &(ipv6->sin6_addr);
            ipver = "IPv6";
        }

        // convert the IP to a string and print it:
        inet_ntop(rp->ai_family, addr, ipstr, sizeof ipstr);
        printf("%s: %s\n", ipver, ipstr);
    }

    // free the linked list
    freeaddrinfo(result);

    return 0;
}
