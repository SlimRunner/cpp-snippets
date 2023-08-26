#include "Complex.hpp"
#include <cmath>

// ref: https://www.desmos.com/calculator/kraz3aiucq

namespace slmath
{
	Complex::Complex(double real, double imag):
		m_real{real},
		m_imag{imag}
	{
		
	}

	Complex::~Complex()
	{
		
	}

	double Complex::real()
	{
		return m_real;
	}

	double Complex::imag()
	{
		return m_imag;
	}

	double Complex::modulus()
	{
		return sqrt(m_real * m_real + m_imag * m_imag);
	}

	double Complex::argument()
	{
		return atan2(m_imag, m_real);
	}

	Complex operator + (Complex lhs, const Complex& rhs)
	{
		return Complex(lhs.m_real + rhs.m_real, lhs.m_imag + rhs.m_imag);
	}

	Complex operator - (Complex lhs, const Complex& rhs)
	{
		return Complex(lhs.m_real - rhs.m_real, lhs.m_imag - rhs.m_imag);
	}

	Complex operator * (Complex lhs, const Complex& rhs)
	{
		return Complex(
			lhs.m_real * rhs.m_real - lhs.m_imag * rhs.m_imag,
			lhs.m_real * rhs.m_imag + lhs.m_imag * rhs.m_real
		);
	}

	Complex operator / (Complex lhs, const Complex& rhs)
	{
		double denom = rhs.m_real * rhs.m_real + rhs.m_imag * rhs.m_imag;
		// (a + bi) / (c + di)
		return Complex(
			(lhs.m_real * rhs.m_real + lhs.m_imag * rhs.m_imag) / denom,
			(lhs.m_imag * rhs.m_real - lhs.m_real * rhs.m_imag) / denom
		);
	}

	Complex operator - (Complex other)
	{
		return Complex(
			-other.m_real,
			-other.m_imag
		);
	}
	
}
