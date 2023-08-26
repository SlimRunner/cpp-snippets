#ifndef COMPLEX_H
#define COMPLEX_H

namespace slmath
{
	class Complex
	{
	private:
		/* data */
		double m_real;
		double m_imag;
	public:
		Complex(double, double);
		~Complex();

		double real();
		double imag();

		double modulus();
		double argument();

		friend Complex operator + (Complex lhs, const Complex& rhs);
		friend Complex operator - (Complex lhs, const Complex& rhs);
		friend Complex operator * (Complex lhs, const Complex& rhs);
		friend Complex operator / (Complex lhs, const Complex& rhs);

		friend Complex operator - (Complex other);
	};

	Complex operator + (Complex lhs, const Complex& rhs);
	Complex operator - (Complex lhs, const Complex& rhs);
	Complex operator * (Complex lhs, const Complex& rhs);
	Complex operator / (Complex lhs, const Complex& rhs);

	Complex operator - (Complex other);

} // !slmath

#endif // !COMPLEX_H