package s4_8;

import java.util.Scanner;

public class P6 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		System.out.println("얼마를 환전하시겠습니까(원화를 숫자만 적어주세요)");
		System.out.println("ex)10만원 -> 100000");
		int korea_Money = scanner.nextInt();//얼마 환전 받을지 입력받기 예) 만원
		System.out.println("현재 환율을 적어주세요(1달러당 몇원인지)");
		double money_Exchange = scanner.nextDouble();//환율(1달러당 몇원인지) 예) 1100원
		System.out.println("은행이 갖는 수수료는 얼마입니까(백분율 말고 소수로 적어주세요)");
		System.out.println("ex) 1% -> 0.01");
		double commission = scanner.nextDouble();//수수료 입력받기 예) 1%(0.01)

		double bankget_per_1dollar = money_Exchange * commission;//은행이 1달러당받는수수료(원) = 1달러의 원화 X 은행수수료
		int dollar_u_Canget = (int) (korea_Money * (1 / (money_Exchange + bankget_per_1dollar)));//너가 받을 달러 = 만원/(1100원+은행수수료)
		                                                           //즉 너의 만원으로는 1100원과 그수수료를 몇번이나 감당하는지,, 1번감당할때마다 1달러씩받음.
		double bankget_Money = dollar_u_Canget * bankget_per_1dollar;//은행이 받을돈 = 너가받는달러 X 은행이 1달러당받는수수료(원)
		int bank_Really_take = 0;//하지만 원화는 소수점으로 받을수가 없다. 따라서 소수점이 생기면 은행은 올려서 받는다. 은행이 손해가 생기면 안되기때문
		if (bankget_Money == (int) bankget_Money) {//소수점이 없는경우. 
			bank_Really_take = (int) bankget_Money;//그대로받음
		} else {//소수점이 생긴경우
			bank_Really_take = (int) bankget_Money + 1;//소수점을 버린다음(int이용) 1을 더해서 받음.(올림해주는 메커니즘)
		}
		int remain = (int) (korea_Money - (money_Exchange * dollar_u_Canget) - bank_Really_take);//잔돈 = 환전하려던 전체돈-환전해서받은달러(원화로전환)-은행수수료
		System.out.println("당신이 받는 달라 : " + dollar_u_Canget);
		System.out.println("은행이 갖는 수수료 :" + bank_Really_take);
		System.out.println("잔돈 : " + remain);
	}

}
