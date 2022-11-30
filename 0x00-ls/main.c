#include <stdio.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char * argv[])
{
    DIR* dir = opendir(".");
    if ( dir == NULL){
        return 1;
    }
    struct dirent* c;
    c = readdir (dir);
    while (c  != NULL){
        printf ("%s\n", c -> d_name);
        c = readdir (dir);

    }

    closedir (dir);
    return 0;
}
