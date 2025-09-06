#pragma once
#include <iostream>
#include <vector>

using namespace std; 

class cls_string
{
private : 

	string _value;

public :

	// handel value 

	cls_string()
	{
		_value = "";
	}

	cls_string(string val)
	{
		_value = val;
	}

	void set_value(string val)
	{
		_value = val;
	}

	string get_value()
	{
		return _value;
	}
	
	_declspec(property(get = get_value, put = set_value)) string value;

	// string functions 

	static char get_first_letter_of_words(string sentence)
	{
		for (int i = 0; i < sentence.length(); i++)
		{
			if (i == 0 && sentence.at(i) != ' ')
				return sentence.at(i);

			if ((i + 1) < sentence.length() && sentence.at(i + 1) != ' ')
			    return sentence.at(i + 1);
		}
	}
	char get_first_letter_of_words()
	{
		return get_first_letter_of_words(this->value); 
	}
	//---------------
	static string convert_first_letter_of_words_upper(string sentence)
	{
		bool first_letter = true;

		for (short i = 0; i < sentence.length(); i++)
		{
			if (sentence.at(i) != ' ' && first_letter)
			{
				sentence.at(i) = toupper(sentence.at(i));

			}

			sentence.at(i) == ' ' ? first_letter = true : first_letter = false;
		}

		return sentence;
	}
	void convert_first_letter_of_words_upper()
	{
		_value = convert_first_letter_of_words_upper(this->value);
	}
	//---------------
	static string convert_first_letter_of_words_lower(string sentence)
	{
		bool first_letter = true;

		for (short i = 0; i < sentence.length(); i++)
		{
			if (sentence.at(i) != ' ' && first_letter)
			{
				sentence.at(i) = tolower(sentence.at(i));

			}

			sentence.at(i) == ' ' ? first_letter = true : first_letter = false;
		}

		return sentence;
	}
	void convert_first_letter_of_words_lower()
	{
		_value = convert_first_letter_of_words_upper(this->value);
	}
	//---------------
	static string convert_to_upper(string sentence)
	{
		string upper_text = "";

		for (short i = 0; i < sentence.length(); i++)
		{
			upper_text += toupper(sentence[i]);
		}

		return upper_text;
	}
	void convert_to_upper()
	{
		_value = convert_to_upper(this->value); 
	}
	//---------------
	static string convert_to_lower(string sentence)
	{
		string lower_text = "";

		for (short i = 0; i < sentence.length(); i++)
		{
			lower_text += tolower(sentence[i]);
		}

		return lower_text;
	}
	void convert_to_lower()
	{
		_value = convert_to_lower(this->value);
	}
	//---------------
	enum e_case { upper = 1, lower };
	static e_case check_char_case(char chary)
	{
		return isupper(chary) ? e_case::upper : e_case::lower;
	}
	static char invert_char(char chary)
	{
		e_case char_case = check_char_case(chary);

		switch (char_case)
		{
			case e_case::upper:
				return tolower(chary);
			case e_case::lower:
				return toupper(chary);
		}
	}
	//---------------
	static string invert_string_case(string sentence)
	{
		string text = "";

		for (short i = 0; i < sentence.length(); i++)
		{
			if (sentence[i] == ' ')
			{
				text += ' ';
				continue;
			}
			text += invert_char(sentence[i]);
		}
		return text;
	}
	void invert_string_case()
	{
		_value = invert_string_case(this->value);
	}
	//---------------
	static short count_capital_letters(string sentence)
	{
		short counter = 0;

		for (short i = 0; i < sentence.length(); i++)
		{
			if (sentence[i] == ' ')
				continue;

			e_case char_case = check_char_case(sentence[i]);

			if (char_case == e_case::upper)
				counter++;
			else
				continue;
		}

		return counter;
	}
	short count_capital_letters()
	{
		return count_capital_letters(this->value);
	}
	static short count_small_letters(string sentence)
	{
		short counter = 0;

		for (short i = 0; i < sentence.length(); i++)
		{
			if (sentence[i] == ' ')
				continue;

			e_case char_case = check_char_case(sentence[i]);

			if (char_case == e_case::lower)
				counter++;
			else
				continue;
		}

		return counter;
	}	
	short count_small_letters()
	{
		return count_small_letters(this->value);
	}
	//---------------
	static short count_letter_in_sentence(string sentence, char letter)
	{
		short counter = 0;
		for (short i = 0; i < sentence.length(); i++)
		{
			if (sentence.at(i) == letter)
				counter++;
		}
		return counter;
	}
	short count_letter_in_sentence(char letter)
	{
		return count_letter_in_sentence(this->value, letter);
	}
	//---------------
	enum e_status { sensitive, not_sensitive };
	static short count_letter_in_sentence_status(string sentence, char letter, bool status)
	{
		status == true ? status = e_status::sensitive : e_status::not_sensitive; 

		short counter = 0;
		for (short i = 0; i < sentence.length(); i++)
		{
			switch (status)
			{
				case e_status::sensitive:
				{
					if (sentence[i] == letter)
					counter++;
					break;
				}
				case e_status::not_sensitive:
				{
					if (sentence[i] == toupper(letter) || sentence[i] == tolower(letter))
					counter++;
					break;
				}
			}

		}
		return counter;
	}
	short count_letter_in_sentence_status(char letter, bool status)
	{
		return count_letter_in_sentence_status(this->value, letter, status);
	}
	//---------------
	static bool IsVowelLetter(char Ch1)
	{
		Ch1 = tolower(Ch1);

		return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
	}
	//---------------
	static short count_vowels(string sentence)
	{
		short counter = 0;

		for (short i = 0; i < sentence.length(); i++)
		{
			if (IsVowelLetter(sentence[i])) {
				counter++;
			}
		}
		return counter;
	}
	short count_vowels()
	{
		return count_vowels(this->value);
	}
	//---------------
	static void print_vowel_letters(string sentence)
	{
		cout << "vowel letters is : ";
		for (short i = 0; i < sentence.length(); i++)
		{
			if (IsVowelLetter(sentence[i])) {
				cout << "  " << sentence[i] << "  ";
			}
		}
		cout << endl;
	}
	void print_vowel_letters()
	{
		print_vowel_letters(this->value);
	}
	//---------------
	static void PrintEachWordInString (string S1)
	{
		string delim = " ";
		short pos = 0;
		string sWord = "";

		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos);
			if (sWord != "")
				cout << sWord << endl;

			S1.erase(0, pos + delim.length());
		}

		if (S1 != "")
			cout << S1 << endl;
	}
	void PrintEachWordInString()
	{
		PrintEachWordInString(_value);
	}
	//---------------
	static short count_word_of_sentence(string sentence)
	{
		string destination = " ";
		short position = 0;
		short counter = 0;
	
		while ((position = sentence.find(destination)) != std::string::npos)
		{
			counter++;
			sentence.erase(0, position + destination.length());
		}
	
		if (sentence != "")
		{
			counter++;
		}
	
		return counter;
	
	}
	short count_word_of_sentence()
	{
		return count_word_of_sentence(_value);
	}
	//---------------
	static vector <string> SplitString(string S1, string Delim)
	{
		short pos = 0;
		string sWord = "";
		vector <string> vString;

		while ((pos = S1.find(Delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos);
			if (sWord != "")
			{
				vString.push_back(sWord);
			}

			S1.erase(0, pos + Delim.length());
		}

		if (S1 != "")
		{
			vString.push_back(S1);
		}

		return vString;
	}
	static void Print_words_of_string(string SS , string delim)
	{
		vector <string> vString = SplitString(SS, delim);

		for (const string& Word : vString)
		{
			cout << Word << endl;
		}
		cout << endl;
	}
	void Print_words_of_string()
	{
		vector <string> vString = SplitString(_value , " ");

		for (const string& Word : vString)
		{
			cout << Word << endl;
		}
		cout << endl;
	}
	//---------------
	static string TrimLeft(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(i, S1.length() - i);
			}
		}
		return S1;
	}
	void TrimLeft()
	{
		_value = TrimLeft(_value);
	}
	static string TrimRight(string S1)
	{
		for (short i = (S1.length() - 1); i >= 0; i--)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(0, i + 1);
			}
		}

		return S1;
	}
	void TrimRight()
	{
		_value =  TrimRight(_value);
	}
	static string Trim(string S1)
	{
		return TrimLeft(TrimRight(S1));
	}
	void Trim()
	{
		_value =  TrimLeft(TrimRight(_value));
	}
	//---------------
	static string JoinString(string SS, string Delim = " ")
	{
		vector <string> vString = SplitString(SS, " ");

		string S1 = "";

		for (const string& Word : vString)
		{
			S1 += Word + Delim;
		}

		return (S1.substr(0, S1.length() - Delim.length()));
	}
	void JoinString(string Delim = " ")
	{
		_value =  JoinString(_value, Delim);
	}
	static string Join_String(vector <string>& vString, string Delim)
	{
		string S1 = "";

		for (const string& Word : vString)
		{
			S1 += Word + Delim;
		}

		return (S1.substr(0, S1.length() - Delim.length()));
	}
	static string JoinString(string ArrString[100], short Length, string Delim)
	{
		string S1 = "";

		for (short i = 0; i < Length; i++)
		{
			S1 += ArrString[i] + Delim;
		}

		return (S1.substr(0, S1.length() - Delim.length()));
	}
	//---------------
	static string ReverseWordsInString(string S1)
	{
		vector <string> vString = SplitString(S1, " ");

		string S2 = "";

		vector <string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{
			--iter;

			S2 += *iter + " ";
		}

		S2 = S2.substr(0, S2.length() - 1);

		return S2;
	}
	void ReverseWordsInString()
	{
		_value =  ReverseWordsInString(_value);
	}
	//---------------
	static string ReplaceWordsInString(string S1,string StringToReplace,string sReplaceTo)
	{
		short pos = S1.find(StringToReplace);

		while (pos != std::string::npos)
		{
			S1 = S1.replace(pos, StringToReplace.length(), sReplaceTo);

			pos = S1.find(StringToReplace);
		}

		return S1;
	}
	void ReplaceWordsInString(string StringToReplace, string sReplaceTo)
	{
		_value = ReplaceWordsInString(_value, StringToReplace, sReplaceTo);
	}
	//---------------
	static string RemoveAllPuncuationsFromString(string S1)
	{
		string S2 = "";

		for (short i = 0; i < S1.length(); i++)
		{
			if (!ispunct(S1[i]))
				S2 += S1[i];
		}

		return S2;
	}
	void RemoveAllPuncuationsFromString() {
		_value =  RemoveAllPuncuationsFromString(_value); 
	}

};

