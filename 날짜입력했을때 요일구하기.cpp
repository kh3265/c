//1900년 1월 1일이 월요일이다.
//1901년 4월 1일 
#include <stdio.h> 
	int main(){
	printf("날짜를 입력하세요 ex)20220413\n");
	int day; 
	scanf("%d", &day);//날짜를 입력받는다.ex)20220413 
	int year= day/10000;// year에 (day/10000)값이 들어감. ex)2022 
	int month=(day%10000)/100;//month에 해당 계산값 들어감. ex)04 
	int pyeongnyun_Montharr[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//평년의 각 월이 가지는 날짜 수 
    int Yunnyun_Montharr[]={31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//윤년의 각 월이 가지는 날짜 수 
	int date=day%100;//date에 해당값이 들어감 ex)13 
	int count_Yunnyun=0;
	int count_Pyeongnyun=0;
	char* what_Day[]={"월", "화", "수", "목", "금", "토", "일"};
	for(int i=1900; i<year; i++){ //1900년부터20 내가 입력한 날짜의 년도까지 for문 돌림. 
		if((((i%4)==0)&&((i%100)!=0)) || (i%400==0)){//윤년의 조건(ex. for문에서 가장 처음 들어가는 1900 이 조건 만족X)
	    count_Yunnyun += 1;//위 조건을 만족할때마다 윤년의 갯수가 1씩증가함. 
		}
		else{
	    count_Pyeongnyun += 1;//만족 안할때마다 평년의 갯수가 1씩증가함 
		}	
	}
	printf("윤년의 갯수 : %d// 평년의 갯수: %d\n",count_Yunnyun, count_Pyeongnyun );//1900년부터 내가 입력한년도까지의 
	                                                                                //윤년갯수와 평년 갯수가 출력됨. 
	int countday_Thisyear=0;
	for (int i=0; i<month-1; i++){
		if ((((year%4)==0)&&((year%100)!=0)) || (year%400==0)){//입력한 년도가 윤년이라면  
	    countday_Thisyear = countday_Thisyear + Yunnyun_Montharr[i];//윤년의 각 월들이 가지는 날짜수를 이용하여 일수 계산
		}
		else{//윤년이 아니라면(평년이라면) 
		countday_Thisyear = countday_Thisyear + pyeongnyun_Montharr[i];//평년의 각 월들이 가지는 날짜수를 이용하여 일수 계산 
		}
}
	int sum_Total = count_Yunnyun*366+count_Pyeongnyun*365+countday_Thisyear+date-1;
	printf("1900.01.01 이후로 %d일이 지났습니다.\n", sum_Total);
	int determine_Number=sum_Total%7;
	printf("%s요일입니다.\n", what_Day[determine_Number]);
}

