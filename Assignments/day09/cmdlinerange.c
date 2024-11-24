#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_NAME_LEN 40

struct server {
    char *name;
    char *ip;
    unsigned short port;
};

void display(struct server *srv) {
    printf("Server Name: %s\nIP Address: %s\nPort: %hu\n", srv->name, srv->ip, srv->port);
}

int valid_ip(char *ip) {
    struct sockaddr_in sa;
    return inet_pton(AF_INET, ip, &(sa.sin_addr)) != 0;
}

int valid_port(unsigned short port) {
    return port >= 0 && port <= 65535;
}

int update(struct server *srv) {
    char input[256];

    printf("Update server configuration? (y/n): ");
    fgets(input, sizeof(input), stdin);
    if (input[0] != 'y') return 0;

    printf("New server name (max %d chars): ", MAX_NAME_LEN);
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    if (strlen(input) <= MAX_NAME_LEN) {
        free(srv->name);
        srv->name = strdup(input);
    }

    printf("New IP address: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    if (valid_ip(input)) {
        free(srv->ip);
        srv->ip = strdup(input);
    }

    printf("New port: ");
    fgets(input, sizeof(input), stdin);
    unsigned short port = (unsigned short)atoi(input);
    if (valid_port(port)) srv->port = port;

    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Error: Provide 3 arguments (name, IP, port).\n");
        return 1;
    }

    if (strlen(argv[1]) > MAX_NAME_LEN) {
        printf("Error: Name too long.\n");
        return 1;
    }

    if (!valid_ip(argv[2])) {
        printf("Error: Invalid IP address.\n");
        return 1;
    }

    unsigned short port = (unsigned short)atoi(argv[3]);
    if (!valid_port(port)) {
        printf("Error: Invalid port number.\n");
        return 1;
    }

    struct server srv;
    srv.name = strdup(argv[1]);
    srv.ip = strdup(argv[2]);
    srv.port = port;

    display(&srv);

    if (update(&srv)) {
        printf("Updated configuration:\n");
        display(&srv);
    }

    free(srv.name);
    free(srv.ip);
    return 0;
}

