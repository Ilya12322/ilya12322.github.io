#ifndef TIME_H
#define TIME_H

#include<iostream>
#include<string>
#include<cctype>

class Time
{
protected:
	int hour, minute, second;
public:
	Time(int hou, int min, int sec);
	Time(int hou, int min);
	Time(int sec);
	Time() : hour{ 0 }, minute{ 0 }, second{ 0 } { }
	Time(std::string s);

	int seconds() const { return second; }
	int minutes() const { return minute; }
	int hours() const { return hour; }
	int all_second() const;
	std::string to_string() const;
	Time operator + (const Time& b) const;
	Time operator + (int n) const;
	Time& operator += (const Time& b);
	Time& operator += (int n);
	Time operator - (const Time& b) const;
	Time operator - (int n) const;
	Time& operator -= (const Time& b);
	Time& operator -= (int n);
	Time& operator ++ ();    
	Time operator ++ (int);  
	Time& operator -- ();    
	Time operator -- (int); 
};

// Объявление функций, не включенных в класс, но работающие с ним 
Time operator + (int n, const Time& a);
Time operator - (int n, const Time& a);
bool operator == (const Time& a, const Time& b);
bool operator < (const Time& a, const Time& b);

// исключения 
class InvalidValue {
private:
	std::string message;
public:
	InvalidValue(std::string s = "") : message{ s } {  }
	std::string what() const { return message; }
};

class InvalidString { };

#endif
