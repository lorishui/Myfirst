#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using std::cout;
using std::endl;

void print(const boost::system::error_code)
{
	cout<<"hello world."<<endl;
}

int main()
{
	boost::asio::io_service io;
	boost::asio::deadline_timer t(io,boost::posix_time::seconds(5));
	t.async_wait(&print);
	io.run();
	system("pause");
}