#include <iostream>
#include "cpr/cpr.h"

enum class CommandType { GET = 1, POST, PUT, R_DELETE, PATCH, EXT };

class Response {
 private:
  cpr::Response putResponse;
  cpr::Response deleteResponse;
  cpr::Response postResponse;
  cpr::Response patchResponse;
  cpr::Response getResponse;

  public:
  void sendPost() {
    postResponse = cpr::Post(cpr::Url("https://httpbin.org/post"));
    std::cout << postResponse.text;
  }

  void sendGet() { 
    getResponse = cpr::Get(cpr::Url("https://httpbin.org/get"));
    std::cout << getResponse.text;
  }

  void sendPut() {
    putResponse = cpr::Put(cpr::Url("https://httpbin.org/put"));
    std::cout << putResponse.text;
  }

  void sendDelete() {
    deleteResponse = cpr::Delete(cpr::Url("https://httpbin.org/delete"));
    std::cout << deleteResponse.text;
  }

  void sendPatch() {
    patchResponse = cpr::Patch(cpr::Url("https://httpbin.org/patch"));
    std::cout << patchResponse.text;
  }
};

int main() {
  int command = 0;
  Response* response = new Response;
  while (command != static_cast<int>(CommandType::EXT)) {
    std::cout << "Enter the command:" << std::endl;
    std::cout << static_cast<int>(CommandType::GET) << "# Get response"
              << std::endl;
    std::cout << static_cast<int>(CommandType::POST) << "# Post response"
              << std::endl;
    std::cout << static_cast<int>(CommandType::PUT) << "# Put response"
              << std::endl;
    std::cout << static_cast<int>(CommandType::R_DELETE) << "# Delete response"
              << std::endl;
    std::cout << static_cast<int>(CommandType::PATCH) << "# Path response"
              << std::endl;
    std::cout << static_cast<int>(CommandType::EXT) << "# Exit" << std::endl;
    std::cin >> command;

    switch (command) {
      case static_cast<int>(CommandType::GET):
        response->sendGet();
        break;
      case static_cast<int>(CommandType::POST):
        response->sendPost();
        break;
      case static_cast<int>(CommandType::PUT):
        response->sendPut();
        break;
      case static_cast<int>(CommandType::R_DELETE):
        response->sendDelete();
        break;
      case static_cast<int>(CommandType::PATCH):
        response->sendPatch();
        break;
    }
    system("pause");
    system("cls");
  }
  delete response;

  std::cout << "Program finished!" << std::endl;
}