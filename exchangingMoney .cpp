#include <stdio.h>
int main(){ 
    printf("<짝홀 판독기>\n"); 
    while(true){
	printf("숫자를 입력해주세요\n");
	int input;
	scanf("%d", &input);//액수입력 
	
	if ((input%2)==0){
		printf("%d는 짝수입니다.\n" ,input);
		}
	else if ((input)%2==1){
	    printf("%d는 홀수입니다.\n", input); 
		}
	}
}
