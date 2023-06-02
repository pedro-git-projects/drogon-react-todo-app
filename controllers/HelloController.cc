#include "HelloController.h"
#include <drogon/HttpResponse.h>

void HelloController::sayHello(const drogon::HttpRequestPtr &req, std::function<void (const drogon::HttpResponsePtr &)> &&callback) {
    Json::Value jsonData;
    jsonData["message"] = "Hello, drogon!";
    auto response = drogon::HttpResponse::newHttpJsonResponse(std::move(jsonData));
    callback(response);
}
