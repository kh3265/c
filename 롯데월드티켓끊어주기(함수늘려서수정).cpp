#include <stdio.h>

char* ticketType(int a) {
	if (a == 1) {
		static char type[10] = "주간권";
		return type;
	}
	if (a == 2) {
		static char type[10] = "야간권";
		return type;
	}
}
char* humanType(int b) {
	if (b == 1) {
		static char humantype[10] = "아기";
		return humantype;
	}
	if (b == 2) {
		static char humantype[10] = "아기";
		return humantype;
	}
	if (b == 3) {
		static char humantype[10] = "어린이";
		return humantype;
	}
	if (b == 4) {
		static char humantype[10] = "청소년";
		return humantype;
	}
	if (b == 5) {
		static char humantype[10] = "어른";
		return humantype;
	}
	if (b == 6) {
		static char humantype[10] = "노인";
		return humantype;
	}
}
char* specialType(int c) {
	if (c == 1) {
		static char speicialtype[30] = "우대적용없음";
		return speicialtype;
	}
	if (c == 2) {
		static char speicialtype[30] = "장애인우대적용";
		return speicialtype;
	}
	if (c == 3) {
		static char speicialtype[30] = "국가유공자우대적용";
		return speicialtype;
	}
	if (c == 4) {
		static char speicialtype[30] = "다둥이우대적용";
		return speicialtype;
	}
	if (c == 5) {
		static char speicialtype[30] = "임산부우대적용";
		return speicialtype;
	}
	if (c == 6) {
		static char speicialtype[30] = "휴가장병우대적용";
		return speicialtype;
	}
}
int humantype(int age_){
	int human_Type;
	if (age_ < 1) {
			human_Type = 1;
		}	
	else if (age_ < 3 && age_ >= 1) {
			human_Type = 2;
		}
	else if (3 <= age_ && age_ < 13) {
			human_Type = 3;
		}
	else if (13 <= age_ && age_ < 19) {
			human_Type = 4;
		}
	else if (19 <= age_ && age_ < 65) {
			human_Type = 5;
		}
	else if (65 <= age_) {
			human_Type = 6;
		}
		return human_Type;
	}
int price(int a, int b){
int price_Arr[2][6] = {    
        { 0, 0, 46000, 52000, 59000, 46000},//주간 가격표 
        { 0, 0, 36000, 43000, 50000, 36000}//야간 가격표 
    };
        return price_Arr[a][b]; //ex)2행6열은 야간-노인 가격이다. 
    }
void discount_uv(){
    printf("우대사항을 선택하세요\n");
	printf("1.없음\n");
	printf("2.장애인\n");
	printf("3.국가유공자\n");
	printf("4.다둥이 행복카드\n");
	printf("5.임산부\n");
	printf("6.휴가장병 우대\n");
}
int ticketDiscount(int a, int b){
	if (a == 2 || a == 3) {//장애인,국가유공자일 경우 
		b = b* 0.5;
	}      
	if (a == 5) {//임산부일 경우 
		b = b * 0.5;
	}
	if (a == 6) {//휴가장병일경우 
		b = b * 0.49;
	}
	if (a == 4) {//다자녀일경우 
		b = b * 0.3;
		}//할인부분 전체적으로 수정 요망 
	return b;
}
int main() {
	int visiting_Date;
	printf("방문 예정일을 입력하여주세요.(ex.20220414)");
	scanf("%d", &visiting_Date);//현재날짜 불러오는 것을 아직 할 줄 모른다. 그래서 날짜 입력받음. 

	int ticket_Type, numberof_Tickets, prefer_Number, ticket_Price, total_Price, human_Type;
	char id_Number[13];
	int try_Number = 0;
	int ticket_Typearr[10];// 
	int human_Typearr[10];
	int count_Ticketarr[10];
	int ticket_Pricearr[10];
	int special_Typearr[10];
	total_Price = 0;
	while (true) {
		while (true) {
			try_Number = try_Number + 1; //첫번째 회차 ,,다시발권할때는 두번째회차,,	
			printf("권종을 선택하세요\n");
			printf("1. 주간권\n");
			printf("2. 야간권\n");
			scanf("%d", &ticket_Type);
			ticket_Typearr[try_Number - 1] = ticket_Type;////나중 티켓 출력했을때 주간권인지 야간권인지 보이게 해주는 부분 
			printf("주민번호를 입력하세요\n");
			scanf("%s", id_Number);//<<나이계산부분 시작>> 
			int birth_Date = (id_Number[0] - 48) * 100000 + (id_Number[1] - 48) * 10000 + (id_Number[2] - 48) * 1000 + (id_Number[3] - 48) * 100 + (id_Number[4] - 48) * 10 + (id_Number[5] - 48) * 1;//아스키코드 이용 94출력 
			if (id_Number[6] <= '2') {
				birth_Date += 19000000;
			}
			else birth_Date += 20000000; //몇년대 생인지 확인 
			int age = (visiting_Date / 10000) - (birth_Date / 10000);
			if ((visiting_Date % 10000) < (birth_Date % 10000)) {
				age = age - 1;
			}
			else age = age;//생일 지났는지 확인해서 
			printf("만나이는 %d입니다.\n", age);//만나이 계산 
			human_Type =humantype(age);
			ticket_Price = 0;
			ticket_Price = price(ticket_Type-1, human_Type-1);
			printf("가격은 %d원입니다.", ticket_Price);
			human_Typearr[try_Number - 1] = human_Type;//첫번째 회차의 사람종류가 human_Typearr배열 첫자리에 입력됨. 두번째회차에는 배열 두번째 자리에 입력됨. 세번째회차는.. 
			while (true) {//<<티켓 수량 부분 시작>> 
				printf("몇개를 주문하시겠습니까?(최대 10개)\n");
				scanf("%d", &numberof_Tickets);
				count_Ticketarr[try_Number - 1] = numberof_Tickets;//첫번째 회차의 티켓수량이 count_Ticketarr배열 첫자리에 입력됨 
				if (0 < numberof_Tickets && numberof_Tickets < 11) {
					ticket_Price = ticket_Price * numberof_Tickets;
					break;
				}
				else printf("다시 입력해주세요");
				continue;
			}
			discount_uv();//우대사항 번호판 나옴. 
			scanf("%d", &prefer_Number);
			special_Typearr[try_Number - 1] = prefer_Number;//첫번째 회차의 우대사항이 special_Typearr배열 첫자리에 입력됨. 
			ticket_Price =ticketDiscount(prefer_Number, ticket_Price);
			ticket_Pricearr[try_Number - 1] = ticket_Price;//첫번째회차의 티켓가격이 ticket_Pricearr배열 첫자리에 입력됨. 
            total_Price = total_Price + ticket_Price;
			printf("계속 발권하시겠습니까?\n");
			printf("1.티켓발권\n");
			printf("2.종료\n");
			int continue_or_Not;
			scanf("%d", &continue_or_Not);
			if (continue_or_Not == 1) {
				continue;
			}
			if (continue_or_Not == 2) {
				break;
			}
		}
		printf("티켓발권을종료합니다. 감사합니다.\n\n");
		printf("===================롯데월드===================\n");
		for (int i = 0; i < try_Number; i++) {
			printf("%s %-6s X %-2d   %-6d    %-10s\n", ticketType(ticket_Typearr[i]), humanType(human_Typearr[i]), count_Ticketarr[i], ticket_Pricearr[i], specialType(special_Typearr[i]));
		}
		printf("입장료 총액은 %d원입니다.\n", total_Price);
		printf("==============================================\n\n");
		printf("계속 진행(1: 새로운 주문, 2: 프로그램 종료) : ");
		int finish_or_Not;
		scanf("%d", &finish_or_Not);
		if (finish_or_Not == 1) {
			continue;
		}
		else if (finish_or_Not == 2) {
			break;
		}
	}
}
