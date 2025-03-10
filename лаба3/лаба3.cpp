#include <iostream>
void EnterHightLowLimit(int64_t&,int64_t&);//������ ������� � ������ �������
bool IsNatural(int64_t,int64_t);//�������� �� ������������� 
bool HightLessLow( int64_t, int64_t);//���� ������� ����� ������ ������ - ����� �������
void OutPutIncreasingOrder(int64_t, int64_t);//������ ����� �� �������� �������, ��� ����� ����� ��������������� ������ ����������
int64_t ReverseNumberOfOrder(int64_t);//���������� ����� ����� ,����� �������� ������������� �������,��� ��������� ����� ������ �����������
int64_t ReverseSecondTimeNumberOfOrder(int64_t);//�������������� ������ ������������ �����
void Swap(int64_t&, int64_t&);
int main() {
	int64_t h_lim{};
	int64_t l_lim{};
	EnterHightLowLimit(h_lim,l_lim);
	if (!IsNatural(h_lim,l_lim)) {
		std::cout << "it is not natural\n";
	}
	else {
		if (HightLessLow(h_lim, l_lim)) {//���� ������� ����� ������ ������ - ����� �������
			Swap(h_lim, l_lim);
		}
		OutPutIncreasingOrder(h_lim, l_lim);
	}
	return 0;
}
void  EnterHightLowLimit(int64_t &h_lim, int64_t& l_lim) {//������ ������� � ������ �������
	std::cout << "enter hight limit : ";
	std::cin >> h_lim;
	std::cout << "enter low limit : ";
	std::cin >> l_lim;
}
bool IsNatural(int64_t h_lim,int64_t l_lim) {//�������� �� ������������� 
	return (h_lim > 0 && l_lim > 0) ? true : false;
}
bool HightLessLow(int64_t h_lim, int64_t l_lim) {//��������� ������ �� ������ �����, ��� �������
	return h_lim < l_lim ? true : false;
}
void OutPutIncreasingOrder(int64_t h_lim, int64_t l_lim) {//������ ����� �� �������� �������, ��� ����� ����� ��������������� ������ ����������
	for (int64_t i{ l_lim }; i <= h_lim; ++i) {//i ����� ����� �� �������� ���������� 
		//int64_t rev_numb_first{ };
		//int64_t rev_numb_sec{};
		//int64_t temp{ i };
		//rev_numb_first = ReverseNumberOfOrder(temp);/*���� ������� ����� ������ ���������� �������, �� ������� ��� � ����� �����*/
		//rev_numb_sec = ReverseSecondTimeNumberOfOrder(rev_numb_first);
		//if (i == rev_numb_sec) {//���� ��������� � ��������,�� ��� ��������
		//	std::cout << i << '\t';
		//}
		bool cond{ true };
		int64_t temp{ i };
		while (temp != 0) {
			if (temp % 10 <= (temp / 10) % 10) {
				cond = false;
				break;
			}
			temp /= 10;
		}
		if (cond) {
			std::cout << i << ' ';
		}
	}
	std::cout << std::endl;
}
int64_t ReverseNumberOfOrder(int64_t temp) {//���������� ����� ����� ,����� �������� ������������� ������� ����
	int64_t rev_numb_first{};//�����,������� ���� �����������,�� ������ ��������� � ��������(���� �� ���������,�� ����� �������� �� �� �����������)
	while (temp > 0) {
		if (temp % 10 > (temp / 10) % 10) {
			rev_numb_first = rev_numb_first * 10 + temp % 10;
		}
		temp /= 10;
	}
	return rev_numb_first;
}
int64_t ReverseSecondTimeNumberOfOrder(int64_t reverse) {//�������������� ������ ������������ �����
	int64_t rev_numb_sec{};
	while (reverse > 0) {
		rev_numb_sec = rev_numb_sec * 10 + reverse % 10;
		reverse /= 10;
	}
	return rev_numb_sec;
}
void Swap(int64_t& a, int64_t& b) {
	int64_t temp{ a };
	a = b;
	b = temp;
}
