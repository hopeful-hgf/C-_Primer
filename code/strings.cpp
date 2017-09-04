#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//const int BUFSIZ = 100;
const int MINLEN = 6;

/* strings: extract printable strings from stream */
void strings(char *name, FILE *fin)
{
	int c, i;
	char buf[BUFSIZ];

	do {	/* once for each string */
		for (i = 0; (c = getc(fin)) != EOF;) {
			if (!isprint(c))
				break;
			buf[i++] = c;
			if (i >= BUFSIZ)
				break;
		}
		if (i >= MINLEN) /* print if long enough */
			printf( "%s:%.*s\n",name,i,buf);
	} while (c != EOF);
}

/* strings main :find printable strings in files */
int main(int argc,char *argv[])
{
	int i;
	FILE *fin;
//	setprogname("strings_hgf");
	printf ("the number of arg is: %d \n",argc);	/* for a verify */
	if (argc == 1)
		printf("usage: strings filename");
	else {
		for (i = 1;i < argc; i++) {
			if ((fin = fopen (argv[i], "rb")) == NULL)
				printf("can't open %s:", argv[i]);
			else {
				strings(argv[i],fin);
				fclose(fin);
			}
		}
	}
	return 0;
}

