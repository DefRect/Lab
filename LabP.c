#include <stdio.h>
#define MAXLINE 1000
void process_line( char buffer[] );
void main( void )
{
	char line[MAXLINE];
	printf("Start line: ");
	gets( line );
	process_line( line );
	printf("Result line: ");
	puts( line );
}

void process_line( char buffer[] )
{
	char *buf_ptr; 
	char *end; 
	char *begin; 
	char c; 
	char prev_c;
	prev_c = ' ';
	buf_ptr = buffer;
	begin = buffer;
	end = buffer;
	do
	{
		c = *buf_ptr;
		if((c != ' ') && (c != ',') && (c != '.') && (c != '\0'))
			if((prev_c == ' ') || (prev_c == ',') || (prev_c == '.') || (prev_c == '\0'))
				begin = buf_ptr;

		if((prev_c != ' ') && (prev_c != ',') && (prev_c != '.') && (prev_c != '\0'))
			if((c == ' ') || (c == ',') || (c == '.') || (c == '\0'))
			{
				end = buf_ptr - 1;
				if(*begin == *end)
				{
					char *begin_c, *end_c;
					begin_c = begin;
					end_c = end + 1;

					while(*end_c != '\0')
						*begin_c++ = *end_c++;

					*begin_c = '\0';
					buf_ptr = buffer;
					c = *buf_ptr;	
				}
			}

	buf_ptr++;
	prev_c = c;
	} while( c != '\0' );

}
