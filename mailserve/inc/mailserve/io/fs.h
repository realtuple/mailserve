#ifndef __MAILSERVE__IO__FS_H__
#define __MAILSERVE__IO__FS_H__

#ifdef _WIN32
#include <BaseTsd.h> // ssize_t on win32
#else
#include <sys/types.h> // ssize_t
#endif

#include <mailserve/data/da.h>

typedef enum Mailserve_File_Type {
    MAILSERVE_DIRENT_NORMAL    = 0,
    MAILSERVE_DIRENT_SYMLINK   = 1,
    MAILSERVE_DIRENT_DIRECTORY = 2,
    MAILSERVE_DIRENT_OTHER     = 3,
} Mailserve_Dirent_Type;

typedef struct Mailserve_Dirent {
    Mailserve_Dirent_Type type;
    char                 *filename;
} Mailserve_Dirent;

typedef MAILSERVE_DA(Mailserve_Dirents, Mailserve_Dirent) Mailserve_Dirents;

typedef struct Mailserve_Directory Mailserve_Directory;

Mailserve_Directory *mailserve_open_dir(const char *path);
ssize_t              mailserve_glob_dir(Mailserve_Directory *directory, Mailserve_Dirents *da);
void                 mailserve_close_dir(Mailserve_Directory *directory);

#endif