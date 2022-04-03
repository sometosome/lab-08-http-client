// Copyright 2021 Your Name <your_email>

#include <processing_answer.hpp>
#include <stdexcept>

void making_request(int argc, char** argv){
  auto const host = argv[1];
  auto const port = argv[2];
  auto const target = argv[3];
  int version = argc == 5 && !std::strcmp("1.0", argv[4]) ? 10 : 11;
  //
  std::string user_name;
  std::string content;
  std::cout << "Enter user_name: ";
  getline(std::cin, user_name);
  std::cout << "Enter input content: ";
  getline(std::cin, content);
  std::cout << "\n";

  net::io_context ioc;
  tcp::resolver resolver{ioc};
  tcp::socket socket{ioc};

  auto const results = resolver.resolve(host, port);

  net::connect(socket, results.begin(), results.end());
  json body = "{"
      "\"input\": \"" + content + "\"}";
  http::request<http::string_body> req{http::verb::post, target, version};
  req.set(http::field::host, host);
  req.set("user_name", user_name);
  req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
  req.body() = body;
  req.prepare_payload();
  http::write(socket, req);

  beast::flat_buffer buffer;

  http::response<http::dynamic_body> res;

  http::read(socket, buffer, res);

  std::cout << "**Response information**" << std::endl;
  std::cout << res << std::endl;
  std::cout << "*****\n" << std::endl;

  beast::error_code ec;
  socket.shutdown(tcp::socket::shutdown_both, ec);
  if (ec && ec != beast::errc::not_connected)
    throw beast::system_error{ec};
}
