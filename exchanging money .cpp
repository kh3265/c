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
		
    printf("%d원 -> %f %s\n", korea_Money, exchanged_Value, unit);
    printf("그래서 당신은 %d %s를 받을수 있다.\n", exchanged_uTake, unit);
    printf("잔돈은 %d원 이다.\n", (int)(change));
	printf("1000원: %d개, 500원: %d개, 100원: %d개 50원: %d개 10원: %d개\n", coin1000,coin500, coin100, coin50, coin10); 
}
int main()
{      
 while(true){
        int korea_Money;
		int choose_Num;
		printf("얼마를  환전하시겠습니까??\n");
		scanf("%d", &korea_Money);
		printf("어느 나라 돈으로 환전하시겠습니까?\n");
		printf("1.미국 2.중국 3.일본\n");
		scanf("%d",&choose_Num); 
		if ((choose_Num != 1) &&(choose_Num != 2) &&(choose_Num != 3)){
			printf("잘못된 번호입니다. 다시 입력하여 주십시오.");
			continue;
		}
		else if(choose_Num==1){
		     exchange_Package(korea_Money, 1233.50, "달라") ;
		     
		}
		else if(choose_Num==2){
			exchange_Package(korea_Money, 193.23, "위안");
		}
		else if(choose_Num==3){
			exchange_Package(korea_Money, 983.89, "엔");
		}
    }
}




