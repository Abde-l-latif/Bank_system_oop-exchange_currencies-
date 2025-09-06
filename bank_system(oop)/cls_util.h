#pragma once
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class cls_util
{
public :

	static string remove_zero_fragments(string Num)
	{
		// Remove trailing zeros
		while (!Num.empty() && Num.back() == '0')
			Num.pop_back();

		// If the last character is a dot, remove it
		if (!Num.empty() && Num.back() == '.')
			Num.pop_back();

		return Num;
	}

	static string encrypt_pass(string text, short unsigned int num)
	{
		for (int i = 0; i < text.length(); i++)
		{
			text[i] = char((int)text[i] + num);
		}
		return text;
	}

	static string decrypt_pass(string text, short unsigned int num)
	{
		for (int i = 0; i < text.length(); i++)
		{
			text[i] = char((int)text[i] - num);
		}
		return text;
	}

	static void s_rand()
	{
		srand((unsigned)time(NULL));
	}

	static int random_num_from_to(int from,  int to)
	{
		int randy = rand() % (to - from + 1) + from;
		return randy;
	}

	static enum estatus { small_letter = 1, capital_letter, special_character, digit };

	static char random_char(estatus input = estatus::small_letter)
	{
		switch (input)
		{
		case estatus::small_letter:
			return char(random_num_from_to(97, 122));
		case estatus::capital_letter:
			return char(random_num_from_to(65, 90)) ;
		case estatus::special_character:
			return char(random_num_from_to(33, 41)) ;
		case estatus::digit:
			return char(random_num_from_to(48, 57)) ;
		default:         
			return 'x';
		}
	}

	static string generate_random_word(estatus type, int length)
	{
		string word = "";
		for (int i = 1; i <= length; i++)
		{
			word += random_char(type);
		}
		return word;
	}

	static string generate_key(estatus type, int length = 4, int word_length = 4)
	{
		string key = "";
		for (int i = 1; i <= length; i++)
		{
			key += generate_random_word(type, word_length);
			if (i != length)
				key += '-';
		}
		return key;
	}
	
	static void print_generated_keys(int length, estatus type, int  word_length, int keys_length)
	{
		for (int i = 1; i <= keys_length; i++)
		{
			cout << "Key [" << i << "] : " << generate_key(type, length, word_length) << endl;
		}
	}

	static  void ShuffleArray(int arr[100], int arrLength)
	{

		for (int i = 0; i < arrLength; i++)
		{
			swap(arr[random_num_from_to(1, arrLength) - 1], arr[random_num_from_to(1, arrLength) - 1]);
		}

	}

	static  void ShuffleArray(string arr[100], int arrLength)
	{

		for (int i = 0; i < arrLength; i++)
		{
			swap(arr[random_num_from_to(1, arrLength) - 1], arr[random_num_from_to(1, arrLength) - 1]);
		}

	}

	static void swap(int & num , int & num2)
	{
		int temp = num;
		num = num2;
		num2 = temp; 
	}

	static void swap(double & num, double & num2)
	{
		double temp = num;
		num = num2;
		num2 = temp;
	}

	static void swap(string & s1, string & s2)
	{
		string temp = s1;
		s1 = s2;
		s2 = temp;
	}

	static string  Tabs(short NumberOfTabs)
	{
		string t = "";

		for (int i = 1; i < NumberOfTabs; i++)
		{
			t = t + "\t";
			cout << t;
		}
		return t;

	}

	static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = random_num_from_to(From, To);
	}

	static void FillArrayWithRandomWords(string arr[100], int arrLength, estatus CharType, short Wordlength)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = generate_random_word(CharType, Wordlength);

	}

	static void FillArrayWithRandomKeys(string arr[100], int arrLength, estatus CharType)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = generate_key(CharType);
	}

	static string convert_numbers(long long unsigned number)
	{
	
		string one_digit[] = { "" , "one" , "two" , "three" , "four" , "five" , "six" , "seven" , "eight" , "nine" };
		string teens_digits[] = { "ten" , "eleven" , "twelve" , "thirteen" , "fourteen" , "fifteen" , "sixteen" , "seventeen", "eighteen" , "nineteen" };
		string tens_digit[] = { "" , "" , "twenty" , "thirty" , "forty" , "fifty" , "sixty" , "seventy" , "eighty" , "ninety" };
	
		string result = "";
	
		if (number == 0)
			return "zero";
	
		if (number >= 1000000000)
		{
			result += convert_numbers(number / 1000000000) + " billion ";
			number %= 1000000000;
			if (!number)
				return result;
		}
	
		if (number >= 1000000)
		{
	
			result += convert_numbers(number / 1000000) + " million ";
	
			number %= 1000000;
	
			if (!number)
				return result;
	
		}
	
		if (number >= 1000)
		{
	
			result += convert_numbers(number / 1000) + " thousand ";
		 	number %= 1000;
			if (!number)
				return result;
		}
	
		if (number >= 100)
		{
			result += one_digit[number / 100] + " hundred ";
			number %= 100;
			if (!number)
				return result;
			result += " and ";
		}
	
		if (number >= 20)
		{
			result += tens_digit[number / 10];
			number %= 10;
			if (number)
				return result += "-" + one_digit[number];
			return result;
		}
	
		if (number >= 10)
			return result += teens_digits[number - 10];

		if (number < 10)
			return result += one_digit[number];
	
	
	
		return result; 
	}

};

