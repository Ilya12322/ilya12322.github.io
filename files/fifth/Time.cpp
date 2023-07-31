#include "Time.h"

Time::Time(int hou, int min, int sec) : hour{ hou }, minute{ min }, second{ sec } 
{
	if (hou < 0 || hou >= 24)
		throw(InvalidValue("Invalid value: " + std::to_string(hou) + " does not belong to the interval [0; 24)"));
	if (min < 0 || min >= 60)
		throw(InvalidValue("Invalid value: " + std::to_string(min) + " does not belong to the interval [0; 60)"));
	if (sec < 0 || sec >= 60)
		throw(InvalidValue("Invalid value: " + std::to_string(sec) + " does not belong to the interval [0; 60)"));
}

Time::Time(int hou, int min) : hour{ hou }, minute{ min }, second{ 0 }  
{
	*this = {hou, min, 0};
}

Time::Time(int sec) 
{
	if (sec < 0 || sec >= 86400)
		throw(InvalidValue("Invalid value: " + std::to_string(sec) + " does not belong to the interval [0; 86400)"));
	*this = { sec / 3600, (sec % 3600) / 60, sec % 60 };
}

Time::Time(std::string st)
{
	int h=0, m=0, s=0;
	int count = 0;
	std::string num="";
	for (int i = 0; i < st.size(); i++) {
		if (isdigit(st[i]))
			num += st[i];
		else if (st[i] == ':') {
			if (!count)
				h = std::stoi(num);
			else if (count == 1)
				m = std::stoi(num);
			count++;
			num = "";
		}
		else
			throw(InvalidString());
	}
	s = std::stoi(num);
	*this = { h, m, s };
}

int Time::all_second() const
{
	int sec = hour * 3600 + minute * 60 + second;
	return sec;
}

std::string Time::to_string() const
{
	std::string s = "";
	if (hour >= 10)
		s += std::to_string(hour) + ":";
	else
		s += "0" + std::to_string(hour) + ":";
	if (minute >= 10)
		s += std::to_string(minute) + ":";
	else
		s += "0" + std::to_string(minute) + ":";
	if (second >= 10)
		s += std::to_string(second);
	else
		s += "0" + std::to_string(second);
	return s;
}

Time Time::operator + (const Time& b) const
{
	int h=0, m=0, s;
	s = second + b.second;
	if (s >= 60) {
		s -= 60;
		++m;
	}
	m += minute + b.minute;
	if (m >= 60) {
		m -= 60;
		++h;
	}
	h += hour + b.hour;
	Time c{ h, m, s };
	return c;
}

Time Time::operator + (int n) const
{
	Time b{ n };
	Time c = *this + b;
	return c;
}

Time& Time::operator += (const Time& b)
{
	*this = *this + b;
	return *this;
}

Time& Time::operator += (int n)
{
	Time b{ n };
	*this += b;
	return *this;
}

Time Time::operator - (const Time& b) const
{
	int h = 0, m = 0, s;
	if (second < b.second) {
		s = second + 60 - b.second;
		--m;
	}
	else
		s = second - b.second;
	if ((minute-m) < b.minute) {
		m += minute + 60 - b.minute;
		--h;
	}
	else
		m += minute - b.minute;
	h += hour - b.hour;
	Time c{ h, m, s };
	return c;
}

Time Time::operator - (int n) const
{
	Time b{ n };
	Time c = *this - b;
	return c;
}

Time& Time::operator -= (const Time& b)
{
	*this = *this - b;
	return *this;
}

Time& Time::operator -= (int n)
{
	Time b{ n };
	*this -= b;
	return *this;
}

Time& Time::operator ++ ()
{
	*this += 1;
	return *this;
}

Time Time::operator ++ (int)
{
	Time a = *this;
	*this+=1;
	return a;
}

Time& Time::operator -- ()
{
	*this -= 1;
	return *this;
}

Time Time::operator -- (int)
{
	Time a = *this;
	*this -= 1;
	return a;
}

// ќбъ€вление функций, не включенных в класс, но работающих с объектами класса
Time operator + (int n, const Time& a) 
{
	return a + n;
}
Time operator - (int n, const Time& a)
{
	return a - n;
}

bool operator == (const Time& a, const Time& b)
{
	return a.all_second() == b.all_second();
}

bool operator < (const Time& a, const Time& b)
{
	return a.all_second() < b.all_second();
}
