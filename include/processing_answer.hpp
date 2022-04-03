// Copyright 2021 Your Name <your_email>

#ifndef INCLUDE_PROCESSING_ANSWER_HPP_
#define INCLUDE_PROCESSING_ANSWER_HPP_

#include <nlohmann/json.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <cstdlib>
#include <iostream>
#include <string>

using json = nlohmann::json;
namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = net::ip::tcp;

void making_request(int argc, char** argv);

#endif // INCLUDE_PROCESSING_ANSWER_HPP_
