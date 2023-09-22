#include <iostream>
#include <sstream>
#include "Rational.h"
#include "Integer.h"

namespace cosc326
{
	// A default constructor that creates Rational with a numerator of 0 and a denominator of 1
	Rational::Rational() : numerator(), denominator("1") {}

	// A constructor that takes a Rational as a parameter and creates a Rational object
	Rational::Rational(const Rational &r) : numerator(r.numerator), denominator(r.denominator) {}

	// A constructor that takes an Integer as a parameter and creates a Rational object
	Rational::Rational(const Integer &a) : numerator(a), denominator("1") {}

	//	A constructor that takes two Integers as parameters and creates a Rational object
	Rational::Rational(const Integer &a, const Integer &b) : numerator(a), denominator(b)
	{
		if (denominator.getIsNegative() && !numerator.getIsNegative())
		{
			denominator.setIsNegative(false);
			numerator.setIsNegative(true);
		}
		else if (denominator.getIsNegative() && numerator.getIsNegative())
		{
			denominator.setIsNegative(false);
			numerator.setIsNegative(false);
		}
	}

	// A constructor that takes three Integers as parameters and creates a Rational object
	Rational::Rational(const Integer &a, const Integer &b, const Integer &c) : denominator(c)
	{
		if (a < Integer())
		{
			Integer multiplier = a * denominator;
			multiplier.setIsNegative(false);
			numerator = b + multiplier;
			numerator.setIsNegative(true);
		}
		else
		{
			numerator = b + (a * denominator);
		}
	}

	// A constructor that takes a string as a parameter and creates a Rational object
	Rational::Rational(const std::string &s)
	{
		if (s.find(".") != std::string::npos)
		{ // Case for when the string contains a whole number and a fraction
			std::vector<std::string> whole = splitString(s, ".");
			std::vector<std::string> parts = splitString(s.substr(s.find(".") + 1), "/");
			numerator = Integer(parts[0]);
			denominator = Integer(parts[1]);
			if (Integer(whole[0]) < Integer())
			{
				Integer multiplier = Integer(whole[0]) * denominator;
				multiplier.setIsNegative(false);
				numerator = Integer(parts[0]) + multiplier;
				numerator.setIsNegative(true);
			}
			else
			{
				numerator = Integer(parts[0]) + (Integer(whole[0]) * denominator);
			}
		}
		else if (s.find("/") != std::string::npos)
		{ // Case for when the string contains a fraction
			std::vector<std::string> parts = splitString(s, "/");
			numerator = Integer(parts[0]);
			denominator = Integer(parts[1]);
		}
		else
		{ // Case for when the string contains a whole number
			numerator = Integer(s);
			denominator = Integer("1");
		}
	}

	// Default destructor
    Rational::~Rational() {}

	// An overload for the unary operator +
	Rational Rational::operator+() const
	{
		return Rational(*this);
	}

	// An overlaod for the unary operator -
	Rational Rational::operator-() const
	{
		return Rational(-numerator, denominator);
	}

	// A getter for the numerator
	const Integer &Rational::getNumerator() const
	{
		return numerator;
	}

	// A getter for the denominator
	const Integer &Rational::getDenominator() const
	{
		return denominator;
	}

	// A setter for the numerator
	void Rational::setNumerator(const Integer &num)
	{
		numerator = num;
	}

	// A setter for the denominator
	void Rational::setDenominator(const Integer &denom)
	{
		denominator = denom;
	}

	// An overload for the assingment operator =
	Rational &Rational::operator=(const Rational &r)
	{
		if (this != &r)
		{
			numerator = r.numerator;
			denominator = r.denominator;
		}
		return *this;
	}

	// An overload for the binary arithmetic operator +
	Rational operator+(const Rational &lhs, const Rational &rhs)
	{
		Integer newNumerator = (lhs.getNumerator() * rhs.getDenominator()) + (rhs.getNumerator() * lhs.getDenominator());
		Integer newDenominator = lhs.getDenominator() * rhs.getDenominator();
		return Rational(newNumerator, newDenominator);
	}

	// An overload for the binary arithmetic operator -
	Rational operator-(const Rational &lhs, const Rational &rhs)
	{
		Integer newNumerator = (lhs.getNumerator() * rhs.getDenominator()) - (rhs.getNumerator() * lhs.getDenominator());
		Integer newDenominator = lhs.getDenominator() * rhs.getDenominator();
		return Rational(newNumerator, newDenominator);
	}

	// An overload for the binary arithmetic operator *
	Rational operator*(const Rational &lhs, const Rational &rhs)
	{
		Integer newNumerator = lhs.getNumerator() * rhs.getNumerator();
		Integer newDenominator = lhs.getDenominator() * rhs.getDenominator();
		return Rational(newNumerator, newDenominator);
	}

	// An overload for the binary arithmetic operator /
	Rational operator/(const Rational &lhs, const Rational &rhs)
	{
		Integer newNumerator = lhs.getNumerator() * rhs.getDenominator();
		Integer newDenominator = lhs.getDenominator() * rhs.getNumerator();
		return Rational(newNumerator, newDenominator);
	}

	// An overload for the compound assignment operator +=
	Rational &Rational::operator+=(const Rational &r)
	{
		*this = *this + r;
		return *this;
	}

	// An overload for the compound assignment operator -=
	Rational &Rational::operator-=(const Rational &r)
	{
		*this = *this - r;
		return *this;
	}

	// An overload for the compound assignment operator *=
	Rational &Rational::operator*=(const Rational &r)
	{
		*this = *this * r;
		return *this;
	}

	// An overload for the compound assignment operator /=
	Rational &Rational::operator/=(const Rational &r)
	{
		*this = *this / r;
		return *this;
	}

	// An overload for the comparison operator ==
	bool operator==(const Rational &lhs, const Rational &rhs)
	{
		return (lhs.getNumerator() == rhs.getNumerator()) && (lhs.getDenominator() == rhs.getDenominator());
	}

	// An overload for the comparison operator !=
	bool operator!=(const Rational &lhs, const Rational &rhs)
	{
		return !operator==(lhs, rhs);
	}

	// An overload for the comparison operator <
	bool operator<(const Rational &lhs, const Rational &rhs)
	{
		return (lhs.getNumerator() * rhs.getDenominator()) < (rhs.getNumerator() * lhs.getDenominator());
	}

	// An overload for the comparison operator <=
	bool operator<=(const Rational &lhs, const Rational &rhs)
	{
		return (lhs.getNumerator() * rhs.getDenominator()) <= (rhs.getNumerator() * lhs.getDenominator());
	}

	// An overload for the comparison operator >
	bool operator>(const Rational &lhs, const Rational &rhs)
	{
		return (lhs.getNumerator() * rhs.getDenominator()) > (rhs.getNumerator() * lhs.getDenominator());
	}

	// An overload for the comparison operator >=
	bool operator>=(const Rational &lhs, const Rational &rhs)
	{
		return (lhs.getNumerator() * rhs.getDenominator()) >= (rhs.getNumerator() * lhs.getDenominator());
	}

	// An overload for the input stream operator >>
	std::ostream &operator<<(std::ostream &os, const Rational &rational)
	{
		if (rational.getDenominator() == Integer())
		{
			throw std::invalid_argument("Cannot divide by 0");
		}
		if (rational.getNumerator() > rational.getDenominator())
		{
			Rational temp(rational.getNumerator(), rational.getDenominator());
			temp = temp.simplify();
			// Case for when the numerator is greater than the denominator
			Integer quotient = temp.getNumerator() / temp.getDenominator();
			Integer remainder = temp.getNumerator() % temp.getDenominator();
			if (remainder == Integer())
			{
				os << quotient;
			}
			else
			{
				os << quotient << "." << remainder << "/" << temp.getDenominator();
			}
		}
		else if (rational.getNumerator() == rational.getDenominator())
		{
			// Case for when the numerator is equal to the denominator
			os << Integer("1");
		}
		else if (rational.getNumerator() == Integer())
		{
			// Case for when the numerator is 0
			os << "0";
		}
		else if (rational.getNumerator() < Integer())
		{
			// Case for when the numerator is negative
			Integer positiveNumerator = -rational.getNumerator();
			Rational temp(positiveNumerator, rational.getDenominator());
			temp = temp.simplify();
			Integer quotient = temp.getNumerator() / rational.getDenominator();
			Integer remainder = temp.getNumerator() % rational.getDenominator();

			os << "-";
			if (remainder == Integer())
			{
				os << quotient;
			}
			else if (quotient > Integer())
			{
				os << quotient << "." << remainder << "/" << temp.getDenominator();
			}
			else
			{
				os << temp.getNumerator() << "/" << temp.getDenominator();
			}
		}
		else
		{
			Rational temp(rational.getNumerator(), rational.getDenominator());
			temp = temp.simplify();
			// Case for when the numerator is positive
			os << temp.getNumerator() << "/" << temp.getDenominator();
		}
		return os;
	}

	// An overload for the output stream operator <<
	std::istream &operator>>(std::istream &is, Rational &i)
	{
		std::string input;
		if (std::getline(is, input))
		{
			i = Rational(input);
		}
		return is;
	}

	// A function to simplify a rational number
	Rational Rational::simplify() const
	{
		Integer gcd = Integer::gcd(getNumerator(), getDenominator());
		Integer simplifiedNumerator = getNumerator() / gcd;
		Integer simplifiedDenominator = getDenominator() / gcd;
		return Rational(simplifiedNumerator, simplifiedDenominator);
	}

	// A function to split a string into tokens by a given delimiter
	std::vector<std::string> splitString(const std::string &s, const std::string &delimiter)
	{
		std::vector<std::string> tokens;
		size_t start = 0;
		size_t end = s.find(delimiter);
		while (end != std::string::npos)
		{
			tokens.push_back(s.substr(start, end - start));
			start = end + delimiter.length();
			end = s.find(delimiter, start);
		}
		tokens.push_back(s.substr(start));
		return tokens;
	}
}
