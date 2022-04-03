#include <processing_answer.hpp>

int main(int argc, char** argv) {
  //
  //
  //
  try
  {
    if(argc != 4 && argc != 5)
    {
      std::cerr <<
          "Usage: http-client-sync <host> <port> <target> [<HTTP version: 1.0 or 1.1(default)>]\n" <<
          "Example:\n" <<
          "    http-client-sync www.example.com 80 /\n" <<
          "    http-client-sync www.example.com 80 / 1.0\n";
      return EXIT_FAILURE;
    }
    making_request(argc, argv);
  }
  catch(std::exception const& e)
  {
    std::cerr << "Error: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}