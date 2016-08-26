#ifndef __Rational_h
#define __Rational_h

#include <string>

class Rational {

private:
	int mNumerator;
	int mDenominator;
	void Normalize();

public:
	Rational();
	Rational(int numerator, int denominator);

	void SetNumerator(int numerator);
	void SetDenominator(int denominator);

	int GetNumerator() const;
	int GetDenominator() const;

	std::string ToString() const;

	Rational (const Rational &o);

	void operator=(const Rational &o);

	Rational operator-() const;

	friend Rational operator+(const Rational& lhs, const Rational& rhs);
	
	friend Rational operator-(const Rational& lhs, const Rational& rhs);

	friend Rational operator*(const Rational& lhs, const Rational& rhs);

	friend Rational operator/(const Rational& lhs, const Rational& rhs);

	friend std::ostream& operator<<(std::ostream& lhs, const Rational& rhs);

	friend bool operator==(const Rational& lhs, const Rational& rhs);

	friend bool operator!=(const Rational& lhs, const Rational& rhs);

	friend bool operator<(const Rational& lhs, const Rational& rhs);

	friend bool operator>(const Rational& lhs, const Rational& rhs);

	friend bool operator<=(const Rational& lhs, const Rational& rhs);

	friend bool operator>=(const Rational& lhs, const Rational& rhs);
};



#endif