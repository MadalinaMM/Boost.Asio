/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: madalina
 *
 * Created on April 1, 2017, 1:10 PM
 */

#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

int main()
{
  boost::asio::io_service io;
 
  for(int i = 0; i < 5; i++) {
    boost::asio::deadline_timer timer(io, boost::posix_time::seconds(i));
    timer.wait();
    std::cout << "Blocking wait(): " << i << " second-wait\n";
  }

  return 0;
}

