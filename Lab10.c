#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <locale.h>

int main()
{
	char **ptr = NULL; 
	char prev_c = ' '; 
	char c; 
	int count_p = 0;
	int i = 0, j, tmp = 0, count; 
	int flag = 1; 

	FILE *fl_in = fopen("Text.txt","r"); 
	if(fl_in == NULL) 
	{
		printf("ERROR");
		system("pause");
		return 1;
	}
	setlocale(LC_ALL, "Rus");

	while(!feof(fl_in))
	{
		count = 0;
		c = fgetc(fl_in);
		tmp++;
		if((c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') && (prev_c = ' '))
		{
			while(1)
			{
				count++;
				prev_c = c;
				c = fgetc(fl_in);
				tmp++;
				if(((c == ' ') || (c == -1)) && (prev_c == '.' || prev_c == '?' || prev_c == '!')) 
				{
					count_p++;
					ptr = (char**)realloc(ptr, count_p * sizeof(char*));
					ptr[i] = (char*)malloc(count);
					fseek(fl_in, tmp-count-1, SEEK_SET);
					fread(ptr[i], sizeof(char), count, fl_in);
					c = fgetc(fl_in);
					i++;
					break;
				}
			}
		}
	}

	printf("Количество предложений: %d\n\n", count_p); 
	for(i = 0; i < count_p; i++)
	{
		printf("Предложение %d: ", i + 1);
		j = 0;
		while(ptr[i][j] != 'э')
		{
			printf("%c", ptr[i][j]); 
			j++;
		}
		printf("\n\n"); 
	}

	for(i = 0; i < count_p; i++)
		free(ptr[i]);

	fclose(fl_in); 
	free(ptr); 
	system("pause");
}
