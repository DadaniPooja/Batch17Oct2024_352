#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 80

char *getUser(char []);
char *getHost(char []);
char *getDomain(char []);
int isValidDomain(char []);

int main() {
    char email[MAX];

    printf("Enter email ID: ");
    fgets(email, MAX, stdin);
    email[strcspn(email, "\n")] = '\0';

    char *username = getUser(email);
    char *host = getHost(email);
    char *domain = getDomain(email);

    if (username != NULL)
        printf("Username: %s\n", username);
    else
        printf("Invalid username.\n");

    if (host != NULL)
        printf("Host: %s\n", host);
    else
        printf("Invalid host.\n");

    if (domain != NULL)
        printf("Domain: %s\n", domain);
    else
        printf("Invalid domain.\n");

    if (isValidDomain(email))
        printf("Valid domain.\n");
    else
        printf("Invalid domain.\n");

    return 0;
}

char *getUser(char a[]) {
    static char user[MAX];
	int len;
    char *at = strchr(a, '@'); 
    
    if(at==NULL) 
        return NULL; 
    
    len=at-a;
    if(len>0)
	{
        strncpy(user, a, len);
        user[len] = '\0';
        return user;
    }
    else
        return NULL; 
}

char *getHost(char a[]) {
    static char host[MAX];
	char *dot;
	int len;
    char *at = strchr(a, '@'); 
    if(at==NULL) 
        return NULL; 
   
    dot=strchr(at+1,'.');
    if(dot==NULL)
        return NULL; 
    
    len=dot-(at+1);
    strncpy(host,at+1,len);
    host[len] = '\0'; 
    return host;
}

char *getDomain(char a[]) {
    static char domain[MAX];
    char *dot = strrchr(a, '.');
    if(dot==NULL || strlen(dot)<4)
        return NULL;  

    strcpy(domain, dot + 1);
    
    if (strcmp(domain, "com") == 0 || strcmp(domain, "edu") == 0)
        return domain;
    else
        return NULL;
}

int isValidDomain(char a[]) {
    char *domain = getDomain(a);
    return (domain != NULL);
}

