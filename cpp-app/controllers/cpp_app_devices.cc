#include "cpp_app_devices.h"

using namespace cpp_app;

void append_device(Json::Value &v, const Device &device)
{
    Json::Value device_json;
    device_json["id"] = device.id;
    device_json["mac"] = device.mac;
    device_json["firmware"] = device.firmware;
    v.append(device_json);
}

void devices::get([[maybe_unused]] const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback)
{

    std::vector<Device> response_devices{
        Device{1, "5F-33-CC-1F-43-82", "2.1.6"},
        Device{2, "EF-2B-C4-F5-D6-34", "2.1.6"}
    };
    Json::Value response_json;
    for (const auto &device : response_devices)
        append_device(response_json, device);

    auto httpResponse = HttpResponse::newHttpJsonResponse(std::move(response_json));
    callback(std::move(httpResponse));
}

uint fibonacci(int n)
{
    if (n == 1 || n == 2) return 1;
    else if (n == 3) return 2;
    else return fibonacci(n - 1) + fibonacci(n - 2);
}

void devices::post([[maybe_unused]] const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) const
{
    int number = dis(gen); // Generate a random 
    auto fib = fibonacci(number); 
    std::string location = "/cpp_app/devices/" + std::to_string(fib);
    auto httpResponse = HttpResponse::newHttpResponse();
    httpResponse->setStatusCode(HttpStatusCode::k201Created);
    httpResponse->setContentTypeCode(ContentType::CT_TEXT_PLAIN);
    httpResponse->addHeader("location", location);
    callback(std::move(httpResponse));
}