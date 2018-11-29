#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	FILE* fp; 
	char name[100];
	
	printf("INPUT A FILE NAME : ");
	scanf("%s", name);
	
	fp = fopen(name, "r");
	
	if (fp == NULL)
	{
		printf("ERROR! CHECK THE FILE NAME : %s\n", name);
		return -1;
	}	
	
	printf("%c\n", fgetc(fp));
	// 파일 내 코드의 단어 하나하나 분석
	
	// 분석 결과 출력
	
	fclose(fp);
	return 0;
}
