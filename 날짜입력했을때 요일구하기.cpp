//1900�� 1�� 1���� �������̴�.
//1901�� 4�� 1�� 
#include <stdio.h> 
	int main(){
	printf("��¥�� �Է��ϼ��� ex)20220413\n");
	int day; 
	scanf("%d", &day);//��¥�� �Է¹޴´�.ex)20220413 
	int year= day/10000;// year�� (day/10000)���� ��. ex)2022 
	int month=(day%10000)/100;//month�� �ش� ��갪 ��. ex)04 
	int pyeongnyun_Montharr[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//����� �� ���� ������ ��¥ �� 
    int Yunnyun_Montharr[]={31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//������ �� ���� ������ ��¥ �� 
	int date=day%100;//date�� �ش簪�� �� ex)13 
	int count_Yunnyun=0;
	int count_Pyeongnyun=0;
	char* what_Day[]={"��", "ȭ", "��", "��", "��", "��", "��"};
	for(int i=1900; i<year; i++){ //1900�����20 ���� �Է��� ��¥�� �⵵���� for�� ����. 
		if((((i%4)==0)&&((i%100)!=0)) || (i%400==0)){//������ ����(ex. for������ ���� ó�� ���� 1900 �� ���� ����X)
	    count_Yunnyun += 1;//�� ������ �����Ҷ����� ������ ������ 1��������. 
		}
		else{
	    count_Pyeongnyun += 1;//���� ���Ҷ����� ����� ������ 1�������� 
		}	
	}
	printf("������ ���� : %d// ����� ����: %d\n",count_Yunnyun, count_Pyeongnyun );//1900����� ���� �Է��ѳ⵵������ 
	                                                                                //���ⰹ���� ��� ������ ��µ�. 
	int countday_Thisyear=0;
	for (int i=0; i<month-1; i++){
		if ((((year%4)==0)&&((year%100)!=0)) || (year%400==0)){//�Է��� �⵵�� �����̶��  
	    countday_Thisyear = countday_Thisyear + Yunnyun_Montharr[i];//������ �� ������ ������ ��¥���� �̿��Ͽ� �ϼ� ���
		}
		else{//������ �ƴ϶��(����̶��) 
		countday_Thisyear = countday_Thisyear + pyeongnyun_Montharr[i];//����� �� ������ ������ ��¥���� �̿��Ͽ� �ϼ� ��� 
		}
}
	int sum_Total = count_Yunnyun*366+count_Pyeongnyun*365+countday_Thisyear+date-1;
	printf("1900.01.01 ���ķ� %d���� �������ϴ�.\n", sum_Total);
	int determine_Number=sum_Total%7;
	printf("%s�����Դϴ�.\n", what_Day[determine_Number]);
}

