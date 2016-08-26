#include "Rational.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

Rational::Rational()
:mNumerator(0), mDenominator(1) {
	cout << "Constructing a default Rational" << endl;
}

Rational::Rational(int numerator, int denominator)
:mNumerator(numerator), mDenominator(denominator) {
	Normalize();
	cout << "Constructing Rational with numerator " << mNumerator 
	 << " and denominator " << mDenominator << endl;
}

void Rational::SetNumerator(int numerator) {
	mNumerator = numerator;
	Normalize();
}

void Rational::SetDenominator(int denominator) {
	mDenominator = denominator;
	Normalize();
}

int Rational::GetNumerator() const {
	return mNumerator;
}

int Rational::GetDenominator() const {
	return mDenominator;
}

void Rational::Normalize() {
	int r;
	int n = mNumerator;
	int m = mDenominator;
	while (n != 0) {
		r = m % n;
		m = n;
		n = r;
	}
	
	mDenominator /=  m;
	mNumerator /=  m;

	if (mNumerator * mDenominator < 0) {
		mNumerator = -(sqrt(mNumerator * mNumerator));
		mDenominator = sqrt(mDenominator * mDenominator);
	}
}

string Rational::ToString() const {
	ostringstream strValue;
	if (mDenominator == 0)
		strValue << mNumerator;
	else
		strValue << mNumerator << "/" << mDenominator;
	return strValue.str();
}

void Rational::operator=(const Rational &o) {
	mNumerator = o.mNumerator;
	mDenominator = o.mDenominator;
}

Rational::Rational(const Rational &o)
	:mNumerator(o.mNumerator), mDenominator(o.mDenominator)
{
	cout << "Making copy of " << o.mNumerator << "/" << o.mDenominator << endl;
}

Rational Rational::operator-() const{
	return Rational(-mNumerator, mDenominator);
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
	int num = lhs.mNumerator * rhs.mDenominator +
	 lhs.mDenominator * rhs.mNumerator;
	int denom = lhs.mDenominator * rhs.mDenominator;
	return Rational(num, denom);
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
	int num = lhs.mNumerator * rhs.mDenominator - 
	 lhs.mDenominator * rhs.mNumerator;
	int denom = lhs.mDenominator * rhs.mDenominator;
	return Rational(num, denom);
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
	int num = lhs.mNumerator * rhs.mNumerator;
	int denom = lhs.mDenominator * rhs.mDenominator;
	return Rational(num, denom);
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
	int num = lhs.mNumerator * rhs.mDenominator;
	int denom = lhs.mDenominator * rhs.mNumerator;
	return Rational(num, denom);
}

ostream& operator<<(ostream& lhs, const Rational& rhs) {
	lhs << rhs.ToString();
	return lhs;
}

bool operator==(const Rational& lhs, const Rational& rhs) {
	return (lhs.mNumerator == rhs.mNumerator &&
	 lhs.mDenominator == rhs.mDenominator);
}

bool operator!=(const Rational& lhs, const Rational& rhs) {
	return !(lhs == rhs);
}

bool operator<(const Rational& lhs, const Rational& rhs) {
	return (double(lhs.mNumerator) / lhs.mDenominator <
	 (double)rhs.mNumerator / rhs.mDenominator);
}

bool operator>(const Rational& lhs, const Rational& rhs) {
	return (double(lhs.mNumerator) / lhs.mDenominator >
		(double)rhs.mNumerator / rhs.mDenominator);
}

bool operator<=(const Rational& lhs, const Rational& rhs) {
	return (lhs < rhs || lhs == rhs);
}

bool operator>=(const Rational& lhs, const Rational& rhs) {
	return (lhs > rhs || lhs == rhs);
}