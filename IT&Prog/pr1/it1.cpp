//Вариант 25
//Класс Рациональное число
//Поля : числитель, знаменатель
//Методы : возведение РЧ в целую степень
//Операторы : ^ как возведение вещественного числа в степень, заданную РЧ, деления / двух
//рациональных, сравнения != рационального числа с действительным, сложения +=
//увеличения значения на величину другого рационального числа

#include <iostream>
#include <cmath>

using namespace std;

class ratio_fraction
{
	int numerator, denomirator;
	double real;

public:

	ratio_fraction()
	{
		numerator = 0;
		denomirator = 1;
		real = 0;
		cout << "Default constructor called" << endl;
	}

	ratio_fraction(int num, int denom, double rel)
	{
		numerator = num;
		denomirator = denom;
		real = rel;
		cout << "Constructor with parameters called" << endl;
	}

	ratio_fraction(const ratio_fraction& r)
	{
		numerator = r.numerator;
		denomirator = r.denomirator;
		real = r.real;
		cout << "Copy constructor called" << endl;
	}

	~ratio_fraction()
	{
		cout << "Destructor called" << endl;
	}

	void set_real(double rel)
	{
		real = rel;
		cout << "Real setter called" << endl;
	}

	double get_real()
	{
		return real;
		cout << "Real getter called" << endl;
	}

	void set_num(int num)
	{
		numerator = num;
		cout << "Numerator setter called" << endl;
	}

	int get_num()
	{
		return numerator;
		cout << "Numerator getter called" << endl;
	}

	void set_denom(int denom)
	{
		do
		{
			if (denom == 0)
			{
				cout << "Denominator cannot be zero." << endl;
				cout << "Denominator: ";
				cin >> denom;
			}
			denomirator = denom;
		}
		while (denom == 0);
		cout << "Denominator setter called" << endl;
	}

	int get_denom()
	{
		return denomirator;
		cout << "Denominator getter called" << endl;
	}

	void power()
	{
		int n, num1, denom1;
		double rez;
		cout << "Entere degree: ";
		cin >> n;
		num1 = pow(numerator, n);
		denom1 = pow(denomirator, n);
		rez = (double)num1 / denom1;
		cout << "Original fraction: " << numerator << "/" << denomirator << endl;
		cout << "Raised to the " << n << " degree" << endl;
		cout << "Result: " << num1 << "/" << denom1 << " = " << rez << endl;
	}

	double to_double()
	{
		if (denomirator == 0)
		{
			cout << "Denominator cannot be 0, so was changed to 1";
			denomirator = 1;
		}
		return (double)numerator / denomirator;
	}

	friend ostream& operator << (ostream& out, const ratio_fraction& r)
	{
		cout << r.numerator << "/" << r.denomirator;
		return out;
	}
	friend ostream& operator < (ostream& out, const ratio_fraction& r)
	{
		cout << r.real;
		return out;
	}

	double operator^(const ratio_fraction& r)
	{
		cout << "Operator ^" << endl;
		return pow(real, r.numerator/r.denomirator);
	}

	double operator/(const ratio_fraction& r)
	{
		int num2, denom2;
		cout << "Operator /" << endl;
		num2 = numerator * r.denomirator;
		denom2 = denomirator * r.numerator;
		return (double)num2 / denom2;
	}

	bool operator!=(const ratio_fraction& r)
	{
		cout << "Operator !=" << endl;
		if ((double)numerator/denomirator != r.real)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	double operator+=(const ratio_fraction& r)
	{
		int num3, denom3;
		cout << "Operator +=" << endl;
		if (denomirator == r.denomirator)
		{
			num3 = numerator + r.numerator;
			cout << num3 << "/" << denomirator << " = ";
			return num3 / denomirator;
		}
		else
		{
			denom3 = denomirator * r.denomirator;
			num3 = (numerator * r.denomirator) + (r.numerator * denomirator);
		}
		cout << num3 << "/" << denom3 << " = ";
		return (double)num3 / denom3;
	}
};

int main(int argc, char* argv[])
{
	int x, y;
	char menu;

	cout << "-----------------------------------" << endl;
	cout << "------ Checking constructors ------" << endl;
	ratio_fraction number1;
	cout << "Number1: " << number1 << endl;
	cout << "-----------------------------------" << endl;

	ratio_fraction number2(4, 9, 0);
	cout << "Number2: " << number2 << endl;
	cout << "-----------------------------------" << endl;

	cout << "---------- from keyboard ----------" << endl;
	cout << "Enter a rational fraction" << endl;
	cout << "Numerator: ";
	cin >> x;
	do
	{
		cout << "Denominator: ";
		cin >> y;
		if (y == 0)
		{
			cout << "Denominator cannot be 0" << endl;
		}
	}
	while (y == 0);
	ratio_fraction number3(x, y, 0);
	cout << "Introduced number3: " << number3 << endl;
	cout << "-----------------------------------" << endl;

	ratio_fraction number4(number3);
	cout << "Number4: " << number4 << endl;

	do
	{
		cout << "-----------------------------------" << endl;
		cout << "-------------- MENU ---------------" << endl;
		cout << "1. Raising a rational number to an integer power" << endl;
		cout << "2. Raising a real number to a power given by a rational number (^)" << endl;
		cout << "3. Division of two rational numbers (/)" << endl;
		cout << "4. Comparison of rational and real numbers (!=)" << endl;
		cout << "5. Addition of two rational numbers (+)" << endl;
		cout << "0. Exit" << endl;
		cout << "-----------------------------------" << endl;
		cin >> menu;
		switch (menu)
		{
			case '1':
			{
				system("cls");
				cout << "---------- from keyboard ----------" << endl;
				cout << "Entere a rational fraction: " << endl;
				cout << "Numerator: ";
				cin >> x;
				number4.set_num(x);
				cout << "Denominator: ";
				cin >> y;
				number4.set_denom(y);
				cout << "Introduced number: " << number4 << " = " << number4.to_double() << endl;
				number4.power();
				break;
			}
			case '2':
			{
				double rez, dbl;
				system("cls");
				cout << "---------- from keyboard ----------" << endl;
				cout << "Enter a real number: ";
				cin >> dbl;
				ratio_fraction real(0, 1, 0);
				real.set_real(dbl);
				cout < real;
				cout << "\nEnter a rational fraction: " << endl;
				cout << "Numerator: ";
				cin >> x;
				number4.set_num(x);
				cout << "Denominator: ";
				cin >> y;
				number4.set_denom(y);
				cout << "Introduced number: " << number4 << " = " << number4.to_double() << endl;
				rez = real ^ number4;
				cout << rez << endl;
				break;
			}
			case '3':
			{
				system("cls");
				double rez;
				cout << "---------- from keyboard ----------" << endl;
				cout << "Enter a first rational fraction: " << endl;
				cout << "Numerator: ";
				cin >> x;
				number3.set_num(x);
				cout << "Denumirator: ";
				cin >> y;
				number3.set_denom(y);
				cout << "Introduced number: " << number3 << endl;
				cout << "-----------------------------------" << endl;
				cout << "Enter a second rational fraction: " << endl;
				do
				{
					cout << "Numerator: ";
					cin >> x;
					if (x == 0)
					{
						cout << "The second fraction cannot be 0." << endl;
					}
				}
				while (x == 0);
				number4.set_num(x);
				cout << "Denumirator: ";
				cin >> y;
				number4.set_denom(y);
				cout << "Introduced number: " << number4 << endl;
				cout << "-----------------------------------" << endl;
				rez = number3 / number4;
				cout << rez << endl;
				break;
			}
			case '4':
			{
				double dbl;
				system("cls");
				cout << "---------- from keyboard ----------" << endl;
				cout << "Enter a rational fraction: " << endl;
				cout << "Numerator: ";
				cin >> x;
				number3.set_num(x);
				cout << "Denumirator: ";
				cin >> y;
				number3.set_denom(y);
				cout << "Introduced number: " << number3 << endl;
				cout << "-----------------------------------" << endl;
				cout << "Enter a real number: " << endl;
				ratio_fraction rel(0, 1, 0);
				cin >> dbl;
				rel.set_real(dbl);
				cout << "-----------------------------------" << endl;
				cout << "First fraction == Real number?" << endl;
				cout << number3.to_double() << " == " < rel;
				cout << "?" << endl;
				cout << ((number3 != rel) ? "YES" : "NO") << endl;
				break;
			}
			case '5':
			{
				system("cls");
				double rez;
				cout << "---------- from keyboard ----------" << endl;
				cout << "Enter a first rational fraction: " << endl;
				cout << "Numerator: ";
				cin >> x;
				number3.set_num(x);
				cout << "Denumirator: ";
				cin >> y;
				number3.set_denom(y);
				cout << "Introduced number: " << number3 << endl;
				cout << "-----------------------------------" << endl;
				cout << "Enter a second rational fraction: " << endl;
				cout << "Numerator: ";
				cin >> x;
				number4.set_num(x);
				cout << "Denumirator: ";
				cin >> y;
				number4.set_denom(y);
				cout << "Introduced number: " << number4 << endl;
				cout << "-----------------------------------" << endl;
				rez = number3 += number4;
				cout << rez << endl;
				break;
			}
			case '0':
			{
				cout << "Exiting program..." << endl;
				break;
			}
			default:
			{
				cout << "-----------------------------------" << endl;
				cout << "Invalid choice. Try again." << endl;
			}
		}
	}
	while (menu != '0');
	return 0;
}
