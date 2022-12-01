#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
int hls (char *dir, int op1, int op2)
{
    DIR *dit = opendir("dir");
    struct dirent* c;

    if ( dit == NULL){
        return 1;
    }
    c = readdir (dit);
    while (c  != NULL){
        if (!op1 &&  c -> d_name[0] == '.') 
        continue;
        printf ("%s\n", c -> d_name);
        if (op1)
            printf("\n");
        c = readdir (dit);
    }
    if (!op1)
        printf("\n");
    closedir (dit);
    return 0;
}
int main(int argc, char *argv[])
{
    
    if (argc == 1)
    {
        hls(".", 0, 0);
    }
    else if (argc == 2)
    {
        if (argv[1][0]== '-')
        {
            int opt1 = 0, opt2 = 0;
            char *p  = (char*)(argv[1]+1);
            while(*p)
            {
                if(*p == 'a')
                    opt1 = 1;
                else if (*p == 'l')
                    opt2 = 1;
                else
                    printf ("known");
            p++;
            }
        hls(".", opt1, opt2);
        }
        else 
        {
            hls(argv[1], 0, 0);
        }
    }
    else if (argc == 3){
        if (argv[1][0]== '-')
        {
            int opt1 = 0, opt2 = 0;
            char *p  = (char*)(argv[1]+1);
            while(*p)
            {
                if(*p == 'a')
                    opt1 = 1;
                else if (*p == 'l')
                    opt2 = 1;
                else
                    printf ("known");
            p++;
            }
            hls(argv[2], 0, 0);
        }

    }
    return 0;
}