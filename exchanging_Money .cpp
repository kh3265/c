#include <stdio.h>
void exchange_Package(int korea_Money, float ex_rate, char *unit){//(�׼�,ȯ��,����)�� �Է¹޾Ƽ� ȯ������� ���ְ� print�κ��� ������ִ�  �Լ��̴�. 
  	float exchanged_Value = (float)((korea_Money/ex_rate));//ȯ������ؼ� ȯ���� ��
    int exchanged_uTake = (int) exchanged_Value;//ȯ���ؼ� ������ �޴� �׼� 
    int change= korea_Money- exchanged_uTake*ex_rate;//�Ž����� 
    int change_Money = change;//�Ʒ���(�������� �����κ�)���� change�� ��� ���� ���� �Է� �Ǳ� ������ ���߿� �Ž������� ������ �˼�������.  
	                          //��¥ �Ž������� change_Money��� �������ٰ� �Է��صд�. 
	int coin1000 =change/1000;//�Ž������� ������ 1000��¥�� ���� 
	    change = change - coin1000*1000;
	int coin500 = change/500;//500��¥�� ���� 
		change = change - coin500 * 500;
	int coin100 = change/100;//100��¥�� ���� 
		change = change - coin100 * 100;
	int coin50 = change/50;//50��¥�� ���� 
		change = change - coin50 * 50;
	int coin10 = change/10;//10��¥�� ���� 
    printf("%d�� -> %f %s\n", korea_Money, exchanged_Value, unit);
    printf("�׷��� ����� %d %s�� ������ �ִ�.\n", exchanged_uTake, unit);
    printf("�ܵ��� %d�� �̴�.\n", change_Money);
	printf("1000��: %d��, 500��: %d��, 100��: %d�� 50��: %d�� 10��: %d��\n", coin1000,coin500, coin100, coin50, coin10); //���Լ��� print�κ� 
    }
int main(){ 
    int korea_Money;//ȯ���� �׼�  
	int choose_Num;//���� ��ȣ 
	printf("�󸶸�  ȯ���Ͻðڽ��ϱ�??\n");
	scanf("%d", &korea_Money);//�׼��Է� 
	printf("��� ���� ������ ȯ���Ͻðڽ��ϱ�?\n");
	printf("1.�̱� 2.�߱� 3.�Ϻ�\n");
	scanf("%d",&choose_Num);//��ȣ�Է�  
	
	if(choose_Num==1){//1���� ���� 
	    exchange_Package(korea_Money, 1233, "�޶�") ;//�Էµ� �׼�, 1233.5�� ȯ��, "�޶�"�� �̿��ؼ� ȯ������� ���ְ� �׿����� print�κ� ������ִ� �Լ� 
	    }
	else if(choose_Num==2){//2���� ����.. ���ϻ��� 
		exchange_Package(korea_Money, 193.23, "����");
     	}
	else if(choose_Num==3){//3���� ����.. ���ϻ��� 
		exchange_Package(korea_Money, 983.89, "��");
    }
}

