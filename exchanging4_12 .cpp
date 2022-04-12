#include <stdio.h>
void exchange_Package(int korea_Money, float ex_rate, char *unit){//(액수,환율,단위)를 입력받아서 환전계산을 해주고 print부분을 출력해주는  함수이다. 
  	float exchanged_Value = (float)((korea_Money)*(1.0/ex_rate));//환율계산해서 환전한 값 
    int exchanged_uTake = (int) exchanged_Value;//환전해서 실제로 받는 액수 
    int change= korea_Money- exchanged_uTake*ex_rate;//거스름돈 
    int coin1000 =change/1000;//거스름돈을 받을때 1000원짜리 갯수 
	change = change - coin1000*1000;
	int coin500 = change/500;//500원짜리 갯수 
	change = change - coin500 * 500;
	int coin100 = change/100;//100원짜리 갯수 
	change = change - coin100 * 100;
	int coin50 = change/50;//50원짜리 갯수 
	change = change - coin50 * 50;
	int coin10 = change/10;//10원짜리 갯수 
    printf("%d원 -> %f %s\n", korea_Money, exchanged_Value, unit);
    printf("그래서 당신은 %d %s를 받을수 있다.\n", exchanged_uTake, unit);
    printf("잔돈은 %d원 이다.\n", (int)(change));
	printf("1000원: %d개, 500원: %d개, 100원: %d개 50원: %d개 10원: %d개\n", coin1000,coin500, coin100, coin50, coin10); //이함수의 print부분 
    }
int main(){ 
    int korea_Money;//환전할 액수  
	int choose_Num;//고르는 번호 
	printf("얼마를  환전하시겠습니까??\n");
	scanf("%d", &korea_Money);//액수입력 
	while(true){//break가 없는 한 계속 반복 
	printf("어느 나라 돈으로 환전하시겠습니까?\n");
	printf("1.미국 2.중국 3.일본\n");
	scanf("%d",&choose_Num);//번호입력  
	
	if(choose_Num==1){//1번을 고르면 
	    exchange_Package(korea_Money, 1233.50, "달라") ;//입력된 액수, 1233.5의 환율, "달라"를 이용해서 환전계산을 해주고 그에따른 print부분 출력해주는 함수 
	    break;//반복문 나감 
	    }
	else if(choose_Num==2){//2번을 고르면.. 이하생략 
		exchange_Package(korea_Money, 193.23, "위안");
		break;
     	}
	else if(choose_Num==3){//3번을 고르면.. 이하생략 
		exchange_Package(korea_Money, 983.89, "엔");
		break;
	    }
	else{
		printf("잘못된 번호입니다. 다시 입력하여 주십시오.");//break 가없으므로 다시 반복문 앞부분으로 감 
		}
    }
}

