#pragma once

#include <drogon/HttpController.h>
#include <vector>
#include <random>

using namespace drogon;

namespace cpp_app
{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(5, 40);

  struct Device
  {
    int id;
    std::string mac;
    std::string firmware;
    Device(int devid, std::string mac_id, std::string firmware_version)
        : id(devid), mac(mac_id), firmware(firmware_version)
    {
    }
  };

  class devices : public drogon::HttpController<devices>
  {
  public:
    METHOD_LIST_BEGIN

    METHOD_ADD(devices::get, "", Get);
    METHOD_ADD(devices::post, "", Post);

    METHOD_LIST_END

    void get(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback);
    void post(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) const;
  };
}