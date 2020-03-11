#include <sys/types.h>
#include <errno.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
     const char *filename;
     char p[2000], *t;
     FILE *fp;
     size_t len;
     int ch, rval;

     setlocale(LC_ALL, "");
 
     while ((ch = getopt(argc, argv, "")) != -1)
             switch(ch) {
             case '?':
             default: ;
             }
     argc -= optind;
     argv += optind;
         fp = stdin;
         filename = "stdin";
         rval = 0;
     do {
         if (*argv) {
             if ((fp = fopen(*argv, "r")) == NULL) {
                 perror(*argv);
                 rval = 1;
                 ++argv;
                 continue;
             }
         filename = *argv++;
         }
         while ((fgets(p, sizeof(p)-1, fp)) != NULL) {
             len = strlen(p);
             if (p[len - 1] == '\n')
             --len;
             t = p + len - 1;
             for (t = p + len - 1; t >= p; --t)
                 putchar(*t);
                 putchar('\n');
         }
         if (ferror(fp)) {
             perror(filename);
             rval = 1;
         }

        (void)fclose(fp);
    } while(*argv);

    exit(rval);
}

