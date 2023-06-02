#include "HelloController.h"
#include <drogon/HttpResponse.h>

void HelloController::sayHello(const drogon::HttpRequestPtr &req, std::function<void (const drogon::HttpResponsePtr &)> &&callback) {
	auto response = drogon::HttpResponse::newHttpResponse();
	response->setBody("Hello, drogon!");
	callback(response);
}
