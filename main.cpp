#include <iostream>
#include <poll.h>
#include <sys/msg.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <thread>
#include <stddef.h>
#include <unistd.h>
using namespace std;

#define SOCK_FILE   "/tmp/foo.sock"
int main()
{
    int fd, ret;
    size_t size;
    struct sockaddr_un un;

    un.sun_family = AF_UNIX;
    strncpy(un.sun_path, SOCK_FILE, strlen(SOCK_FILE));

    fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if(fd < 0)
    {
        perror("socket");
        exit(-1);
    }

    size = offsetof(struct sockaddr_un, sun_path) + strlen(un.sun_path);
    ret = bind(fd, (const struct sockaddr*)&un, size);
    if(ret < 0)
    {
        perror("bind");
    }

    cout<<"Unix domain socket bound"<<endl;
    close(fd);

    return 0;
}
