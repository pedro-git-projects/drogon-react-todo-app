#include <algorithm>
#include <functional>
#include <drogon/drogon.h>
#include <drogon/HttpAppFramework.h>
#include <drogon/utils/FunctionTraits.h>
#include <trantor/utils/Logger.h>
#include "controllers/HelloController.h"

int main() {
	drogon::app().registerHandler(
        "/",
        [](const drogon::HttpRequestPtr& req,
           std::function<void(const drogon::HttpResponsePtr&)>&& callback) {
            auto helloController = HelloController();
            helloController.sayHello(req, std::move(callback));
        });
	LOG_INFO << "Starting server on 127.0.0.1:1137";
	drogon::app().addListener("0.0.0.0", 1337).run();
}
