#include <stdio.h>
#include <stdlib.h> // for exit() function
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
        int fd;
        if ( argc < 2 ){
                printf("Usage: %s <directoryname>\n", argv[0]);
				printf("This program will enter you into a directory assuming it exists.\n");
                printf("The directory might exist or not.\n");
                exit(1);
        }

        fd = open(argv[1], O_DIRECTORY);
        if (fd == -1){
                printf("Entering directory \"%s\" failed.\n", argv[1]);
        }
        else{
				char s[100];
				printf("Previous current working directory: \"%s\".\n", getcwd(s, 100));
                printf("The directory \"%s\" was entered w/o problem.\n", argv[1]);
				chdir(argv[1]);
				printf("Current working directory: \"%s\".\n", getcwd(s, 100));
        }

        return 0;
}
