#include <stdio.h>
void exchange_Package(int korea_Money, float ex_rate, char *unit){
        	float exchanged_Value = (float)((korea_Money)*(1.0/ex_rate));
            int exchanged_uTake = (int) exchanged_Value;
            int change= korea_Money- exchanged_uTake*ex_rate;
            printf("%d�� -> %f %s\n", korea_Money, exchanged_Value, unit);
            printf("�׷��� ����� %d %s�� ������ �ִ�.\n", exchanged_uTake, unit);
            printf("�ܵ��� %d�� �̴�.\n", (int)(change));
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



 
