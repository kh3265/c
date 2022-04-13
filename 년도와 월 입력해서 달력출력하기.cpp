#include <stdio.h> 
	int main(){
	printf("<달력출력기>\n");
	printf("년도를 입력하여 주십시오.");
	int year;
	scanf("%d", &year); 
	printf("월을 입력하여 주십시오.");
	int month;
	scanf("%d", &month);
	printf("%d년도 %d월의 달력입니다.",year ,month);
	
	int Pyeongnyun_Montharr[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//평년의 각 월이 가지는 날짜 수 
    int Yunnyun_Montharr[]={31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//윤년의 각 월이 가지는 날짜 수 
	
	int count_Yunnyun=0;
	int count_Pyeongnyun=0;
	char* what_Day[]={"월", "화", "수", "목", "금", "토", "일"};
	for(int indexA=1900; indexA<year; indexA++){ //1900년부터20 내가 입력한 날짜의 년도까지 for문 돌림. 
		if((((indexA%4)==0)&&((indexA%100)!=0)) || (indexA%400==0)){//윤년의 조건(ex. for문에서 가장 처음 들어가는 1900 이 조건 만족X)
	    	count_Yunnyun += 1;//위 조건을 만족할때마다 윤년의 갯수가 1씩증가함. 
		}
		else{
	    count_Pyeongnyun += 1;//만족 안할때마다 평년의 갯수가 1씩증가함 
		}	
	}
	printf("윤년의 갯수 : %d// 평년의 갯수: %d\n",count_Yunnyun, count_Pyeongnyun );//1900년부터 내가 입력한년도까지의 
	                                                                                //윤년갯수와 평년 갯수가 출력됨. 
	int countday_Thisyear=0;
	for (int indexB=0; indexB<month-1; indexB++){
		if ((((year%4)==0)&&((year%100)!=0)) || (year%400==0)){//입력한 년도가 윤년이라면  
	    	countday_Thisyear = countday_Thisyear + Yunnyun_Montharr[indexB];//윤년의 각 월들이 가지는 날짜수를 이용하여 일수 계산
		}
		else{//윤년이 아니라면(평년이라면) 
			countday_Thisyear = countday_Thisyear + Pyeongnyun_Montharr[indexB];//평년의 각 월들이 가지는 날짜수를 이용하여 일수 계산 
		}
	}
	int sum_Total = count_Yunnyun*366+count_Pyeongnyun*365+countday_Thisyear;
	int determine_Number=sum_Total%7;//determine_Number값이 무슨요일인지를 알려주는것. 
	printf("%d년 %d월 1일은 %s요일입니다.\n", year, month, what_Day[determine_Number] );
	
	printf("\t\t<%d년 %d월의 달력>\n", year, month);//달력만들기 시작 
	printf("월\t화\t수\t목\t금\t토\t일\n");
	printf("-----------------------------------------------------------\n");
	
	for(int jump=0; jump<determine_Number; jump++){//1일을 요일에 따라 빈칸 점프를 해주는 부분. 
	printf("\t");
	}
	
	if ((((year%4)==0)&&((year%100)!=0)) || (year%400==0)){//if문을통해 해당연도가 윤년이면 윤년달력을쓰고 
		for(int indexC=1; indexC<=Yunnyun_Montharr[month-1];indexC++){
			printf("%d\t", indexC);
			determine_Number++;
				if((determine_Number%7)==0){
					printf("\n");
				}
			}
		}
	else{
		for(int indexD=1; indexD<=Pyeongnyun_Montharr[month-1];indexD++){//해당연도가 평년이면 평년달력을 쓴다 
			printf("%d\t", indexD);
			determine_Number++;
			if((determine_Number%7)==0){
				printf("\n");
			}
		}
	}
}

