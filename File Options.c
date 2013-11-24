/* 
- Author: Sam McEvoy
- Description: This program gives users the option to perform some 
operations with files like reading, copying and character counting.
- Date: 15/12/2010
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>

char option[80];
char filename[40] ;
FILE *fopen(), *fp, *fp2 ;

void file_open( void ) ;				/* Declaring each function */
void display_menu( void ) ;
void get_option( void ) ;
void process_option( void ) ;
void read_file( void ) ;
void character_count( void ) ;
void user_input( void ) ;
void copy_file( void );

void main()
{
	printf("\nEnter file that you wish to use: ");
	gets( filename );
	
	display_menu();						/* Running each function */
	get_option();
	while(option[0] != 'Q')
	{
		file_open();
		process_option();
		display_menu();
		get_option();
	}
}

void file_open(void)
{
	int i ;
	i = 0;
	
	for( i = 0; i < 3; i++ )			/* Loop to allow 3 attempts to input a filename */
	{
		fp = fopen(filename, "r"); 
		
		if( fp != NULL )				/* 'if' statement which ends loop if file is found */
		{
			printf("\n");
			i = i + 3;
		}
		
		if( fp == NULL )
		{
		printf("Cannot open %s for reading\n", filename);
		}
	}
	
	if( fp == NULL )
	{
		exit(1);						/* Ends program if file not found */
	}
}

void read_file(void)
{
	int c;
	c = getc( fp );						
	while ( c != EOF )					/* Loop which displays each character in the file */
	{
		putchar(c);
		c = getc ( fp );
	}
	fclose( fp );
}

void character_count ( void )
{
	int c, count, y ;
	y = 0;
	count = 0;
	char k[10];
	
	printf("Enter character you wish to count: ");
	scanf("%s", &k );
	
	c = getc( fp );						
	while ( c != EOF )					/* Loop that reads each character until the last one */
	{
		c = getc ( fp );
		if( c == k[y] )					/* Compares the entered character with each character in the file */
		{
			count++;
		}
	}
	printf("The character '%s' appears %d times", k, count );
}

void display_menu(void)
{
	printf("\n\n\n\n");
	printf("\t\t\tFile Options\n");
	printf("\t\tQ ......................... Quit \n");
	printf("\t\tC ......................... Copy \n");
	printf("\t\tA ......................... Character Amount \n");
	printf("\t\tR ......................... Read \n");
	printf("\n");
}

void get_option( void )
{	
	printf("\t\t\tEnter Option: ");
	gets( option ) ;
}

void copy_file( void )
{
	int c;
	char file2[80];
	printf("Enter the name of the copied file: ");
	gets( file2 );
	fp2 = fopen( file2, "w" );				/* Opens a new file for writing to */
	
	if( fp == NULL )
	{
		printf("Cannot open %s for reading", filename );
	}
	else if ( fp2 == NULL )
	{
		printf("Cannot open %s for reading", file2 );
	}
	else
	{
		c = getc( fp );
		while( c != EOF )					/* Copies each character to the new file */
		{
			putc( c, fp2 );
			c = getc( fp );
		}
	fclose(fp2);
	
	printf("Files successfully copied \n");
	}
}

void process_option( void )					 
{
	if (( option[0] == 'C') || ( option[0] == 'c' ))
	{
		copy_file();
	}
	else if ( ( option[0] == 'R') || ( option[0] == 'r' ))
	{
		read_file() ;
	}
	else if ( ( option[0] == 'A' ) || ( option[0] == 'a' ))
	{	
		character_count() ;
	}
	else
	{
		printf("Invalid option: %c \n", option[0] );
	}
	user_input();
}

void user_input( void )	
{
	char dummy[80];
	printf("\n\nPress Enter to continue");
	gets( dummy ) ;
}