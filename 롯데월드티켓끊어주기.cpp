#include <stdio.h>

char* ticketType(int a) {
	if(a==1){
	static char type[10] = "�ְ���";
	return type;
    }
    if(a==2){
	static char type[10] = "�߰���";
	return type;
    }
}
char* humanType(int b){
	if(b==1){
	static char humantype[10]= "�Ʊ�";
	return humantype;
	}
	if(b==2){
	static char humantype[10]= "�Ʊ�";
	return humantype;
	}
	if(b==3){
	static char humantype[10]= "���";
	return humantype;
	}
	if(b==4){
	static char humantype[10]= "û�ҳ�";
	return humantype;
	}
	if(b==5){
	static char humantype[10]= "�";
	return humantype;
	}
	if(b==5){
	static char humantype[10]= "����";
	return humantype;
	}
}
char* specialType(int c){
	if(c==1){
	static char speicialtype[30]= "����������";
	return speicialtype;
	}
	if(c==2){
	static char speicialtype[30]= "����ο������";
	return speicialtype;
	}
	if(c==3){
	static char speicialtype[30]= "���������ڿ������";
	return speicialtype;
	}
	if(c==4){
	static char speicialtype[30]= "�ٵ��̿������";
	return speicialtype;
	}
	if(c==5){
	static char speicialtype[30]= "�ӻ�ο������";
	return speicialtype;
	}
	if(c==6){
	static char speicialtype[30]= "�����庴�������";
	return speicialtype;
	}
}
int main() {
    int today_Date;
	printf("���� ��¥�� �Է��Ͽ��ּ���.(ex.20220414)");
	scanf("%d", &today_Date);//���糯¥ �ҷ����� ���� ���� �� �� �𸥴�. 
	
	int ticket_Type, numberof_Tickets, prefer_Number, ticket_Price, total_Price, human_Type;
	char id_Number[13];
	int trynum = 0;
	int ticket_Typearr[5] ;
	int human_Typearr[5] ;
	int count_Ticketarr[5];
	int ticket_Pricearr[5];
	int special_Typearr[5];
	while(true){
		while(true){
		trynum = trynum + 1; //ù��° ȸ�� ,,�ٽù߱��Ҷ��� �ι�°ȸ��,,	
		printf("������ �����ϼ���\n");
		printf("1. �ְ���\n");
		printf("2. �߰���\n");
		scanf("%d", &ticket_Type);
		printf("%s�Դϴ�\n", ticketType(ticket_Type));
		
		ticket_Typearr[trynum-1]=ticket_Type;//�迭�� 1(�ְ���) 2(�߰���)�� ����������� 
		//���� Ƽ�� ��������� �ְ������� �߰������� ���̰� ���ִ� �κ� 
		
		printf("�ֹι�ȣ�� �Է��ϼ���\n");//<<���̰��κ� ����>> 
		scanf("%s", id_Number);
		int birth_Date = (id_Number[0]-48)*100000 + (id_Number[1]-48)*10000+(id_Number[2]-48)*1000+(id_Number[3]-48)*100+(id_Number[4]-48)*10+(id_Number[5]-48)*1;//�ƽ�Ű�ڵ� �̿� 94��� 
			if (id_Number[6]<='2'){
				birth_Date += 19000000;
			}
			else{
				birth_Date += 20000000;
			}//���� ������ Ȯ�� 
		int age= (today_Date/10000)-(birth_Date/10000);
			if ((today_Date%10000)<(birth_Date%10000)){
				age = age-1;
			}
			else age= age;//���� �������� Ȯ���ؼ� 
		printf("�����̴� %d�Դϴ�.\n", age);//������ ��� 
		ticket_Price=0;
		if (ticket_Type==1){
			if (age<1){
				ticket_Price=0;
				human_Type=1; 
			}else if (age<3&&age>=1){
				ticket_Price=0;//12�������� 36������ 0��������, �ణ �ٸ����� ������ �ϴ� ����ȭ�س��´�. 
				human_Type=2;
			}else if (3<=age&&age<13){
				ticket_Price=46000;
				human_Type=3;
			}else if (13<=age&&age<19){
				ticket_Price=52000;
				human_Type=4;
			}else if (19<=age&&age<65){
				ticket_Price=59000;
				human_Type=5;
			}else if (65<=age){
				ticket_Price=46000;
				human_Type=6;
			}
			printf("������ %d���Դϴ�.", ticket_Price);
			
		}
		if (ticket_Type==2){
			if (age<1){
				ticket_Price=0;
				human_Type=1;
			}else if (age<3&&age>=1){
				ticket_Price=0;//12�������� 36������ 0��������, �ణ �ٸ����� ������ �ϴ� ����ȭ�س��´�. 
				human_Type=2;	
			}else if (3<=age&&age<13){
				ticket_Price=36000;
				human_Type=3;
			}else if (13<=age&&age<19){
				ticket_Price=43000;
				human_Type=4;
			}else if (19<=age&&age<65){
				ticket_Price=50000;
				human_Type=5;
			}else if (65<=age){
				ticket_Price=36000;//��Ÿ ���� �ȵ�. 
				human_Type=6;
			}
			printf("������ %d���Դϴ�.", ticket_Price);
		}
			human_Typearr[trynum-1]=human_Type;//ù��° ȸ���� ��������� human_Typearr�迭 ù�ڸ��� �Էµ�. �ι�°ȸ������ �迭 �ι�° �ڸ��� �Էµ�. ����°ȸ����.. 
		while(true){//<<Ƽ�� ���� �κ� ����>> 
		printf("��� �ֹ��Ͻðڽ��ϱ�?(�ִ� 10��)\n");
		scanf("%d", &numberof_Tickets);
		count_Ticketarr[trynum-1]=numberof_Tickets;//ù��° ȸ���� Ƽ�ϼ����� count_Ticketarr�迭 ù�ڸ��� �Էµ� 
		if (0<numberof_Tickets&&numberof_Tickets<11){
		 ticket_Price= ticket_Price*numberof_Tickets;
		 break;
		}
		else printf("�ٽ� �Է����ּ���");
		continue;
		}
		
		printf("�������� �����ϼ���\n");//<<������ �κн���>> 
		printf("1.����\n");
		printf("2.�����\n");
		printf("3.����������\n");
	    printf("4.�ٵ��� �ູī��\n");
	    printf("5.�ӻ��\n");
	    printf("6.�ް��庴 ���\n"); 
	    scanf("%d", &prefer_Number); 
	    special_Typearr[trynum-1]=prefer_Number;//ù��° ȸ���� �������� special_Typearr�迭 ù�ڸ��� �Էµ�. 
	    if(prefer_Number==2||prefer_Number==3){//�����,������������ ��� 
	    	if(numberof_Tickets==1){//����Ƽ�ϼ��� 1���϶��� Ƽ�������� ����ۿ� ������.	
				ticket_Price= ticket_Price-(ticket_Price/numberof_Tickets)*0.5;
	        }else ticket_Price= ticket_Price-(ticket_Price/numberof_Tickets)*0.5;
		}       //���� Ƽ�ϼ��� 2�� �̻��϶��� ����1�α��� 2�� ���ι���. 
		if(prefer_Number==5){//�ӻ���� ��� 
	    	ticket_Price= ticket_Price-(ticket_Price/numberof_Tickets)*0.5;
	    	 }
			   
		if(prefer_Number==6){
	    	if(numberof_Tickets==1){	
				ticket_Price= ticket_Price-(ticket_Price/numberof_Tickets)*0.49;
	        	}else ticket_Price= ticket_Price-(ticket_Price/numberof_Tickets)*0.49*2;
			}
		if(prefer_Number==4){
			while(true){
			printf("�����ο��� �ٵ��� ī�忡 ���� ����� ����ΰ���?\n");
	    	int dadoongicard_Member;
	    	scanf("%d", &dadoongicard_Member);
	    	if(dadoongicard_Member<=numberof_Tickets){
			ticket_Price= ticket_Price-(ticket_Price/numberof_Tickets)*dadoongicard_Member*0.3;
			break;
			}
			else{
			printf("�����ο����� ���ι޴� �ο��� �����ϴ�. �ٽ� �Է����ּ���.\n");//���ι޴°Ÿ� ��ü������ �� �߸��ؼ� �����ؾ� �� 
				}
	        }
	    }
	    ticket_Pricearr[trynum-1] =ticket_Price;//ù��°ȸ���� Ƽ�ϰ����� ticket_Pricearr�迭 ù�ڸ��� �Էµ�. 
	    
	    total_Price= total_Price+ticket_Price;
	    printf("��� �߱��Ͻðڽ��ϱ�?\n");
	    printf("1.Ƽ�Ϲ߱�\n");
	    printf("2.����\n");
	    int continue_or_Not;
	    scanf("%d",&continue_or_Not);
		if(continue_or_Not==1){
		 	continue;	
		}
		if(continue_or_Not==2){
			break;
	    	}
		}
	    printf("Ƽ�Ϲ߱��������մϴ�. �����մϴ�.\n\n");
	    printf("===================�Ե�����===================\n");
	    for(int i=0; i<trynum; i++){
		printf("%s %s X %d   %d    %s\n", ticketType(ticket_Typearr[i]), humanType(human_Typearr[i]), count_Ticketarr[i], ticket_Pricearr[i], specialType(special_Typearr[i]) );
		}
		printf("����� �Ѿ��� %d�Դϴ�.\n", total_Price);//�̺κк��� ������ �ȵ� ���ϱ� 
		printf("==============================================\n\n");
		printf("��� ����(1: ���ο� �ֹ�, 2: ���α׷� ����) : ");
		int finish_or_Not;
		scanf("%d",&finish_or_Not);
		if (finish_or_Not == 1){
			continue;
		}else if(finish_or_Not == 2){
			break;
		}
	}
}

