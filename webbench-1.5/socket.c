/* $Id: socket.c 1.1 1995/01/01 07:11:14 cthuang Exp $
 *
 * This module has been modified by Radim Kolar for OS/2 emx
 */

/***********************************************************************
  module:       socket.c
  program:      popclient
  SCCS ID:      @(#)socket.c    1.5  4/1/94
  programmer:   Virginia Tech Computing Center
  compiler:     DEC RISC C compiler (Ultrix 4.1)
  environment:  DEC Ultrix 4.3
  description:  UNIX sockets code.
 ***********************************************************************/

#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int Socket(const char *host, int clientPort)    // clientPort: 主机字节顺序表达的16位数。
{
    int sock;
    unsigned long inaddr;
    struct sockaddr_in ad;
    struct hostent *hp;

    memset(&ad, 0, sizeof(ad));
    ad.sin_family = AF_INET;

    inaddr = inet_addr(host);       // 将一个点分十进制的IP转换成一个长整数型数（u_long类型）
    if (inaddr != INADDR_NONE)      // 如果传入的字符串不是一个合法的IP地址，将返回INADDR_NONE
        memcpy(&ad.sin_addr, &inaddr, sizeof(inaddr));
    else
    {
        hp = gethostbyname(host);       // 返回对应于给定主机名的包含主机名字和地址信息的hostent结构指针
        if (hp == NULL)
            return -1;
        memcpy(&ad.sin_addr, hp->h_addr, hp->h_length);
    }
    ad.sin_port = htons(clientPort);    // 将主机的无符号短整形数转换成网络字节顺序。(将一个数的高低位互换)

    sock = socket(AF_INET, SOCK_STREAM, 0);     // 对于流类套接口（SOCK_STREAM类型），
    if (sock < 0)                               // 利用名字来与一个远程主机建立连接，
        return sock;                            // 一旦套接口调用成功返回，它就能收发数据了。
    if (connect(sock, (struct sockaddr *)&ad, sizeof(ad)) < 0)
        return -1;
    return sock;
}

