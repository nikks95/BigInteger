#pragma once

// LICENSE
// BigInteger.h
// version 0.0.0
// owner kartik
// this file comes with NO WARRANTY
// you are free to use and modify this file but you must not edit or remove LICENSE
// to report bug or to request feature email kartik.thakur@hotmail.com
//LICENSE


// WARNING! this file is not yet optimized if you are using it you may face performance issues

#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <stack>
#include <math.h>


// PAD_SIZE is an crucial feild it can improve performance with computer with better architectures and is this file is currently designed to support every computer
#define PAD_SIZE 8 // limit the value which can be stored in an integer for example 8 means maximum value which can be stored in an element of integer array is 99999999

using namespace std;

regex integer_expression("(\\+|-)?[[:digit:]]+"); // Regular Expression to check if the entered digit is valid or not

class BigInteger
{
public:
	// constructors
	BigInteger();
	BigInteger(string);
	BigInteger(BigInteger&);
	BigInteger(int);

	//return the stored array in form of string
	string ToString();

	// stdin stdout operators
	friend ostream& operator << (ostream&, BigInteger&);
	friend istream& operator >> (istream&, BigInteger&);

	// relational operators
	bool operator < (BigInteger&);
	bool operator > (BigInteger&);
	bool operator <= (BigInteger&);
	bool operator >= (BigInteger&);
	bool operator == (BigInteger&);
	bool operator != (BigInteger&);


	//---------------------------------------------
	//Operator Declared here will have added complexity avoid using them if not neccessary
	//use relational operators declared above
	bool operator < (string&);
	bool operator > (string&);
	bool operator <= (string&);
	bool operator >= (string&);
	bool operator == (string&);
	bool operator != (string&);

	bool operator < (int);
	bool operator > (int);
	bool operator <= (int);
	bool operator >= (int);
	bool operator == (int);
	bool operator != (int);
	//---------------------------------------------

	// assignment operator
	void operator = (BigInteger&);
	void operator = (string);
	void operator = (int);
	/*void operator = (long);
	void operator = (long long);
	void operator = (long int);
	void operator = (long long int);*/

	// arithmetic operators

	BigInteger operator + (BigInteger);
	BigInteger operator - (BigInteger);

	void operator += (BigInteger&);
	void operator -= (BigInteger&);

	BigInteger operator + (int);
	BigInteger operator - (int);
	void operator += (int);
	void operator -= (int);

	// postfix and prefix increment operators
	
	BigInteger operator ++ (int); // postfix increment
	BigInteger operator ++ (); // prefix increment
	BigInteger operator -- (int);
	BigInteger operator -- ();

private:

	
	void UnsignedAddition(BigInteger&, BigInteger&, BigInteger&);
	void SignedAddition(BigInteger&, BigInteger&, BigInteger&);

	vector<int> integer_array; // hold integers values
	bool negative;     // true if the integer has negative magnitude

	void StoreString(string);
};

BigInteger BigInteger::operator ++(int)
{
	BigInteger temp = *this;
	*this += 1;
	return temp;
}

BigInteger BigInteger::operator ++()
{
	*this += 1;
	return *this;
}

BigInteger BigInteger::operator -- (int)
{
	BigInteger temp = *this;
	*this -= 1;
	return temp;
}

BigInteger BigInteger::operator -- ()
{
	*this -= 1;
	return *this;
}


BigInteger BigInteger::operator + (int input)
{
	BigInteger temp = input;
	return *this + temp;
}

BigInteger BigInteger::operator - (int input)
{
	BigInteger temp = input;
	return *this - temp;
}

void BigInteger::operator += (int input)
{
	BigInteger temp = input;
	*this += temp;
}

void BigInteger::operator -= (int input)
{
	BigInteger temp = input;
	*this -= temp;
}

void BigInteger::operator += (BigInteger &input)
{
	*this = *this + input;
}

void BigInteger::operator -= (BigInteger &input)
{
	*this = *this - input;
}

bool BigInteger::operator < (int input)
{
	BigInteger temp = input;
	return *this < temp;
}

bool BigInteger::operator > (int input)
{
	BigInteger temp = input;
	return *this > temp;
}

bool BigInteger::operator <= (int input)
{
	BigInteger temp = input;
	return *this <= temp;
}

bool BigInteger::operator >= (int input)
{
	BigInteger temp = input;
	return *this >= temp;
}

bool BigInteger::operator == (int input)
{
	BigInteger temp = input;
	return *this == temp;
}

bool BigInteger::operator != (int  input)
{
	BigInteger temp = input;
	return *this != temp;
}

bool BigInteger::operator < (string &input)
{
	BigInteger temp(input);
	return *this < temp;
}

bool BigInteger::operator <= (string &input)
{
	BigInteger temp(input);
	return *this <= temp;
}

bool BigInteger::operator >= (string &input)
{
	BigInteger temp(input);
	return *this >= temp;
}

bool BigInteger::operator == (string &input)
{
	BigInteger temp(input);
	return *this == temp;
}

bool BigInteger::operator != (string &input)
{
	BigInteger temp(input);
	return *this != temp;
}

bool BigInteger::operator > (string &input)
{
	BigInteger temp(input);
	return *this > temp;
}

void BigInteger::operator = (int input)
{
	this->integer_array.clear();
	this->integer_array.resize(0);
	this->StoreString(to_string(input));
}

BigInteger BigInteger::operator - (BigInteger input)
{
	BigInteger result;
	if (this->negative && !input.negative)
		result.negative = true;
	else if (!this->negative && input.negative)
		result.negative = false;
	else
	{
		if (*this > input)
			result.negative = false;
		else
			result.negative = true;
		input.negative = !input.negative;
	}
	result = *this + input;
	return result;
}

// this operator is not optimized better operations can be done on it in future versions
BigInteger BigInteger::operator + (BigInteger input)
{
	int input1_size = this->integer_array.size(); //holds size of this
	int input2_size = input.integer_array.size(); //holds size of input
	BigInteger result;
	// negative value
	// if both are positive then 0
	// if operand 1 is negative then 1
	// if operand 2 is negative then 2
	// if both are negative than then 3
	int negative;
	if (this->negative && input.negative)
		negative = 3;
	else if (!this->negative && input.negative)
		negative = 2;
	else if (this->negative && !input.negative)
		negative = 1;
	else
		negative = 0;

	//determining the sign of result
	if (input1_size == input2_size)
		if (*this > input)
		{
			int i = 0;
			while (i < input1_size)
				if (this->integer_array[i] > input.integer_array[i])
				{
					result.negative = this->negative;
					break;
				}
				else if (this->integer_array[i] < input.integer_array[i])
				{
					result.negative = input.negative;
					break;
				}
				else
					i++;
		}
		else
			result.negative = input.negative;
	else
		if (input1_size > input2_size)
			result.negative = this->negative;
		else
			result.negative = input.negative;


	// addition is performed in this loop
	if (negative == 3 || negative == 0)
		UnsignedAddition(*this, input, result);

	else
		SignedAddition(*this, input, result);

	return result;
}

// not properly tested yet
void BigInteger::UnsignedAddition(BigInteger &input1, BigInteger &input2, BigInteger &result)
{
	int input1_size = input1.integer_array.size();
	int input2_size = input2.integer_array.size();
	stack<int> result_holder;
	int carry = 0;
	while (input1_size > 0 || input2_size > 0)
	{
		int result;
		input1_size--;
		input2_size--;
		if (input1_size >= 0 && input2_size >= 0)
		{
			result = input1.integer_array[input1_size] + input2.integer_array[input2_size] + carry;
			carry = 0;
			if (result >= (int)pow(10, PAD_SIZE))
			{
				result = result % (int)pow(10, PAD_SIZE);
				carry = 1;
			}
		}
		else if (input1_size >= 0)
		{
			result = input1.integer_array[input1_size] + carry;
			carry = 0;
			if (result >= (int)pow(10, PAD_SIZE))
			{
				result = result % (int)pow(10, PAD_SIZE);
				carry = 1;
			}
		}
		else
		{
			result = input2.integer_array[input2_size] + carry;
			carry = 0;
			if (result >= (int)pow(10, PAD_SIZE))
			{
				result = result % (int)pow(10, PAD_SIZE);
				carry = 1;
			}
		}
		result_holder.push(result);
	}
	if (carry == 1)
		result_holder.push(carry);
	while (!result_holder.empty())
	{
		result.integer_array.push_back(result_holder.top());
		result_holder.pop();
	}
	while (result.integer_array[0] == 0 && result.integer_array.size() > 1)
		result.integer_array.erase(result.integer_array.begin());
}

// not tested properly yet but working
void BigInteger::SignedAddition(BigInteger &input1, BigInteger &input2, BigInteger &result)
{
	int input1_size = input1.integer_array.size();
	int input2_size = input2.integer_array.size();
	stack<int> result_holder;

	int greater;
	if (input1_size == input2_size)
	{
		if (input1.integer_array == input2.integer_array)
		{
			result.negative = false;
			return;
		}
		else if (input1.integer_array[0] > input2.integer_array[0])
			greater = 1;
		else if (input1.integer_array[0] < input2.integer_array[0])
			greater = 2;
		else
		{
			int i = 1;
			while (i < input1_size)
				if (input1.integer_array[i] > input2.integer_array[i])
				{
					greater = 1;
					break;
				}
				else if (input1.integer_array[i] < input2.integer_array[i])
				{
					greater = 2;
					break;
				}
				else
					i++;
		}
	}
	else if (input1_size > input2_size)
		greater = 1;
	else
		greater = 2;


	int carry = 0;
	while (input1_size >0 || input2_size > 0)
	{
		input1_size--;
		input2_size--;
		if (input1_size >= 0 && input2_size >= 0)
		{
			int result;
			if (greater == 1 && (input1.integer_array[input1_size] + carry) < input2.integer_array[input2_size])
			{
				// this is true when input1 is greater in magnitude but its element is smaller than input2 element
				result = input1.integer_array[input1_size] + carry + (int)pow(10, PAD_SIZE) - input2.integer_array[input2_size];
				carry = -1;
			}
			else if (greater == 2 && input1.integer_array[input1_size] > (input2.integer_array[input2_size] + carry))
			{
				result = input2.integer_array[input2_size] + carry + (int)pow(10, PAD_SIZE) - input1.integer_array[input1_size];
				carry = -1;
			}
			else if (greater == 1)
			{
				result = input1.integer_array[input1_size] - input2.integer_array[input2_size] + carry;
				carry = 0;
			}
			else
			{
				result = input2.integer_array[input2_size] - input1.integer_array[input1_size] + carry;
				carry = 0;
			}
			result_holder.push(result);
		}
		else if (input1_size >= 0)
		{
			if (input1.integer_array[input1_size] == 0 && carry == -1)
				result_holder.push(carry + (int)pow(10, PAD_SIZE));
			else
			{
				result_holder.push(input1.integer_array[input1_size] + carry);
				carry = 0;
			}
		}
		else
		{
			if (input2.integer_array[input2_size] == 0 && carry == -1)
				result_holder.push(carry + (int)pow(10, PAD_SIZE));
			else
			{
				result_holder.push(input2.integer_array[input2_size] + carry);
				carry = 0;
			}
		}
	}
	result.integer_array.clear();
	while (!result_holder.empty())
	{
		result.integer_array.push_back(result_holder.top());
		result_holder.pop();
	}

	while (result.integer_array[0] == 0 && result.integer_array.size() > 1)
		result.integer_array.erase(result.integer_array.begin());
}

bool BigInteger::operator < (BigInteger& input)
{
	if (this->negative && !input.negative)
		return true;
	else if (!this->negative && input.negative)
		return false;
	else
	{
		unsigned int array_size = this->integer_array.size();
		unsigned int input_size = input.integer_array.size();
		if (array_size < input_size)
			return true;
		else if (array_size > input_size)
			return false;
		else
		{
			if (!this->negative)
			{
				unsigned int i = 0;
				while (i < array_size)
					if (this->integer_array[i] == input.integer_array[i])
						i++;
					else if (this->integer_array[i] < input.integer_array[i])
						return true;
					else
						return false;
			}
			else
			{
				unsigned int i = 0;
				while (i < array_size)
					if (this->integer_array[i] == input.integer_array[i])
						i++;
					else if (this->integer_array[i] > input.integer_array[i])
						return true;
					else
						return false;
			}
			return false;
		}
	}
}

bool BigInteger::operator > (BigInteger& input)
{
	if (!this->negative && input.negative)
		return true;
	else if (this->negative && !input.negative)
		return false;
	else
	{
		unsigned int array_size = this->integer_array.size();
		unsigned int input_size = input.integer_array.size();
		if (array_size > input_size)
			return true;
		else if (array_size < input_size)
			return false;
		else
		{
			if (!this->negative)
			{
				unsigned int i = 0;
				while (i < array_size)
					if (this->integer_array[i] == input.integer_array[i])
						i++;
					else if (this->integer_array[i] > input.integer_array[i])
						return true;
					else
						return false;
			}
			else
			{
				unsigned int i = 0;
				while (i < array_size)
					if (this->integer_array[i] == input.integer_array[i])
						i++;
					else if (this->integer_array[i] < input.integer_array[i])
						return true;
					else
						return false;
			}
			return false;
		}
	}
}

bool BigInteger::operator <= (BigInteger& input)
{
	if (this->negative && !input.negative)
		return true;
	else if (!this->negative && input.negative)
		return false;
	else
	{
		unsigned int array_size = this->integer_array.size();
		unsigned int input_size = input.integer_array.size();
		if (array_size < input_size)
			return true;
		else if (array_size > input_size)
			return false;
		else
		{
			if (!this->negative)
			{
				unsigned int i = 0;
				while (i < array_size)
					if (this->integer_array[i] == input.integer_array[i])
						i++;
					else if (this->integer_array[i] < input.integer_array[i])
						return true;
					else
						return false;
			}
			else
			{
				unsigned int i = 0;
				while (i < array_size)
					if (this->integer_array[i] == input.integer_array[i])
						i++;
					else if (this->integer_array[i] > input.integer_array[i])
						return true;
					else
						return false;
			}
			return true;
		}
	}
}

bool BigInteger::operator >= (BigInteger &input)
{
	if (!this->negative && input.negative)
		return true;
	else if (this->negative && !input.negative)
		return false;
	else
	{
		unsigned int array_size = this->integer_array.size();
		unsigned int input_size = input.integer_array.size();
		if (array_size > input_size)
			return true;
		else if (array_size < input_size)
			return false;
		else
		{
			if (!this->negative)
			{
				unsigned int i = 0;
				while (i < array_size)
					if (this->integer_array[i] == input.integer_array[i])
						i++;
					else if (this->integer_array[i] > input.integer_array[i])
						return true;
					else
						return false;
			}
			else
			{
				unsigned int i = 0;
				while (i < array_size)
					if (this->integer_array[i] == input.integer_array[i])
						i++;
					else if (this->integer_array[i] < input.integer_array[i])
						return true;
					else
						return false;
			}
			return true;
		}
	}
}

bool BigInteger::operator == (BigInteger & input)
{
	if (this->negative != input.negative)
		return false;
	else
	{
		unsigned int array_size = this->integer_array.size();
		unsigned int input_size = input.integer_array.size();
		if (array_size != input_size)
			return false;
		else
		{
			unsigned int i = 0;
			while (i < array_size)
				if (this->integer_array[i] == input.integer_array[i])
					i++;
				else
					return false;
			return true;
		}
	}
}

bool BigInteger::operator != (BigInteger& input)
{
	return !(*this == input);
}

void BigInteger::operator = (BigInteger& input)
{
	this->integer_array.clear();
	this->integer_array.resize(0);
	this->negative = input.negative;
	this->integer_array.assign(input.integer_array.begin(), input.integer_array.end());
}

void BigInteger::operator= (string input)
{
	this->integer_array.clear();
	this->integer_array.resize(0);
	this->StoreString(input);
}

BigInteger::BigInteger()
{
	negative = false;
	integer_array.push_back(0);
}

BigInteger::BigInteger(string input)
{
	negative = false;
	StoreString(input);
}

BigInteger::BigInteger(BigInteger& input)
{
	this->negative = input.negative;
	this->integer_array.assign(input.integer_array.begin(), input.integer_array.end());
}

BigInteger::BigInteger(int input)
{
	negative = false;
	this->StoreString(to_string(input));
}

void BigInteger::StoreString(string str)
{
	string input(str.begin(), str.end());
	if (!regex_match(input.begin(), input.end(), integer_expression))
	{
		cerr << "not a valid integer\nprogram will exit now!";
		getchar();
		exit(-1);
	}
	else
	{
		if (input[0] == '+') // if integer string is starting with + then remove +
			input.erase(input.begin());
		else if (input[0] == '-') // if integer string is starting with - then make signed = true and remove -
		{
			negative = true;
			input.erase(input.begin());
		}
		// making input string compatible with further algorithm
		int padding;
		padding = input.length() % PAD_SIZE;

		if (padding > 0)
			padding = PAD_SIZE - padding;

		if (padding > 0)
			for (int i = 0; i < padding; i++)
				input = "0" + input;

		// storing string in an integer array made up of vector
		for (unsigned int i = 0; i < input.length(); i += PAD_SIZE)
		{
			string integer(input, i, PAD_SIZE);
			integer_array.push_back(atoi(integer.c_str()));
		}

		// remove zeroes from start of integer array because they doesn't contribute to the value of integer
		while (true)
			if (integer_array[0] == 0 && integer_array.size() > 1)
				integer_array.erase(integer_array.begin());
			else
				break;
	}
}

string BigInteger::ToString()
{
	string output = "";
	//if negative is true that means that integer array has negative magnitude
	if (negative)
		output = "-";

	output += to_string(integer_array[0]); // first integer is added manually because to avoid padded zeroes in the start of string i.e. output

	string padding = "000000000000000000000000";

	for (unsigned int i = 1; i < integer_array.size(); i++)
	{
		string integer = to_string(integer_array[i]);
		int padding = integer.length() % PAD_SIZE;
		if (padding > 0)
			padding = PAD_SIZE - padding;
		if (padding > 0)
		{
			for (int i = 0; i < padding; i++)
				integer = "0" + integer;
		}
		output += integer;
	}
	return output;
}

ostream& operator << (ostream& output_stream, BigInteger &input)
{
	output_stream << input.ToString();
	return output_stream;
}

istream& operator >> (istream& input_stream, BigInteger &output)
{
	output.integer_array.clear();
	output.integer_array.resize(0);
	string input;
	input_stream >> input;
	output.StoreString(input);
	getchar();
	return input_stream;
}
