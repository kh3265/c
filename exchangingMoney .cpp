#include <stdio.h>
int main(){ 
    printf("<¦Ȧ �ǵ���>\n"); 
    while(true){
	printf("���ڸ� �Է����ּ���\n");
	int input;
	scanf("%d", &input);//�׼��Է� 
	
	if ((input%2)==0){
		printf("%d�� ¦���Դϴ�.\n" ,input);
		}
	else if ((input)%2==1){
	    printf("%d�� Ȧ���Դϴ�.\n", input); 
		}
	}
}
