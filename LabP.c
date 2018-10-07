#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main()
{
	char buf[MAX];
	int flag = 0;

	FILE *fpin, *fpout;

	fpin = fopen("Text.txt", "rt");
	if(fpin == NULL)
	{
		printf("Error opening file: text.txt \n");
		system("pause");
		return 1;
	}
	else 
		printf ("File text.txt opened successfully\n");

	fpout = fopen("test.txt", "wt");
	if(fpout == NULL) 
	{
		printf("Error opening file: test.txt \n");
		system("pause");
		return 1;
	}
	else 
		printf ("File test.txt opened successfully\n");

	while(!feof(fpin))
	{
		char *ptr;
		ptr = fgets(buf, MAX, fpin);

		if(ptr == NULL) 
			break;

		while(*ptr != '\n')
		{
			if(flag == 0)
				if((*ptr == '/') && (*(ptr + 1) == '/'))
				{
					while(*ptr != '\n')
					{
						if(*ptr == '\0')
							break;
						*ptr = ' ';
						ptr++;
					}
					break;
				}

			if((*ptr == '/') && (*(ptr + 1) == '*'))
				flag = 1; 
			
			if(flag == 1)
				while(1)
				{
					if((*ptr == '*') && (*(ptr + 1) == '/')) 
					{
						*ptr = ' ';
						*(ptr + 1) = ' ';
						flag = 0;
						break;
					}
					else
						*ptr = ' ';
					if(*ptr != '\n') 
						break;
					ptr++;
				}

			ptr++;
		}

		fputs(buf, fpout);
	}

	if(fclose (fpin) == EOF) 
		printf ("Error closing file: text.txt\n");
	else 
		printf ("File text.txt closed successfully\n");

	if(fclose (fpout) == EOF) 
		printf ("Error closing file: test.txt\n");
	else 
		printf ("File test.txt closed successfully\n");
	system("pause");
	return 0;
}
