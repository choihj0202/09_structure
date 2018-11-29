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
	
	while ((c=fgetc(fp)) != EOF)	// �� ���� ����  
	{
		if (is_whitespace(c) == 0)	// ���ǹ��� �����̸� ����  
			break;
	}
	
	if (c == EOF)	// ���� ���� ���ڰ� �������� ��  
		return 0;
	
	// ���������� �ܾ �� ���ھ� ����  
	cnt = 0;
	word[cnt++] = c;	// �Ʊ� ���� ù ���� �Է� 
	word[cnt] = '\0';	// Ȥ�� �ڿ��� �� ���� �� �����Ƿ� (�� ����¥�� �ܾ�)  
	
	while ((word[cnt]=fgetc(fp)) != EOF)	// �� ���� �޾Ƽ� ���ǹ��� ���ڰ� ���� ������ ���� �ݺ�  
	{
		if (is_whitespace(word[cnt]) == 1)	// ���� �����̸� ���� �� ����ϰ� ����  
		{
			word[cnt] = '\0';	// ���ڿ� �� 
			break;	// ���ǹ��� ���ڸ� ���� 
		}
		cnt++;
	}
	
	// ���� ���� �� ��ȯ  
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
	
	while (fget_word(fp, word) != 0)	// fp���� �� ���ھ� �����ͼ� word�� ����  
	{
		printf("%s\n", word);
		//count_word(word); 
	}
	
	//print_word();
	
	fclose(fp);
	
	return 0;
}
