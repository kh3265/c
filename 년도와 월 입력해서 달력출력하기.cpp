#include <stdio.h> 
	int main(){
	printf("<�޷���±�>\n");
	printf("�⵵�� �Է��Ͽ� �ֽʽÿ�.");
	int year;
	scanf("%d", &year); 
	printf("���� �Է��Ͽ� �ֽʽÿ�.");
	int month;
	scanf("%d", &month);
	printf("%d�⵵ %d���� �޷��Դϴ�.",year ,month);
	
	int Pyeongnyun_Montharr[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//����� �� ���� ������ ��¥ �� 
    int Yunnyun_Montharr[]={31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//������ �� ���� ������ ��¥ �� 
	
	int count_Yunnyun=0;
	int count_Pyeongnyun=0;
	char* what_Day[]={"��", "ȭ", "��", "��", "��", "��", "��"};
	for(int indexA=1900; indexA<year; indexA++){ //1900�����20 ���� �Է��� ��¥�� �⵵���� for�� ����. 
		if((((indexA%4)==0)&&((indexA%100)!=0)) || (indexA%400==0)){//������ ����(ex. for������ ���� ó�� ���� 1900 �� ���� ����X)
	    	count_Yunnyun += 1;//�� ������ �����Ҷ����� ������ ������ 1��������. 
		}
		else{
	    count_Pyeongnyun += 1;//���� ���Ҷ����� ����� ������ 1�������� 
		}	
	}
	printf("������ ���� : %d// ����� ����: %d\n",count_Yunnyun, count_Pyeongnyun );//1900����� ���� �Է��ѳ⵵������ 
	                                                                                //���ⰹ���� ��� ������ ��µ�. 
	int countday_Thisyear=0;
	for (int indexB=0; indexB<month-1; indexB++){
		if ((((year%4)==0)&&((year%100)!=0)) || (year%400==0)){//�Է��� �⵵�� �����̶��  
	    	countday_Thisyear = countday_Thisyear + Yunnyun_Montharr[indexB];//������ �� ������ ������ ��¥���� �̿��Ͽ� �ϼ� ���
		}
		else{//������ �ƴ϶��(����̶��) 
			countday_Thisyear = countday_Thisyear + Pyeongnyun_Montharr[indexB];//����� �� ������ ������ ��¥���� �̿��Ͽ� �ϼ� ��� 
		}
	}
	int sum_Total = count_Yunnyun*366+count_Pyeongnyun*365+countday_Thisyear;
	int determine_Number=sum_Total%7;//determine_Number���� �������������� �˷��ִ°�. 
	printf("%d�� %d�� 1���� %s�����Դϴ�.\n", year, month, what_Day[determine_Number] );
	
	printf("\t\t<%d�� %d���� �޷�>\n", year, month);//�޷¸���� ���� 
	printf("��\tȭ\t��\t��\t��\t��\t��\n");
	printf("-----------------------------------------------------------\n");
	
	for(int jump=0; jump<determine_Number; jump++){//1���� ���Ͽ� ���� ��ĭ ������ ���ִ� �κ�. 
	printf("\t");
	}
	
	if ((((year%4)==0)&&((year%100)!=0)) || (year%400==0)){//if�������� �ش翬���� �����̸� ����޷������� 
		for(int indexC=1; indexC<=Yunnyun_Montharr[month-1];indexC++){
			printf("%d\t", indexC);
			determine_Number++;
				if((determine_Number%7)==0){
					printf("\n");
				}
			}
		}
	else{
		for(int indexD=1; indexD<=Pyeongnyun_Montharr[month-1];indexD++){//�ش翬���� ����̸� ���޷��� ���� 
			printf("%d\t", indexD);
			determine_Number++;
			if((determine_Number%7)==0){
				printf("\n");
			}
		}
	}
}

