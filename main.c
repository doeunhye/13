#include <stdio.h>
#include <stdlib.h>
#include "keyword.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int is_whitespace(char c)
{
	if(c == ' '||
	   c == '\t'||
	   c == '\n'||
	   c == '\r'||
	   c == '('||
	   c == ')')
	   return 1;
	   
	return 0;
}

int fget_word(FILE *fp, char *word)
{
	char c;
	int cnt;
		
	while ((c=fgetc(fp)) != EOF)
	{
	if (is_whitespace(c) == 0 )
		{
			break;
		}
   }
	if ( c == EOF)
	{
		return 0;
	}
	
	cnt = 0;
	word[cnt++] = c;
	word[cnt] = '\0';
	
	while((word[cnt]=fgetc(fp)) != EOF){
		if (is_whitespace(word[cnt])==1)
		{
			word[cnt] = '\0';
			break;
		}
		cnt++;
	}
	
	return cnt;
}




int main(int argc, char *argv[]) {
	
	FILE* fp;
	char name[100];
	char word[100];
	

	//printf, scanf
	printf("input a file name : ");
	scanf("%s",name);
	
	//fopen
	fp = fopen(name, "r");
	//error handling
	if(fp == NULL)
	{
		printf("error! check file name : %s \n", name);
		return -1;
	}
	while (fget_word ( fp, word)!=0)
	{
		count_word(word);
	}
	print_word();
	
	fclose(fp);
	
	
	//word reading
	
	
	
	return 0;

}
