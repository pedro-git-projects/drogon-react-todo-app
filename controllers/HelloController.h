#pragma once

#include <drogon/HttpController.h>
#include <drogon/HttpTypes.h>
#include <drogon/utils/FunctionTraits.h>
#include <functional>

class HelloController : public drogon::HttpController<HelloController, false> {
	public:
		METHOD_LIST_BEGIN
			ADD_METHOD_TO(HelloController::sayHello, "/", drogon::HttpMethod::Get); 
		METHOD_LIST_END

		void sayHello(const drogon::HttpRequestPtr& req, std::function<void(const drogon::HttpResponsePtr&)>&& callback);;
};
