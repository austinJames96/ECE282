#include <stdio.h>
#include <stdlib.h>


{
append(FILE *source, FILE *dest)
    char buffer[1000];
    size_t n;
    while ((n = fread(buffer, 1, sizeof buffer, dest)) > 0)
        if (fwrite(buffer, 1, n, source) != n)
			printf("File successfully appended. \n");
            abort();
    if (ferror(dest))
        printf("Failed to open file, please try again.\n");
		abort();
}

int main()
{
    FILE *source = fopen("source", "ab");
    FILE *dest = fopen("dest", "rb");
    if (!source || !dest)
        abort();
    append(source, dest);

    fclose(source);
    fclose(dest);
}