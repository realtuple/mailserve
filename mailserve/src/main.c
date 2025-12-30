#include <stdbool.h>
#include <stdio.h>

#include "server.h"

int main() {
    _Mailserve_Server server = { 0 };
    
    // TODO: Add configuration
    // TODO: Add plugins

    _mailserve_server_init(&server);
    printf("Server initialized\n");

    while (server.isRunning) {
        _mailserve_server_update(&server);
        printf("Server updated\n");
    }
    
    _mailserve_server_close(&server);
    printf("Server closed\n");
    
    return 0;
}