#include "Integer.h"

#include <iostream>
#include <ostream>
#include <string>
#include <vector>

namespace cosc326
{
	// A default constructor that creates Integer with a value of 0
	Integer::Integer() : isNegative(false), digits({0}) {}

	// A copy constructor that creates a deep copy of the Integer passed in
	Integer::Integer(const Integer &i) : isNegative(i.isNegative), digits(i.digits) {}

	// A constructor that takes a string and creates an Integer with the same value
	Integer::Integer(const std::string &s)
	{
		int length, startIndex;
		if (s[0] == '+' || s[0] == '-')
		{
			length = s.length() - 1;
			startIndex = 1;
		}
		else
		{
			length = s.length();
			startIndex = 0;
		}
		digits.resize(length);
		int j = 0;
		for (int i = startIndex; i < s.length(); i++)
		{
			digits[j++] = s[i] - '0';
		}
		isNegative = s[0] == '-';
	}

	// A constructor that takes a bool and a vector of ints and creates an Integer with the same value
	Integer::Integer(bool isNegative, const std::vector<int> &digits) : isNegative(isNegative), digits(digits) {}

	// Default destructor
    Integer::~Integer() {}

	// An overload for the unary operator +
	Integer Integer::operator+() const
	{
		// Return a copy of the current object
		return *this;
	}

	// An overload for the unary operator -
	Integer Integer::operator-() const
	{
		// Create a copy of the current object and toggle the isNegative flag
		Integer result(*this);
		result.setIsNegative(!result.getIsNegative());
		return result;
	}

	// A getter for the isNegative flag
	bool Integer::getIsNegative() const
	{
		return isNegative;
	}

	// A getter for the digits vector
	const std::vector<int> &Integer::getDigits() const
	{
		return digits;
	}

	// A setter for the isNegative flag
	void Integer::setIsNegative(bool negative)
	{
		isNegative = negative;
	}

	// A setter for the digits vector
	void Integer::setDigits(const std::vector<int> &newDigits)
	{
		digits = newDigits;
	}

	// An overload for the assingment operator =
	Integer &Integer::operator=(const Integer &i)
	{
		if (this == &i)
		{ // Self-assignment check
			return *this;
		}
		isNegative = i.isNegative;
		digits = i.digits;
		return *this;
	}

	// An overlaod for the binary arithmetic operator +
	Integer operator+(const Integer &lhs, const Integer &rhs)
	{
		bool isNegative;

		// Check if the result is negative
		if (lhs.getIsNegative() && !rhs.getIsNegative())
		{
			// Case for (-a) + b
			Integer lhsTemp(lhs);
			lhsTemp.setIsNegative(false);
			return rhs - lhsTemp;
		}
		else if (!lhs.getIsNegative() && rhs.getIsNegative())
		{
			// Case for a + (-b)
			Integer rhsTemp(rhs);
			rhsTemp.setIsNegative(false);
			return lhs - rhsTemp;
		}
		else if (!lhs.getIsNegative() && !rhs.getIsNegative())
		{
			// Case for a + b
			isNegative = false;
		}
		else
		{
			// Case for (-a) + (-b)
			isNegative = true;
		}
		const std::vector<int> &lhsDigits = lhs.getDigits();
		const std::vector<int> &rhsDigits = rhs.getDigits();
		int lhsLength = lhsDigits.size();
		int rhsLength = rhsDigits.size();
		int resultLength = std::max(lhsLength, rhsLength) + 1; 
		std::vector<int> resultArray(resultLength);			 
		int lhsIndex = lhsLength - 1;						  
		int rhsIndex = rhsLength - 1;						  
		int carry = 0;										 
		while (resultLength > 0)
		{
			int sum;
			if (lhsIndex >= 0 && rhsIndex >= 0)
			{
				sum = lhsDigits[lhsIndex--] + rhsDigits[rhsIndex--] + carry;
			}
			else if (lhsIndex >= 0)
			{
				sum = lhsDigits[lhsIndex--] + carry;
			}
			else if (rhsIndex >= 0)
			{
				sum = rhsDigits[rhsIndex--] + carry;
			}
			else
			{
				sum = carry;
			}
			resultArray[resultLength - 1] = sum % 10;
			carry = sum / 10;
			resultLength--;
		}
		return Integer(isNegative, Integer::removeLeadingZeros(resultArray));
	}

	// An overload for the binary arithmetic operator -
	Integer operator-(const Integer &lhs, const Integer &rhs)
	{
		if (!lhs.getIsNegative() && rhs.getIsNegative())
		{ // Case for a - (-b)
			Integer lhsTemp(lhs);
			lhsTemp.setIsNegative(false);
			Integer rhsTemp(rhs);
			rhsTemp.setIsNegative(false);
			return lhsTemp + rhsTemp;
		}
		else if (lhs.getIsNegative() && !rhs.getIsNegative())
		{ // Case for (-a) - b
			Integer lhsTemp(lhs);
			lhsTemp.setIsNegative(true);
			Integer rhsTemp(rhs);
			rhsTemp.setIsNegative(true);
			return lhsTemp + rhsTemp;
		}
		else if (lhs.getIsNegative() && rhs.getIsNegative())
		{ // Case for (-a) - (-b)
			Integer rhsTemp(rhs);
			rhsTemp.setIsNegative(false);
			return lhs + rhsTemp;
		}
		else
		{
			bool isNegative;
			std::vector<int> largerDigitCopy = (lhs >= rhs) ? lhs.getDigits() : rhs.getDigits();
			std::vector<int> &largerDigit = largerDigitCopy;
			const std::vector<int> &smallerDigit = (lhs >= rhs) ? rhs.getDigits() : lhs.getDigits();
			if (lhs >= rhs)
			{
				isNegative = false;
			}
			else
			{
				isNegative = true;
			}
			int biggestLength = largerDigit.size();
			int smallestLength = smallerDigit.size();
			int largerIndex = biggestLength - 1;   
			int smallerIndex = smallestLength - 1;
			std::vector<int> resultArray(biggestLength);
			int difference = 0;
			while (biggestLength > 0)
			{
				if (smallestLength > 0)
				{
					if (largerDigit[largerIndex] - smallerDigit[smallerIndex] < 0)
					{
						difference = largerDigit[largerIndex--] - smallerDigit[smallerIndex--] + 10;
						int tempIndex = largerIndex;
						while (largerDigit[tempIndex] == 0)
						{
							int tempValue = largerDigit[tempIndex];
							tempValue = 9;
							largerDigit[tempIndex] = tempValue;
							tempIndex--;
						}
						largerDigit[tempIndex]--;
					}
					else
					{
						difference = largerDigit[largerIndex--] - smallerDigit[smallerIndex--];
					}
				}
				else
				{
					difference = largerDigit[largerIndex--];
				}
				resultArray[biggestLength - 1] = difference;
				biggestLength--;
				smallestLength--;
			}
			return Integer(isNegative, Integer::removeLeadingZeros(resultArray));
		}
	}

	// An overload for the binary arithmetic operator *
	Integer operator*(const Integer &lhs, const Integer &rhs)
	{
		bool isNegative = lhs.getIsNegative() ^ rhs.getIsNegative(); 
		const std::vector<int> &lhsDigits = lhs.getDigits();
		const std::vector<int> &rhsDigits = rhs.getDigits();
		int lhsLength = lhsDigits.size();
		int rhsLength = rhsDigits.size();
		std::vector<int> resultArray(lhsLength + rhsLength); 
		for (int i = lhsLength - 1; i >= 0; i--)
		{
			int carry = 0; 
			for (int j = rhsLength - 1; j >= 0; j--)
			{
				int product = lhsDigits[i] * rhsDigits[j] + carry + resultArray[i + j + 1];
				resultArray[i + j + 1] = product % 10;									
				carry = product / 10;													
			}
			resultArray[i] += carry;
		}
		return Integer(isNegative, Integer::removeLeadingZeros(resultArray));
	}

	// An overload for the binary arithmetic operator /
	Integer operator/(const Integer &lhs, const Integer &rhs)
	{
		bool isNegative = lhs.getIsNegative() ^ rhs.getIsNegative();
		if (isNegative == false && lhs < rhs)
		{
			return Integer();
		}
		else if (lhs == rhs)
		{
			return Integer("1");
		}
		else
		{
			std::vector<int> dividend = lhs.getDigits();
			std::vector<int> divisor = rhs.getDigits();
			std::vector<int> quotient(dividend.size(), 0);
			int dividendIndex = divisor.size() - 1;
			Integer dividendTemp(false, std::vector<int>(dividend.begin(), dividend.begin() + dividendIndex + 1));
			Integer divisorTemp(false, divisor);
			while (dividendIndex < dividend.size())
			{
				int multiple = 0;
				while ((dividendTemp - divisorTemp) >= Integer())
				{
					dividendTemp = dividendTemp - divisorTemp;
					multiple++;
				}
				quotient[dividendIndex] = multiple;
				dividendIndex++;
				if (dividendIndex < dividend.size())
				{
					std::vector<int> temporary;
					if (dividendTemp == Integer())
					{
						temporary.resize(dividendTemp.getDigits().size());
					}
					else
					{
						temporary.resize(dividendTemp.getDigits().size() + 1);
					}
					std::copy(dividendTemp.getDigits().begin(), dividendTemp.getDigits().end(), temporary.begin());
					temporary[temporary.size() - 1] = dividend[dividendIndex];
					dividendTemp = Integer(false, temporary);
				}
			}
			return Integer(isNegative, Integer::removeLeadingZeros(quotient));
		}
	}

	// An overload for the binary arithmetic operators %
	Integer operator%(const Integer &lhs, const Integer &rhs)
	{
		bool isNegative = lhs.getIsNegative();
		if (isNegative == false && lhs < rhs)
		{
			return lhs;
		}
		else
		{
			std::vector<int> dividend = lhs.getDigits();
			std::vector<int> divisor = rhs.getDigits();
			int dividendIndex = divisor.size() - 1;
			Integer dividendTemp(false, std::vector<int>(dividend.begin(), dividend.begin() + dividendIndex + 1));
			Integer divisorTemp(false, divisor);
			while (dividendIndex < dividend.size())
			{
				while ((dividendTemp - divisorTemp) >= Integer())
				{
					dividendTemp = dividendTemp - divisorTemp;
				}

				if (dividendIndex < dividend.size() - 1)
				{
					std::vector<int> temporary;
					if (dividendTemp == Integer())
					{
						temporary.resize(dividendTemp.getDigits().size());
					}
					else
					{
						temporary.resize(dividendTemp.getDigits().size() + 1);
					}
					std::copy(dividendTemp.getDigits().begin(), dividendTemp.getDigits().end(), temporary.begin());
					temporary[temporary.size() - 1] = dividend[dividendIndex + 1];
					dividendTemp = Integer(false, temporary);
				}
				dividendIndex++;
			}
			return Integer(isNegative, Integer::removeLeadingZeros(dividendTemp.getDigits()));
		}
	}

	// An overload for the compound assignment operator +=
	Integer &Integer::operator+=(const Integer &i)
	{
		*this = *this + i;
		return *this;
	}

	// An overload for the compound assignment operator -=
	Integer &Integer::operator-=(const Integer &i)
	{
		*this = *this - i;
		return *this;
	}

	// An overload for the compound assignment operator *=
	Integer &Integer::operator*=(const Integer &i)
	{
		*this = *this * i;
		return *this;
	}

	// An overload for the compound assignment operator /=
	Integer &Integer::operator/=(const Integer &i)
	{
		*this = *this / i;
		return *this;
	}

	// An overload for the compound assignment operator %=
	Integer &Integer::operator%=(const Integer &i)
	{
		*this = *this % i;
		return *this;
	}

	// An overload for the comparison operator ==
	bool operator==(const Integer &lhs, const Integer &rhs)
	{
		if (lhs.getIsNegative() != rhs.getIsNegative())
		{
			return false;
		}
		const std::vector<int> &lhsDigits = lhs.getDigits();
		const std::vector<int> &rhsDigits = rhs.getDigits();
		if (lhsDigits.size() != rhsDigits.size())
		{
			return false;
		}
		for (size_t i = 0; i < lhsDigits.size(); i++)
		{
			if (lhsDigits[i] != rhsDigits[i])
			{
				return false;
			}
		}
		return true;
	}

	// An overload for the comparison operator !=
	bool operator!=(const Integer &lhs, const Integer &rhs)
	{
		if (lhs.getIsNegative() != rhs.getIsNegative())
		{
			return true;
		}
		const std::vector<int> &lhsDigits = lhs.getDigits();
		const std::vector<int> rhsDigits = rhs.getDigits();
		if (lhsDigits.size() != rhsDigits.size())
		{
			return true;
		}
		for (size_t i = 0; i < lhsDigits.size(); ++i)
		{
			if (lhsDigits[i] != rhsDigits[i])
			{
				return true;
			}
		}
		return false;
	}

	// An overload for the comparison operator <
	bool operator<(const Integer &lhs, const Integer &rhs)
	{
		if (lhs.getIsNegative() && !rhs.getIsNegative())
		{
			return true;
		}
		else if (!lhs.getIsNegative() && rhs.getIsNegative())
		{
			return false;
		}
		else
		{
			const std::vector<int> &lhsDigits = lhs.getDigits();
			const std::vector<int> &rhsDigits = rhs.getDigits();
			if (lhsDigits.size() < rhsDigits.size())
			{
				return true;
			}
			else if (lhsDigits.size() > rhsDigits.size())
			{
				return false;
			}
			else
			{
				for (size_t i = 0; i < lhsDigits.size(); i++)
				{
					if (lhsDigits[i] < rhsDigits[i])
					{
						return true;
					}
					else if (lhsDigits[i] > rhsDigits[i])
					{
						return false;
					}
				}
				return false;
			}
		}
	}

	// An overload for the comparison operator <=
	bool operator<=(const Integer &lhs, const Integer &rhs)
	{
		return (lhs < rhs) || (lhs == rhs);
	}

	// An overload for the comparison operator >
	bool operator>(const Integer &lhs, const Integer &rhs)
	{
		if (lhs.getIsNegative() && !rhs.getIsNegative())
		{
			return false;
		}
		else if (!lhs.getIsNegative() && rhs.getIsNegative())
		{
			return true;
		}
		else
		{
			const std::vector<int> &lhsDigits = lhs.getDigits();
			const std::vector<int> &rhsDigits = rhs.getDigits();
			if (lhsDigits.size() > rhsDigits.size())
			{
				return true;
			}
			else if (lhsDigits.size() < rhsDigits.size())
			{
				return false;
			}
			else
			{
				for (size_t i = 0; i < lhsDigits.size(); i++)
				{
					if (lhsDigits[i] > rhsDigits[i])
					{
						return true;
					}
					else if (lhsDigits[i] < rhsDigits[i])
					{
						return false;
					}
				}
				return false;
			}
		}
	}

	// An overload for the comparison operator >=
	bool operator>=(const Integer &lhs, const Integer &rhs)
	{
		return (lhs > rhs) || (lhs == rhs);
	}

	// An overload for the streaming insertion operator <<
	std::ostream &operator<<(std::ostream &os, const Integer &obj)
	{
		if (obj.getIsNegative())
		{
			os << "-";
		}
		for (int digit : obj.getDigits())
		{
			os << digit;
		}
		return os;
	}

	// An overload for the streaming extraction operator >>
	std::istream &operator>>(std::istream &is, Integer &i)
	{
		std::string input;
		is >> input;
		i = Integer(input); 
		return is;
	}

	// A function that calculates the greatest common divisor (GCD) of two integers using the Euclidean algorithm.
	Integer Integer::gcd(const Integer &a, const Integer &b)
	{
		std::vector<int> largerArray;
		std::vector<int> smallerArray;
		if (a > b)
		{
			largerArray = a.getDigits();
			smallerArray = b.getDigits();
		}
		else
		{
			largerArray = b.getDigits();
			smallerArray = a.getDigits();
		}
		Integer largerDigit(false, largerArray);
		Integer smallerDigit(false, smallerArray);
		if (a == b)
		{
			return a;
		}
		else
		{
			while (smallerDigit != Integer())
			{
				Integer temp = smallerDigit;
				smallerDigit = largerDigit % smallerDigit;
				largerDigit = temp;
			}
			return largerDigit; 
		}
	}

	// A function that removes leading zeros from a vector of digits representing an integer.
	std::vector<int> Integer::removeLeadingZeros(const std::vector<int> &digits)
	{
		int i = 0;
		while (i < digits.size() && digits[i] == 0)
		{
			i++;
		}
		if (i == digits.size())
		{
			return std::vector<int>{0};
		}
		std::vector<int> result(digits.begin() + i, digits.end());
		return result;
	}
}
