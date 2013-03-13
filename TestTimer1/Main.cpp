#include <boost/timer.hpp>
#include <iostream>
#include <limits>
#include <cstddef>
#include <string>
#include <locale>
#include <boost/progress.hpp>
#include <sstream>
#include <vector>
#include <fstream>


using namespace boost;
using namespace std;

struct test
{
	int a;
	string s;
	int b;
};

void TestTimer()
{
	timer t;
	cout << "max timespan:" << t.elapsed_max() / 3600 << "h" << endl;
	cout << "min timespan:" << t.elapsed_min() << "s" << endl;

	cout << "now time elapsed:" << t.elapsed() << "s" <<endl;
}

void TestNumeric()
{
	cout << (std::numeric_limits<short>::max)() << endl;
	cout << (std::numeric_limits<unsigned short>::max)() << endl;
	cout << (std::numeric_limits<int>::max)() << endl;
	cout << (std::numeric_limits<long>::max)()<< endl;
	cout << (std::numeric_limits<long>::min)() << endl;
	cout << (std::numeric_limits<double>::max)() << endl;

	cout << numeric_limits<char>::is_signed << endl;
	cout << offsetof(test,b) << endl;
	std::cout.setf(std::ios::uppercase);
	std::cout << "sfsdf"<<endl;
	bool f = true;
	cout << std::boolalpha << f <<"==" << std::noboolalpha << f<<endl;

	locale l("");
	cout.imbue(l);
	cout<<l.name() << endl;
}

void TestProgress_Timer()
{
	progress_timer t;
	cout<<"begin progress test!!!"<<endl;
	cout<<"progress time:"<<t.elapsed() << endl;
	cout<<"exit func"<<endl;
}

void TestProgress_display()
{
	vector<string> v(100);
	ofstream fs("d:\\test.txt");
	progress_display pd(v.size(),cout,"%%%","+++","???");
	vector<string>::iterator pos;
	for(pos = v.begin();pos != v.end();++pos)
	{
		fs << *pos <<endl;
		++pd;
	}
}

#include <boost/date_time/gregorian/gregorian.hpp>
void TestDate()
{
	using namespace boost::gregorian;
	date d1;
	date d2(2000,1,1);
	date d3(2000,Jan,1);
	date d4 = from_string("1999-12-31");
	date d5 = from_undelimited_string("19991231");

	cout<<day_clock::local_day() << endl;
	cout<<day_clock::universal_day() << endl;
	
	date now = day_clock::local_day();
	cout<<"year:"<<now.year()<<" month:"<<now.month()<<" day:"<<now.day()<<endl;
	date::ymd_type ymd = now.year_month_day();
	cout<<"year:"<<ymd.year<<" month:"<<ymd.month<<" day:"<<ymd.day<<endl;

	cout<<"================================="<<endl;
	cout<<to_simple_string(now)<<endl;
	cout<<to_iso_string(now)<<endl;
	cout<<to_iso_extended_string(now)<<endl;

// 	date test;
// 	cin >> test;
// 	cout<<test;
	cout<<"============================="<<endl;
	date t(2010,2,1);
	tm s = to_tm(t);
	cout<<s.tm_hour<<"  "<<s.tm_min<<endl;
	cout<<s.tm_year +1900<<" "<<s.tm_mon + 1<<"  "<<s.tm_mday<<endl;
	date t1 = date_from_tm(s);
	assert(t == t1);
	days ds(10);
	date t2 = t1 + ds;
	cout<<t2<<endl;
	days ds1 = t2 - t1;
	cout<<ds1<<endl;
}

void TestDatePeriod()
{
	using namespace boost::gregorian;
	date_period dp1(date(2013,2,3),days(10));
	cout<<dp1.begin()<<endl;
	cout<<dp1.last()<<endl;
	cout<<dp1.end()<<endl;
	cout<<dp1.length()<<endl;
}

int main()
{
	//TestTimer();
	//TestNumeric();
	//TestProgress_Timer();
	//TestProgress_display();
	//TestDate();
	TestDatePeriod();
	system("pause");
}