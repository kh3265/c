package s4_8;

import java.util.Scanner;

public class P6 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		System.out.println("�󸶸� ȯ���Ͻðڽ��ϱ�(��ȭ�� ���ڸ� �����ּ���)");
		System.out.println("ex)10���� -> 100000");
		int korea_Money = scanner.nextInt();//�� ȯ�� ������ �Է¹ޱ� ��) ����
		System.out.println("���� ȯ���� �����ּ���(1�޷��� �������)");
		double money_Exchange = scanner.nextDouble();//ȯ��(1�޷��� �������) ��) 1100��
		System.out.println("������ ���� ������� ���Դϱ�(����� ���� �Ҽ��� �����ּ���)");
		System.out.println("ex) 1% -> 0.01");
		double commission = scanner.nextDouble();//������ �Է¹ޱ� ��) 1%(0.01)

		double bankget_per_1dollar = money_Exchange * commission;//������ 1�޷���޴¼�����(��) = 1�޷��� ��ȭ X ���������
		int dollar_u_Canget = (int) (korea_Money * (1 / (money_Exchange + bankget_per_1dollar)));//�ʰ� ���� �޷� = ����/(1100��+���������)
		                                                           //�� ���� �������δ� 1100���� �׼����Ḧ ����̳� �����ϴ���,, 1�������Ҷ����� 1�޷�������.
		double bankget_Money = dollar_u_Canget * bankget_per_1dollar;//������ ������ = �ʰ��޴´޷� X ������ 1�޷���޴¼�����(��)
		int bank_Really_take = 0;//������ ��ȭ�� �Ҽ������� �������� ����. ���� �Ҽ����� ����� ������ �÷��� �޴´�. ������ ���ذ� ����� �ȵǱ⶧��
		if (bankget_Money == (int) bankget_Money) {//�Ҽ����� ���°��. 
			bank_Really_take = (int) bankget_Money;//�״�ι���
		} else {//�Ҽ����� ������
			bank_Really_take = (int) bankget_Money + 1;//�Ҽ����� ��������(int�̿�) 1�� ���ؼ� ����.(�ø����ִ� ��Ŀ����)
		}
		int remain = (int) (korea_Money - (money_Exchange * dollar_u_Canget) - bank_Really_take);//�ܵ� = ȯ���Ϸ��� ��ü��-ȯ���ؼ������޷�(��ȭ����ȯ)-���������
		System.out.println("����� �޴� �޶� : " + dollar_u_Canget);
		System.out.println("������ ���� ������ :" + bank_Really_take);
		System.out.println("�ܵ� : " + remain);
	}

}
