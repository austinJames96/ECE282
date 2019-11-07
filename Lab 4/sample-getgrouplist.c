#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <grp.h>
void main()
{
        gid_t  rgid, egid, sgid, *groups;
        struct group *grp;
        int num = 100, retval;

        if( getresgid(&rgid, &egid, &sgid) == -1 )
        {
                printf("Error\n");
                exit(1);
        }
        printf("%d %d %d\n", rgid, egid, sgid);

        if( (retval = getgrouplist( "hessamla", rgid, groups, &num)) <= num ){
                printf("Number of groups: %d\n", num);
                while ( retval--){
                        printf("%d\n", groups[retval]);
                }
        }
        return;
}
