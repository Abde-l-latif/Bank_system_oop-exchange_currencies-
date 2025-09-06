#pragma warning(disable : 4996)
#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class cls_date
{
private:
	short _day;
	short _month;
	short _year;

public:

	cls_date()
	{
		time_t time_sec = time(0);
		tm* now = localtime(&time_sec);
		_day = now->tm_mday;
		_month = now->tm_mon + 1;
		_year = now->tm_year + 1900;
	}
	cls_date(short _day, short _month, short _year)
	{
		this->_day = _day;
		this->_month = _month;
		this->_year = _year;
	}
	cls_date(short _day, short _year)
	{
		convert_days_to_date(_day, _year);
		this->_year = _year;
	}
	string convert_date_to_string()
	{
		string text = "";
		text += to_string(_day) + "/";
		text += to_string(_month) + "/";
		text += to_string(_year);
		return text;
	}
	string convert_time_to_string()
	{
		time_t time_sec = time(0);
		tm* now = localtime(&time_sec);
		short hours = now->tm_hour;
		short minutes = now->tm_min;
		short seconds = now->tm_sec;
		string text = "";
		text += to_string(hours) + ":";
		text += to_string(minutes) + ":";
		text += to_string(seconds);
		return text;
	}

	void set_day(short _day)
	{
		this->_day = _day;
	}
	short day()
	{
		return _day;
	}
	void set_month(short _month)
	{
		this->_month = _month;
	}
	short month()
	{
		return _month;
	}
	void set_year(short _year)
	{
		this->_year = _year;
	}
	short year()
	{
		return _year;
	}

	static bool check_leap_year(short year)
	{
		return((year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0));
	}
	static short get_days_of_month(short year, short month)
	{
		if (month == 2)  return (check_leap_year(year)) ? 29 : 28;
		return (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) ? 31 : 30;
	}
	short get_days_of_month()
	{
		return get_days_of_month(_year, _month);
	}
	void convert_days_to_date(short days, short year)
	{
		short month = 1;

		while (get_days_of_month(year, month) < days)
		{
			days -= get_days_of_month(year, month);
			if (month < 12)
			{
				month++;
			}
			else {
				month = 1;
				year++;
			}
		}

		this->_month = month;
		this->_day = days;
	}

	void print()
	{
		cout << "Date is :  " << convert_date_to_string() << endl;
	}

	static short get_days_of_year(short year)
	{
		return check_leap_year(year) ? 366 : 365;
	}
	short get_days_of_year()
	{
		get_days_of_year(_year);
	}
	static short get_hours_of_year(short year)
	{
		return get_days_of_year(year) * 24;
	}
	short get_hours_of_year()
	{
		return get_hours_of_year(_year);
	}
	static int get_minutes_of_year(short year)
	{
		return get_hours_of_year(year) * 60;
	}
	int get_minutes_of_year()
	{
		return get_minutes_of_year(_year);
	}
	static int get_seconds_of_year(short year)
	{
		return get_minutes_of_year(year) * 60;
	}
	int get_seconds_of_year()
	{
		return get_seconds_of_year(_year);
	}

	static int get_hours_of_month(cls_date date)
	{
		return get_days_of_month(date.year(), date.month()) * 24;
	}
	int get_hours_of_month()
	{
		return get_hours_of_month(*this);
	}
	static int get_minutes_of_month(cls_date date)
	{
		return get_hours_of_month(date) * 60;
	}
	int get_minutes_of_month()
	{
		return get_minutes_of_month(*this);
	}
	static int get_seconds_of_month(cls_date date)
	{
		return get_minutes_of_month(date) * 60;
	}
	int get_seconds_of_month()
	{
		return get_seconds_of_month(*this);
	}

	static int calc_index_of_day(cls_date date)
	{
		int a = (14 - date.month()) / 12;
		int y = date.year() - a;
		int m = date.month() + (12 * a) - 2;


		int index = (date.day() + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;

		return index;
	}
	static int calc_index_of_day(short month, short year, short day)
	{
		int a = (14 - month) / 12;
		int y = year - a;
		int m = month + (12 * a) - 2;


		int index = (day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;

		return index;
	}
	int calc_index_of_day()
	{
		return calc_index_of_day(*this);
	}
	static void print_day_name(cls_date date)
	{
		string arr[] = { "sunday" , "monday" , "tuesday" , "wednesday" , "thursday" , "friday" , "saturday" };
		int index = calc_index_of_day(date);
		cout << "Day name   : " << arr[index] << endl;
	}
	void print_day_name()
	{
		print_day_name(*this);
	}

	static string month_name(cls_date date)
	{
		string months_names[] = {
			"" ,"Janury" , "fabrury" , "march" , "april" , "may" , "june" , "july" , "augost" , "september" , "october" , "november" , "december"
		};

		return months_names[date.month()];
	}
	static string month_name(short month)
	{
		string months_names[] = {
			"" ,"Janury" , "fabrury" , "march" , "april" , "may" , "june" , "july" , "augost" , "september" , "october" , "november" , "december"
		};

		return months_names[month];
	}
	string month_name()
	{
		return month_name(*this);
	}
	static void print_days_calender()
	{
		string arr[7] = { "sun" , "mon" , "tue" , "wed" , "thu" , "fri" , "sat" };

		for (short i = 0; i < 7; i++)
			cout << left << setw(6) << arr[i];

		cout << endl;
	}
	static void print_days_in_month(cls_date date)
	{
		short counter = 0;
		short days_in_month = get_days_of_month(date.year(), date.month());

		for (short j = 0; j < calc_index_of_day(date); j++)
		{
			cout << left << setw(6) << "";
			counter++;
		}

		for (short i = 1; i <= days_in_month; i++)
		{
			if (counter == 7)
			{
				cout << endl;
				counter = 0;
			}

			cout << left << setw(6) << i;
			counter++;
		}

		cout << endl;

	}
	static void print_days_in_month(short month, short year)
	{
		short counter = 0;
		short days_in_month = get_days_of_month(year, month);

		for (short j = 0; j < calc_index_of_day(month, year, 1); j++)
		{
			cout << left << setw(6) << "";
			counter++;
		}

		for (short i = 1; i <= days_in_month; i++)
		{
			if (counter == 7)
			{
				cout << endl;
				counter = 0;
			}

			cout << left << setw(6) << i;
			counter++;
		}

		cout << endl;

	}

	void print_days_in_month()
	{
		print_days_in_month(*this);
	}
	static void print_calender_of_month(cls_date date)
	{
		cout << "_______________ " << month_name(date) << " _________________" << endl;
		print_days_calender();
		print_days_in_month(date);
		cout << "________________________________________" << endl;
	}
	void print_calender_of_month()
	{
		print_calender_of_month(*this);
	}
	static void year_calender_header(cls_date date)
	{
		cout << "________________________________________\n" << endl;
		printf("         Calendar  - [ %d ] \n", date.year());
		cout << "________________________________________" << endl;
	}
	void year_calender_header()
	{
		year_calender_header(*this);
	}
	static void print_year_calender(cls_date date)
	{
		year_calender_header(date);
		for (short i = 1; i <= 12; i++)
		{
			cout << "_______________ " << month_name(i) << " _________________" << endl;
			print_days_calender();
			print_days_in_month(i, date.year());
			cout << "________________________________________" << endl;
		}
	}
	void print_year_calender()
	{
		print_year_calender(*this);
	}

	static short calc_days_spent(cls_date date)
	{
		int days_sum = 0;
		for (short i = 1; i < date.month(); i++)
		{
			days_sum += get_days_of_month(date.year(), i);
		}

		days_sum += date.day();

		return days_sum;
	}
	short calc_days_spent()
	{
		return calc_days_spent(*this);
	}
	static void add_days(cls_date& date, int extra)
	{
		short YEAR = date.year();
		short MONTH = date.month();
		short DAYS = date.day();

		DAYS += extra;

		while (DAYS > get_days_of_month(YEAR, MONTH))
		{
			DAYS -= get_days_of_month(YEAR, MONTH);
			if (MONTH == 12)
			{
				YEAR++;
				MONTH = 1;
				continue;
			}
			else {
				MONTH++;
			}
		}

		date.set_day(DAYS);
		date.set_year(YEAR);
		date.set_month(MONTH);
	}
	void add_days(int extra)
	{
		add_days(*this, extra);
	}
	static bool check_if_date1_equal_to_date2(cls_date date1, cls_date date2)
	{
		return (date1.day() == date2.day() && date1.month() == date2.month() && date1.year() == date2.year());
	}
	static bool check_if_date1_before_date2(cls_date date1, cls_date date2)
	{
		if (date1.year() != date2.year())
			return date1.year() < date2.year();
		if (date1.month() != date2.month())
			return date1.month() < date2.month();
		return date1.day() < date2.day();
	}
	static bool check_if_date1_after_date2(cls_date date1, cls_date date2)
	{
		if (date1.year() != date2.year())
			return date1.year() > date2.year();
		if (date1.month() != date2.month())
			return date1.month() > date2.month();
		return date1.day() > date2.day();
	}
	static bool is_last_month(cls_date date)
	{
		return (date.month() == 12);
	}
	bool is_last_month()
	{
		return is_last_month(*this);
	}
	static bool is_last_day(cls_date date)
	{
		return (date.day() == get_days_of_month(date.year(), date.month()));
	}
	bool is_last_day()
	{
		return is_last_day(*this);
	}

	static void increase_day(cls_date& date)
	{

		if (is_last_month(date) && is_last_day(date))
		{
			date.set_year(date.year() + 1);
			date.set_month(1);
			date.set_day(1);
		}
		else if (is_last_day(date))
		{
			date.set_day(1);
			date.set_month(date.month() + 1);
		}
		else
			date.set_day(date.day() + 1);;
	}
	void increase_day()
	{
		increase_day(*this);
	}
	static int GetDifferenceInDays(cls_date Date1, cls_date Date2, bool IncludeEndDay = false)
	{
		int Days = 0;
		if (check_if_date1_before_date2(Date1, Date2))
		{
			while (check_if_date1_before_date2(Date1, Date2))
			{
				Days++;
				increase_day(Date1);
			}
			return IncludeEndDay ? ++Days : Days;
		}
		else {
			cls_date temp;

			temp = Date1;
			Date1 = Date2;
			Date2 = temp;

			while (check_if_date1_before_date2(Date1, Date2))
			{
				Days++;
				increase_day(Date1);
			}
			return IncludeEndDay ? ++Days * -1 : Days * -1;

		}

	}
	static void add_one_week(cls_date& date)
	{
		for (short i = 0; i < 7; i++)
		{
			increase_day(date);
		}
	}
	void add_one_week()
	{
		add_one_week(*this);
	}
	static void add_week_by_x(cls_date& date, short repeat = 1)
	{
		for (short i = 0; i < repeat; i++)
		{
			add_one_week(date);
		}
	}
	void add_week_by_x(short repeat = 1)
	{
		add_week_by_x(*this, repeat);
	}
	static void increase_date_by_one_month(cls_date& date)
	{
		short days_month = get_days_of_month(date.year(), date.month());

		for (short i = 0; i < days_month; i++)
		{
			increase_day(date);
		}
	}
	void increase_date_by_one_month()
	{
		increase_date_by_one_month(*this);
	}
	static void increase_date_by_x_months(cls_date& date, short repeat = 1)
	{
		for (short i = 0; i < repeat; i++)
		{
			increase_date_by_one_month(date);
		}
	}
	void increase_date_by_x_months(short repeat = 1)
	{
		increase_date_by_x_months(*this, repeat);
	}

	static void increase_date_by_one_year(cls_date& date)
	{
		date.set_year(date.year() + 1);

		if (date.month() == 2 && date.day() == 29 && !check_leap_year(date.year()))
		{
			date.set_day(28);
		}
	}
	void increase_date_by_one_year()
	{
		increase_date_by_one_year(*this);
	}
	static void add_years(cls_date& date, short repeat = 1)
	{
		for (short i = 0; i < repeat; i++)
		{
			increase_date_by_one_year(date);
		}
	}
	void add_years(short repeat = 1)
	{
		add_years(*this, repeat);
	}
	static void add_decade(cls_date& date)
	{
		add_years(date, 10);
	}
	void add_decade() {
		add_decade(*this);
	}
	static void add_decades(cls_date& date, short repeat = 1)
	{
		for (short i = 0; i < repeat; i++)
		{
			add_decade(date);
		}
	}
	void add_decades(short repeat = 1)
	{
		add_decades(*this, repeat);
	}
	static void add_one_century(cls_date& date)
	{
		add_decades(date, 10);
	}
	void add_one_century()
	{
		add_one_century(*this);
	}
	static void add_millennium(cls_date& date)
	{
		for (short i = 0; i < 10; i++)
		{
			add_one_century(date);
		}
	}
	void add_millennium()
	{
		add_millennium(*this);
	}

	static bool IsFirstDayInMonth(cls_date date)
	{
		return (date.day() == 1);
	}
	bool IsFirstDayInMonth()
	{
		IsFirstDayInMonth(*this);
	}
	static bool IsFirstMonthInYear(cls_date date)
	{
		return (date.month() == 1);
	}
	bool IsFirstMonthInYear()
	{
		IsFirstMonthInYear(*this);
	}
	static void DecreaseDateByOneDay(cls_date& date)
	{
		if (IsFirstDayInMonth(date))
		{
			if (IsFirstMonthInYear(date))
			{
				date.set_day(31);
				date.set_month(12);
				date.set_year(date.year() - 1);
			}
			else
			{
				date.set_month(date.month() - 1);
				date.set_day(get_days_of_month(date.year(), date.month()));
			}
		}
		else
		{
			date.set_day(date.day() - 1);
		}
	}
	void DecreaseDateByOneDay()
	{
		DecreaseDateByOneDay(*this);
	}
	static void DecreaseDateByXDays(cls_date& date, short NumberOfDays)
	{
		for (short i = 1; i <= NumberOfDays; i++)
		{
			DecreaseDateByOneDay(date);
		}
	}
	void DecreaseDateByXDays(short NumberOfDays)
	{
		DecreaseDateByXDays(*this, NumberOfDays);
	}
	static void DecreaseDateByOneWeek(cls_date& date)
	{
		DecreaseDateByXDays(date, 7);
	}
	void DecreaseDateByOneWeek()
	{
		DecreaseDateByOneWeek(*this);
	}
	static void DecreaseDateByXWeeks(cls_date& date, short NumberOfWeeks)
	{
		for (short i = 1; i <= NumberOfWeeks; i++)
		{
			DecreaseDateByOneWeek(date);
		}
	}
	void DecreaseDateByXWeeks(short NumberOfWeeks)
	{
		DecreaseDateByXWeeks(*this, NumberOfWeeks);
	}
	static void DecreaseDateByOneMonth(cls_date& date)
	{
		if (IsFirstMonthInYear(date))
		{
			date.set_month(12);
			date.set_year(date.year() - 1);
		}
		else
		{
			date.set_month(date.month() - 1);
		}

		if (date.day() > date.get_days_of_month(date.year(), date.month()))
		{
			date.set_day(date.get_days_of_month(date.year(), date.month()));
		}
	}
	void DecreaseDateByOneMonth()
	{
		DecreaseDateByOneMonth(*this);
	}
	static void DecreaseDateByXMonths(cls_date& date, short NumberOfMonths)
	{
		for (short i = 1; i <= NumberOfMonths; i++)
		{
			DecreaseDateByOneMonth(date);
		}
	}
	void DecreaseDateByXMonths(short NumberOfMonths)
	{
		DecreaseDateByXMonths(*this, NumberOfMonths);
	}
	static void DecreaseDateByOneYear(cls_date& date)
	{
		date.set_year(date.year() - 1);
	}
	void DecreaseDateByOneYear()
	{
		DecreaseDateByOneYear(*this);
	}
	static void DecreaseDateByXYears(cls_date& date, short NumberOfYears)
	{
		date.set_year(date.year() - NumberOfYears);
	}
	void DecreaseDateByXYears(short NumberOfYears)
	{
		DecreaseDateByXYears(*this, NumberOfYears);
	}
	static void DecreaseDateByOneDecade(cls_date& date)
	{
		date.set_year(date.year() - 10);
	}
	void DecreaseDateByOneDecade() {
		DecreaseDateByOneDecade(*this);
	}
	static void DecreaseDateByXDecades(cls_date& date, short NumberOfDecades)
	{
		date.set_year(date.year() - (NumberOfDecades * 10));
	}
	void DecreaseDateByXDecades(short NumberOfDecades)
	{
		DecreaseDateByXDecades(*this, NumberOfDecades);
	}
	static void DecreaseDateByOneCentury(cls_date& date)
	{
		date.set_year(date.year() - 100);
	}
	void DecreaseDateByOneCentury()
	{
		DecreaseDateByOneCentury(*this);
	}
	static void DecreaseDateByOneMillennium(cls_date& date)
	{
		date.set_year(date.year() - 1000);
	}
	void DecreaseDateByOneMillennium()
	{
		DecreaseDateByOneMillennium(*this);
	}

	static bool IsEndOfWeek(cls_date date)
	{
		return (calc_index_of_day(date) == 0);
	}
	bool IsEndOfWeek()
	{
		IsEndOfWeek(*this);
	}
	static bool IsWeekEnd(cls_date date)
	{
		short DayIndex = calc_index_of_day(date);
		return (DayIndex == 6 || DayIndex == 0);
	}
	bool IsWeekEnd()
	{
		IsWeekEnd(*this);
	}
	static bool IsBusinessDay(cls_date date)
	{
		return !IsWeekEnd(date);
	}
	bool IsBusinessDay()
	{
		IsBusinessDay(*this);
	}
	static short DaysUntilTheEndOfWeek(cls_date date)
	{
		short days = 0;
		while (calc_index_of_day(date) != 0)
		{
			days++;
			increase_day(date);
		}
		return days;
	}
	short DaysUntilTheEndOfWeek()
	{
		return DaysUntilTheEndOfWeek(*this);
	}
	static short DaysUntilTheEndOfMonth(cls_date date)
	{
		cls_date EndOfMonthDate;

		EndOfMonthDate.set_day(get_days_of_month(date.year(), date.month()));
		EndOfMonthDate.set_month(date.month());
		EndOfMonthDate.set_year(date.year());

		return GetDifferenceInDays(date, EndOfMonthDate, true);
	}
	short DaysUntilTheEndOfMonth()
	{
		DaysUntilTheEndOfMonth(*this);
	}
	static short DaysUntilTheEndOfYear(cls_date date)
	{
		cls_date EndOfYearDate;

		EndOfYearDate.set_day(31);
		EndOfYearDate.set_month(12);
		EndOfYearDate.set_year(date.year());

		return GetDifferenceInDays(date, EndOfYearDate, true);
	}
	short DaysUntilTheEndOfYear()
	{
		DaysUntilTheEndOfYear(*this);
	}
	static bool is_validate_date(cls_date date)
	{
		return date.day() > get_days_of_month(date.year(), date.month()) ||
			date.month() > 12 ? false : true;
	}
	bool is_validate_date()
	{
		is_validate_date(*this);
	}
	static void swip(cls_date& date1, cls_date& date2)
	{
		cls_date temp = date1;
		date1 = date2;
		date2 = temp;
	}
};