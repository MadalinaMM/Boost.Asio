#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

void handler(const boost::system::error_code& /*e*/, boost::asio::deadline_timer* timer, int* count)
{
  if (*count < 5)
  {
    std::cout << *count << "\n";
    ++(*count);

    timer->expires_at(timer->expires_at() + boost::posix_time::seconds(1));
    timer->async_wait(boost::bind(handler, boost::asio::placeholders::error, timer, count));
  }
}

int main()
{
  boost::asio::io_service io;

  int count = 0;
  boost::asio::deadline_timer timer(io, boost::posix_time::seconds(1));
  timer.async_wait(boost::bind(handler, boost::asio::placeholders::error, &timer, &count));

  io.run();

  std::cout << "The last count : " << count << "\n";

  return 0;
}
