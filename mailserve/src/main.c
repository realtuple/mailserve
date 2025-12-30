#include <stdbool.h>
#include <stdio.h>

#include <mailserve/data/da.h>
#include <mailserve/io/fs.h>
#include "server.h"

typedef MAILSERVE_DA(UwU, int) UwU;

void dump_uwu(UwU *uwu) {
    for (size_t i = 0; i < uwu->count; i++) {
        printf("%d ", MAILSERVE_DA_AT(uwu, i));
    }
    printf("\n");
}

int main(int argc, char **argv) {
    _Mailserve_Server server = { 0 };
    
    // Loading addons
    Mailserve_Dirents dirents = { 0 };

    // assumes that file is executed from build folder, not out folder or anything
    // in future handle other folders
    Mailserve_Directory *directory = mailserve_open_dir("./out/addons");
    mailserve_glob_dir(directory, &dirents);

    for (size_t i = 0; i < dirents.count; i++) {
        printf("%s (%d) \n", dirents.items[i].filename, dirents.items[i].type);
    }
    mailserve_close_dir(directory);    

    // TODO: Add configuration

    _mailserve_server_init(&server);
    printf("Server initialized\n");
    
    while (server.isRunning) {
        _mailserve_server_update(&server);
    }
    
    _mailserve_server_close(&server);
    printf("Server closed\n");
    
    return 0;
}