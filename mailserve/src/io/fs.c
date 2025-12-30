// I hate filesystems

#include <dirent.h> // if you are using MSVC add some implementation from github, or use MinGW and MSys2
#include <string.h>
#ifdef _WIN32
#include <BaseTsd.h> // ssize_t on win32
#else
#include <sys/types.h> // ssize_t
#endif

#include <mailserve/io/fs.h>

struct Mailserve_Directory {
    DIR *realdir;
};

Mailserve_Directory *mailserve_open_dir(const char *path) {
    Mailserve_Directory *mdir = malloc(sizeof(Mailserve_Directory));
    if (!mdir) return NULL;
    mdir->realdir = opendir(path);
    if(!mdir->realdir) {
        free(mdir);
        return NULL;
    }
    return mdir;
}

ssize_t mailserve_glob_dir(Mailserve_Directory *directory, Mailserve_Dirents *da) {
    struct dirent *direntry;
    ssize_t        cnt = 0;
    while ((direntry = readdir(directory->realdir)) != NULL) {
        Mailserve_Dirent mailserveDirent;
            
            switch (direntry->d_type) {
            case DT_DIR:
                mailserveDirent.type = MAILSERVE_DIRENT_DIRECTORY;
                break;
            case DT_REG:
                mailserveDirent.type = MAILSERVE_DIRENT_NORMAL;
                break;
            case DT_LNK:
                mailserveDirent.type = MAILSERVE_DIRENT_SYMLINK;
                break;
            default:
                mailserveDirent.type = MAILSERVE_DIRENT_OTHER;
                break;
            }
        
        char *fname = malloc(strlen(direntry->d_name) + 1);
        if (!fname) return -1; // buy more ram
        strcpy(fname, direntry->d_name);
        mailserveDirent.filename = fname;

        MAILSERVE_DA_PUSH_BACK(da, mailserveDirent);

        ++cnt;
    }
}

void mailserve_close_dir(Mailserve_Directory *directory) {
    closedir(directory->realdir);
    free(directory);
}
