#include <stdio.h>

void exchange_Package(int korea_Money, float ex_rate, char *unit){
  	float exchanged_Value = (float)((korea_Money)*(1.0/ex_rate));
    int exchanged_uTake = (int) exchanged_Value;
    int change= korea_Money- exchanged_uTake*ex_rate;
            
    int coin1000 =change/1000;
	change = change - coin1000*1000;
	int coin500 = change/500;
	change = change - coin500 * 500;
	int coin100 = change/100;
	change = change - coin100 * 100;
	int coin50 = change/50;
	change = change - coin50 * 50;
	int coin10 = change/10;
		
    printf("%d�� -> %f %s\n", korea_Money, exchanged_Value, unit);
    printf("�׷��� ����� %d %s�� ������ �ִ�.\n", exchanged_uTake, unit);
    printf("�ܵ��� %d�� �̴�.\n", (int)(change));
	printf("1000��: %d��, 500��: %d��, 100��: %d�� 50��: %d�� 10��: %d��\n", coin1000,coin500, coin100, coin50, coin10); 
}
int main()
{      
 while(true){
        int korea_Money;
		int choose_Num;
		printf("�󸶸�  ȯ���Ͻðڽ��ϱ�??\n");
		scanf("%d", &korea_Money);
		printf("��� ���� ������ ȯ���Ͻðڽ��ϱ�?\n");
		printf("1.�̱� 2.�߱� 3.�Ϻ�\n");
		scanf("%d",&choose_Num); 
		if ((choose_Num != 1) &&(choose_Num != 2) &&(choose_Num != 3)){
			printf("�߸��� ��ȣ�Դϴ�. �ٽ� �Է��Ͽ� �ֽʽÿ�.");
			continue;
		}
		else if(choose_Num==1){
		     exchange_Package(korea_Money, 1233.50, "�޶�") ;
		     
		}
		else if(choose_Num==2){
			exchange_Package(korea_Money, 193.23, "����");
		}
		else if(choose_Num==3){
			exchange_Package(korea_Money, 983.89, "��");
		}
    }
}




