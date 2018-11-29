#include <stdio.h>
#include <stdlib.h>
//#include "keyword.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int is_whitespace(char c)
{	
	if ((c == ' ') || (c == '\n') || (c == '\r') || (c == '\t') || (c == '(') || (c == ')'))
		return 1;

	return 0;
}

int fget_word(FILE* fp, char* word)
{
	char c;
	int cnt;
	
	while ((c=fgetc(fp)) != EOF)	// 한 문자 받음  
	{
		if (is_whitespace(c) == 0)	// 유의미한 문자이면 나감  
			break;
	}
	
	if (c == EOF)	// 최초 읽은 문자가 마지막일 때  
		return 0;
	
	// 본격적으로 단어를 한 글자씩 읽음  
	cnt = 0;
	word[cnt++] = c;	// 아까 읽은 첫 글자 입력 
	word[cnt] = '\0';	// 혹시 뒤에서 못 읽을 수 있으므로 (한 글자짜리 단어)  
	
	while ((word[cnt]=fgetc(fp)) != EOF)	// 한 문자 받아서 무의미한 글자가 나올 때까지 저장 반복  
	{
		if (is_whitespace(word[cnt]) == 1)	// 공백 문자이면 받은 거 취소하고 나감  
		{
			word[cnt] = '\0';	// 문자열 끝 
			break;	// 무의미한 문자면 멈춤 
		}
		cnt++;
	}
	
	// 읽은 글자 수 반환  
	return cnt;
}

int main(int argc, char *argv[]) {
	
	FILE* fp; 
	char name[100];
	char word[100];
	
	printf("INPUT A FILE NAME : ");
	scanf("%s", name);
	
	fp = fopen(name, "r");
	
	if (fp == NULL)
	{
		printf("ERROR! CHECK THE FILE NAME : %s\n", name);
		return -1;
	}	
	
	while (fget_word(fp, word) != 0)	// fp에서 한 글자씩 가져와서 word에 저장  
	{
		printf("%s\n", word);
		//count_word(word); 
	}
	
	//print_word();
	
	fclose(fp);
	
	return 0;
}
