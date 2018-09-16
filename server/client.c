/*************************************************************************
	> File Name: client.c
	> Author: 
	> Mail: 
	> Created Time: 2017年05月24日 星期三 21时01分04秒
 ************************************************************************/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>

#define PORT 4321 //客户端通信端口
#define BUFFER_SIZE 1024 //消息的最大长度

int main(int argc, char *argv[])
{
    int sockfd; //生命客户端套接字描述符
    int sendbytes, recvbytes; //
    char buf[BUFFER_SIZE];
    struct hostent *host;    //声明host结构体
    struct sockaddr_in serv_addr; //声明一个socket，储存客户端IP地址和端口
    int child;
    int child_id, father_id;
    char *a="quit";

    if(argc != 2) //检验是否输入IP地址
    {
        fprintf(stderr,"USAGE: ./client Hostname(or ip address) Text\n");
        exit(1);
    }


    if ((host = gethostbyname(argv[1])) == NULL) //获取主机名，IP地址
    {
        perror("gethostbyname"); //抛出异常
        exit(1);
    }

    memset(buf, 0, sizeof(buf)); //初始化buf

    if ((sockfd = socket(AF_INET,SOCK_STREAM,0)) == -1) //检验是否成功创建套接字描述符
    {
        perror("socket"); //抛出异常
        exit(1);
    }


    serv_addr.sin_family = AF_INET; //主机字节顺序
    serv_addr.sin_port = htons(PORT); //网络字节顺序，短整型
    serv_addr.sin_addr = *((struct in_addr *)host->h_addr);
    bzero(&(serv_addr.sin_zero), 8); //将此结构的其余空间清零


    if(connect(sockfd,(struct sockaddr *)&serv_addr, sizeof(struct sockaddr))== -1) //向检验是否成功连接服务器
    {
        perror("connect"); //抛出异常
        exit(1);
    }
    printf("\n");
    child = fork(); //创建子进程

    if(child == 0) //创建子进程成功
    {
        father_id = getppid();
        do //发消息进程
        {
            memset(buf, 0, sizeof(buf)); //初始化buf
            if(fgets(buf, BUFFER_SIZE, stdin) == NULL)
            {
                perror("fgets"); //抛出异常
                exit(1);
            }
            if ((sendbytes = send(sockfd, buf, strlen(buf), 0)) == -1) //检验发送消息是否成功
            {
                perror("send"); //抛出异常
                exit(1);
            }
        }while(strncmp(buf,"quit",4) != 0);
        printf("\n");
        if(kill(father_id,SIGKILL) == -1) //遇到“quit”，结束发消息进程
        {
            printf("error in quit father_process!");
        }
        else
        {
            printf("successed in quit father_process!");
        }
        exit(0); //结束子进程
    }
    else if(child > 0)
    {
        do //接收消息进程
        {
            memset(buf, 0, sizeof(buf)); //初始化buf

            if ((recvbytes = recv(sockfd, buf, BUFFER_SIZE, 0)) == -1) //检验接受消息是否成功
            {
                perror("recv"); //抛出异常
                exit(1);
            }
            printf("Receive a message:%s\n", buf);
            sleep(1);
        }while(strncmp(buf,"quit",4) != 0);
        printf("\n");
        exit(0); //遇到“quit”，退出发送进程
    }
    else
    {
        perror("fork"); //抛出异常
        exit(1);
    }
    close(sockfd); //关闭套接字通信
    exit(0); //退出程序
}
