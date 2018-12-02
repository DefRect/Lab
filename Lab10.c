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
	int i = 0, j = 0; 
	int flag = 0; 

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
		c = fgetc(fl_in);
		if(((c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) && flag == 0)
		{
			count_p++;
			ptr = (char**)realloc(ptr, count_p * sizeof(char*));
			ptr[i] = (char*)malloc(0);
			j = 0;
			flag = 1;
			while(1)
			{
				if(((c < 'A' || c > 'Z') && (c < '0' || c > '9') && (c < 'a' || c > 'z')) && (prev_c == '.' || prev_c == '?' || prev_c == '!'))
				{
					ptr[i] = (char*)realloc(ptr[i], (j + 1)*sizeof(char));
					ptr[i][j] = '\0';
					flag = 0;
					i++;
					break;
				}
				ptr[i] = (char*)realloc(ptr[i], (j + 1)*sizeof(char));
				ptr[i][j] = c;
				prev_c = c;
				c = fgetc(fl_in);
				j++;
			}
		}
	}

	printf("Количество предложений: %d\n\n", count_p); 
	for(i = 0; i < count_p; i++)
		printf("Предложение %d: %s\n\n", i + 1, ptr[i]);

	for(i = 0; i < count_p; i++)
		free(ptr[i]);

	fclose(fl_in); 
	free(ptr); 
	system("pause");
}
