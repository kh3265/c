#include <stdio.h>

char* ticketType(int a) {
	if (a == 1) {
		static char type[10] = "�ְ���";
		return type;
	}
	if (a == 2) {
		static char type[10] = "�߰���";
		return type;
	}
}
char* humanType(int b) {
	if (b == 1) {
		static char humantype[10] = "�Ʊ�";
		return humantype;
	}
	if (b == 2) {
		static char humantype[10] = "�Ʊ�";
		return humantype;
	}
	if (b == 3) {
		static char humantype[10] = "���";
		return humantype;
	}
	if (b == 4) {
		static char humantype[10] = "û�ҳ�";
		return humantype;
	}
	if (b == 5) {
		static char humantype[10] = "�";
		return humantype;
	}
	if (b == 6) {
		static char humantype[10] = "����";
		return humantype;
	}
}
char* specialType(int c) {
	if (c == 1) {
		static char speicialtype[30] = "����������";
		return speicialtype;
	}
	if (c == 2) {
		static char speicialtype[30] = "����ο������";
		return speicialtype;
	}
	if (c == 3) {
		static char speicialtype[30] = "���������ڿ������";
		return speicialtype;
	}
	if (c == 4) {
		static char speicialtype[30] = "�ٵ��̿������";
		return speicialtype;
	}
	if (c == 5) {
		static char speicialtype[30] = "�ӻ�ο������";
		return speicialtype;
	}
	if (c == 6) {
		static char speicialtype[30] = "�ް��庴�������";
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
        { 0, 0, 46000, 52000, 59000, 46000},//�ְ� ����ǥ 
        { 0, 0, 36000, 43000, 50000, 36000}//�߰� ����ǥ 
    };
        return price_Arr[a][b]; //ex)2��6���� �߰�-���� �����̴�. 
    }
void discount_uv(){
    printf("�������� �����ϼ���\n");
	printf("1.����\n");
	printf("2.�����\n");
	printf("3.����������\n");
	printf("4.�ٵ��� �ູī��\n");
	printf("5.�ӻ��\n");
	printf("6.�ް��庴 ���\n");
}
int ticketDiscount(int a, int b){
	if (a == 2 || a == 3) {//�����,������������ ��� 
		b = b* 0.5;
	}      
	if (a == 5) {//�ӻ���� ��� 
		b = b * 0.5;
	}
	if (a == 6) {//�ް��庴�ϰ�� 
		b = b * 0.49;
	}
	if (a == 4) {//���ڳ��ϰ�� 
		b = b * 0.3;
		}//���κκ� ��ü������ ���� ��� 
	return b;
}
int main() {
	int visiting_Date;
	printf("�湮 �������� �Է��Ͽ��ּ���.(ex.20220414)");
	scanf("%d", &visiting_Date);//���糯¥ �ҷ����� ���� ���� �� �� �𸥴�. �׷��� ��¥ �Է¹���. 

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
			try_Number = try_Number + 1; //ù��° ȸ�� ,,�ٽù߱��Ҷ��� �ι�°ȸ��,,	
			printf("������ �����ϼ���\n");
			printf("1. �ְ���\n");
			printf("2. �߰���\n");
			scanf("%d", &ticket_Type);
			ticket_Typearr[try_Number - 1] = ticket_Type;////���� Ƽ�� ��������� �ְ������� �߰������� ���̰� ���ִ� �κ� 
			printf("�ֹι�ȣ�� �Է��ϼ���\n");
			scanf("%s", id_Number);//<<���̰��κ� ����>> 
			int birth_Date = (id_Number[0] - 48) * 100000 + (id_Number[1] - 48) * 10000 + (id_Number[2] - 48) * 1000 + (id_Number[3] - 48) * 100 + (id_Number[4] - 48) * 10 + (id_Number[5] - 48) * 1;//�ƽ�Ű�ڵ� �̿� 94��� 
			if (id_Number[6] <= '2') {
				birth_Date += 19000000;
			}
			else birth_Date += 20000000; //���� ������ Ȯ�� 
			int age = (visiting_Date / 10000) - (birth_Date / 10000);
			if ((visiting_Date % 10000) < (birth_Date % 10000)) {
				age = age - 1;
			}
			else age = age;//���� �������� Ȯ���ؼ� 
			printf("�����̴� %d�Դϴ�.\n", age);//������ ��� 
			human_Type =humantype(age);
			ticket_Price = 0;
			ticket_Price = price(ticket_Type-1, human_Type-1);
			printf("������ %d���Դϴ�.", ticket_Price);
			human_Typearr[try_Number - 1] = human_Type;//ù��° ȸ���� ��������� human_Typearr�迭 ù�ڸ��� �Էµ�. �ι�°ȸ������ �迭 �ι�° �ڸ��� �Էµ�. ����°ȸ����.. 
			while (true) {//<<Ƽ�� ���� �κ� ����>> 
				printf("��� �ֹ��Ͻðڽ��ϱ�?(�ִ� 10��)\n");
				scanf("%d", &numberof_Tickets);
				count_Ticketarr[try_Number - 1] = numberof_Tickets;//ù��° ȸ���� Ƽ�ϼ����� count_Ticketarr�迭 ù�ڸ��� �Էµ� 
				if (0 < numberof_Tickets && numberof_Tickets < 11) {
					ticket_Price = ticket_Price * numberof_Tickets;
					break;
				}
				else printf("�ٽ� �Է����ּ���");
				continue;
			}
			discount_uv();//������ ��ȣ�� ����. 
			scanf("%d", &prefer_Number);
			special_Typearr[try_Number - 1] = prefer_Number;//ù��° ȸ���� �������� special_Typearr�迭 ù�ڸ��� �Էµ�. 
			ticket_Price =ticketDiscount(prefer_Number, ticket_Price);
			ticket_Pricearr[try_Number - 1] = ticket_Price;//ù��°ȸ���� Ƽ�ϰ����� ticket_Pricearr�迭 ù�ڸ��� �Էµ�. 
            total_Price = total_Price + ticket_Price;
			printf("��� �߱��Ͻðڽ��ϱ�?\n");
			printf("1.Ƽ�Ϲ߱�\n");
			printf("2.����\n");
			int continue_or_Not;
			scanf("%d", &continue_or_Not);
			if (continue_or_Not == 1) {
				continue;
			}
			if (continue_or_Not == 2) {
				break;
			}
		}
		printf("Ƽ�Ϲ߱��������մϴ�. �����մϴ�.\n\n");
		printf("===================�Ե�����===================\n");
		for (int i = 0; i < try_Number; i++) {
			printf("%s %-6s X %-2d   %-6d    %-10s\n", ticketType(ticket_Typearr[i]), humanType(human_Typearr[i]), count_Ticketarr[i], ticket_Pricearr[i], specialType(special_Typearr[i]));
		}
		printf("����� �Ѿ��� %d���Դϴ�.\n", total_Price);
		printf("==============================================\n\n");
		printf("��� ����(1: ���ο� �ֹ�, 2: ���α׷� ����) : ");
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
