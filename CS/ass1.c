//assni(A) 1
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    pid_t p;
    int w;
    p = fork();

    if (p == 0)
    {
        printf("%d", getpid());
        printf("%d", getppid());
        execl("./nikhill", "mycp.c", NULL);
    }
    else
    {
        wait(&w);
        printf("%d", p);
        printf("%d", getpid());
        execl("./nikhil", "mygrep.c", NULL);
    }
    return 0;
}


//assni(B) 1
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    FILE *fptr1, *fptr2;
    char c, temp1[200], temp2[200];
    printf("enter file for reading\n");
    scanf("%s", temp1);
    fptr1 = fopen(temp1, "r");
    printf("enter file for writting\n");
    scanf("%s", temp2);
    fptr2 = fopen(temp2, "w");
    c = fgetc(fptr1);
    while (c != EOF)
    {
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }

    fclose(fptr1);
    fclose(fptr2);
    return 0;
}


//assni(C) 1
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    FILE *fptr1;
    char fn[200], pat[200], temp3[200];
    scanf("%s", pat);

    scanf("%s", fn);
    fptr1 = fopen(fn, "r");
    while (!feof(fptr1))
    {
        fgets(temp3, 1000, fptr1);
        if (strstr(temp3, pat))
        {
            printf("Pattern found");
        }
    }
    fclose(fptr1);
    return 0;
}
