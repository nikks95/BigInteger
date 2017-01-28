#pragma once

// LICENSE
// BigInteger.h
// version 0.0.0
// owner kartik
// this file comes with NO WARRANTY
// you are free to use and modify this file until but you must not edit or remove license
// to report bug or to request feature email kartik.thakur@hotmail.com

#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <stack>

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

	// assignment operator
	void operator = (BigInteger&);
	void operator = (string);

	// arithmetic operators

	BigInteger& operator + (BigInteger&);
	BigInteger& operator - (BigInteger&);

private:

	void UnsignedAddition(BigInteger&, BigInteger&, unsigned int, unsigned int, BigInteger&);
	void SignedAddition(BigInteger&, BigInteger&, unsigned int, unsigned int, BigInteger&);

	vector<int> integer_array; // hold integers values
	bool negative;     // true if the integer has negative magnitude

	void StoreString(string);
};

BigInteger& BigInteger::operator + (BigInteger& input)
{
	int input1_size = this->integer_array.size();
	int input2_size = input.integer_array.size();
	BigInteger result;
	stack<int> result_holder;
	int max = input1_size > input2_size ? input1_size : input2_size; // max no of iterations in loop
	int min = input1_size <= input2_size ? input1_size : input2_size;
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
			result.negative = this->negative;
		else
			result.negative = input.negative;
	else
		if (input1_size > input2_size)
			result.negative = this->negative;
		else
			result.negative = input.negative;

	// addition is performed in this loop
	if (negative == 3 || negative == 0);
		//		UnsignedAddition(*this, input, max, min, result);

	else;
//		SignedAddition(*this, input, max, min, result);

	return result;
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

	string padding = "0000000000";

	for (unsigned int i = 1; i < integer_array.size(); i++)
	{
		string integer = to_string(integer_array[i]);
		int padding = integer.length() % PAD_SIZE;
		if (padding > 0)
			padding = PAD_SIZE - padding;
		if (padding > 0)
		{
			for(int i = 0; i < padding; i++)
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