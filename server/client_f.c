
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>


#include <sys/types.h>
#include <arpa/inet.h>      //包含AF_INET相关操作的函数
#include <sys/ioctl.h>
#include <unistd.h>
#include<fcntl.h>
#include<signal.h>
#include<sys/wait.h>
#include<ctype.h>

#define PORT 6666
#define BUFFSIZE   1024

void handler(int sig)
{
    printf("recv a sig=%d\n",sig);
    exit(EXIT_SUCCESS);
}
int main()
{
    int sock_fd;
    if((sock_fd =socket(AF_INET,SOCK_STREAM,0))<0)
    {
        perror("socket");
    }
    struct sockaddr_in servaddr;
    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(connect(sock_fd,(struct sockaddr*)&servaddr,sizeof(servaddr))<0)
    {
        perror("connect");
    }
    char sendbuff[BUFFSIZE];
    char recvbuff[BUFFSIZE];
    while(fgets(sendbuff,sizeof(sendbuff),stdin)!=NULL)
    {
        write(sock_fd,sendbuff,strlen(sendbuff));
        read(sock_fd,recvbuff,sizeof(recvbuff));

        fputs(recvbuff,stdout);

        memset(sendbuff,0,sizeof(sendbuff));
        memset(recvbuff,0,sizeof(recvbuff));
    }
    close(sock_fd);
    return 0;
}
