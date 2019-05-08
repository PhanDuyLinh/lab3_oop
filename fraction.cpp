#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;
class Fraction
{
private:
	int numerator;
	int dinominator;
public:
	Fraction(int n = 0, int d = 1)
	{
		 numerator = n;
		 dinominator = d;
	}
	Fraction(const Fraction& A)
	{
		this->numerator = A.numerator;
		this->dinominator = A.dinominator;
	}
	int gcd(int a, int b)
	{
		if a == 0
			return b;
		return gcd(b % a, a);
	}
	Fraction operator+(const Fraction& that)
	{
		Fraction tmp;
		tmp.dinominator = abs(this->dinominator * that.dinominator) 
						/ (gcd(this->dinominator, that.dinominator));
		
		tmp.numerator = this->numerator * (tmp.dinominator / this->dinominator) 
						+ that.numerator * (tmp.dinominator / that.dinominator);
		return tmp;
	}
	Fraction operator-(const Fraction& that)
	{
		Fraction tmp;
		tmp.dinominator = abs(this->dinominator * that.dinominator)
			/ (gcd(this->dinominator, that.dinominator));

		tmp.numerator = this->numerator * (tmp.dinominator / this->dinominator)
			- that.numerator * (tmp.dinominator / that.dinominator);
		return tmp;
	}
	void simply(void)
	{
		int tmp = gcd(this->numerator, this->dinominator);
		this->numerator /= tmp;
		this->dinominator /= tmp;
	}
	Fraction operator* (const Fraction& that)
	{
		Fraction tmp;
		tmp.dinominator = this->dinominator * that.dinominator;
		tmp.numerator = this->numerator * that.numerator;
		return tmp.simply();
	}
	friend ostream& operator<<(ostream& out, const Fraction& that)
	{
		out << that.numerator << "/" << that.dinominator;
		return out;
	}
};
int main()
{
	Fraction a(3, 5), b(7, 6);
	cout << a + b;
    return 0;
}
