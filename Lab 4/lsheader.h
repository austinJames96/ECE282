#ifndef ls_h
#define ls_h

int ls(int x);
{
        strcpy(str, "----------");
        {
                if(S_ISDIR(mode)) str[0] = 'd';//directory
                if (S_ISCHR(mode)) str[0] = 'c';//character devices
                if (S_ISBLK(mode)) str[0] = 'b';//block device
                if (mode & S_IRUSR) str[1] = 'r';//owner read
                if (mode & S_IWUSR) str[2] = 'w';//owner write
                if (mode & S_IXUSR) str[3] = 'x';//owner execute
                if (mode & S_IRGRP) str[4] = 'r';//group read
                if (mode & S_WRGRP) str[5] = 'w';//group write
                if (mode & S_IXGRP) str[6] = 'x';//group execute
                if (mode & S_IROTH) str[7] = 'r';//other read
                if (mode & S_IWOTH) str[8] = 'w';//other write
                if (mode & S_IXOTH) str[9] = 'x';//other execute
        }
        #include <pwd.h>
}
