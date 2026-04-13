#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Function to scan a single port
int scan_port(const char *ip, int port)
{
    int sock;
    struct sockaddr_in target;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        printf("Socket creation failed\n");
        return -1;
    }

    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    target.sin_addr.s_addr = inet_addr(ip);

    int result = connect(sock, (struct sockaddr *)&target, sizeof(target));

    close(sock);

    if (result == 0)
        return 1; // OPEN
    else
        return 0; // CLOSED
}

int main()
{
    const char *target_ip = "127.0.0.1";
    int ports[] = {22, 80, 443, 3306};
    int num_ports = sizeof(ports) / sizeof(ports[0]);

    printf("Scanning %s...\n\n", target_ip);

    for (int i = 0; i < num_ports; i++)
    {
        int status = scan_port(target_ip, ports[i]);

        if (status == 1)
            printf("Port %d: OPEN\n", ports[i]);
        else
            printf("Port %d: CLOSED\n", ports[i]);
    }

    return 0;
}