#ifndef __SERVER_H__
#define __SERVER_H__

#include <stdbool.h>

typedef struct {
    bool isRunning; 
} _Mailserve_Server;

void _mailserve_server_init(_Mailserve_Server *server);
void _mailserve_server_update(_Mailserve_Server *server);
void _mailserve_server_close(_Mailserve_Server *server);

#endif