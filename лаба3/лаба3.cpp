#include <iostream>
void EnterHightLowLimit(int64_t&,int64_t&);//вводим верхнюю и нижнию границу
bool IsNatural(int64_t,int64_t);//проверка на натуральность 
bool HightLessLow( int64_t, int64_t);//если верхняя грань меньше нижней - меняй местами
void OutPutIncreasingOrder(int64_t, int64_t);//выводт числа на заданном отрезке, где цифры числа последовательно строго возрастают
int64_t ReverseNumberOfOrder(int64_t);//записывает новое число ,цифры которого удовлетворяют условию,что последнее число больше предыдущего
int64_t ReverseSecondTimeNumberOfOrder(int64_t);//переворачивает первое перевернутое число
void Swap(int64_t&, int64_t&);
int main() {
	int64_t h_lim{};
	int64_t l_lim{};
	EnterHightLowLimit(h_lim,l_lim);
	if (!IsNatural(h_lim,l_lim)) {
		std::cout << "it is not natural\n";
	}
	else {
		if (HightLessLow(h_lim, l_lim)) {//если верхняя грань меньше нижней - меняй местами
			Swap(h_lim, l_lim);
		}
		OutPutIncreasingOrder(h_lim, l_lim);
	}
	return 0;
}
void  EnterHightLowLimit(int64_t &h_lim, int64_t& l_lim) {//вводим верхнюю и нижнию границу
	std::cout << "enter hight limit : ";
	std::cin >> h_lim;
	std::cout << "enter low limit : ";
	std::cin >> l_lim;
}
bool IsNatural(int64_t h_lim,int64_t l_lim) {//проверка на натуральность 
	return (h_lim > 0 && l_lim > 0) ? true : false;
}
bool HightLessLow(int64_t h_lim, int64_t l_lim) {//проверяем больше ли нижняя грань, чем верхняя
	return h_lim < l_lim ? true : false;
}
void OutPutIncreasingOrder(int64_t h_lim, int64_t l_lim) {//выводт числа на заданном отрезке, где цифры числа последовательно строго возрастают
	for (int64_t i{ l_lim }; i <= h_lim; ++i) {//i здесь число на заданном промежутке 
		//int64_t rev_numb_first{ };
		//int64_t rev_numb_sec{};
		//int64_t temp{ i };
		//rev_numb_first = ReverseNumberOfOrder(temp);/*если остаток будет меньше следующего остатка, то вгоняем его в новое число*/
		//rev_numb_sec = ReverseSecondTimeNumberOfOrder(rev_numb_first);
		//if (i == rev_numb_sec) {//если совпадает с исходным,то оно подходит
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
int64_t ReverseNumberOfOrder(int64_t temp) {//записывает новое число ,цифры которого удовлетворяют условию ниже
	int64_t rev_numb_first{};//число,которое если перевернуть,то должно совпадать с исходным(если не совпадает,то цифры записаны не по возрастанию)
	while (temp > 0) {
		if (temp % 10 > (temp / 10) % 10) {
			rev_numb_first = rev_numb_first * 10 + temp % 10;
		}
		temp /= 10;
	}
	return rev_numb_first;
}
int64_t ReverseSecondTimeNumberOfOrder(int64_t reverse) {//переворачивает первое перевернутое число
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
