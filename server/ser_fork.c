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
#include<ctype.h>

#define MAXLINE 1024
#define BACKLOG  10
#define PORT    6666

void  service(int fd);

int main()
{
    signal(SIGCHLD,SIG_IGN);
    int sockfd,connfd,n;
    char buf[MAXLINE];

    struct sockaddr_in servaddr;
    pid_t pid;
    sockfd = socket(AF_INET,SOCK_STREAM,0);

    if(sockfd<0)
    {
        perror("sockfd error:");
        exit(0);
    }
    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    int on =1;
    if(setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on))<0)
    {
        perror("setsockopt:");
        exit(0);
    }
    if(bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr))<0)
    {
        perror("bind");
        exit(0);
    }
    if(listen(sockfd,BACKLOG)<0)
    {
        perror("listen");
        exit(0);
    }
    struct sockaddr_in cli_addr;
    socklen_t cli_addr_len = sizeof(cli_addr);

    while(1)
    {
        if((connfd = accept(sockfd,(struct sockaddr*)&cli_addr,&cli_addr_len))<0)
        {
            perror("accept");
            exit(0);
        }
        printf("recv connect ip=%s port=%d\n",inet_ntoa(cli_addr.sin_addr),ntohs(cli_addr.sin_port));

        pid = fork();
        if(pid < 0)
        {
            perror("fork");
        }
        if(pid == 0)
        {
            close(sockfd);
            service(connfd);
            exit(EXIT_SUCCESS);
        }
        else
            close(connfd);
    }
    return 0;

}

void service(int fd)
{
    char recvbuff[MAXLINE];
    while(1)
    {
        memset(recvbuff,0,sizeof(recvbuff));
        int ret = read(fd,recvbuff,sizeof(recvbuff));
        if(ret == 0)
        {
            printf("client is close\n");
            break;
        }
        else if(ret == -1)
        {
            perror("read error:");
            exit(0);
        }
        fputs(recvbuff,stdout);
        write(fd,recvbuff,ret);
    }
}
