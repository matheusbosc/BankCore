/// @author Matheus Boscariol
/// @date 3/4/26
/// @note Licensed under GNU AGPL License

#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

namespace bankcore
{
    namespace v1
    {
        class account : public drogon::HttpController<account>
        {
        public:
            METHOD_LIST_BEGIN
            // use METHOD_ADD to add your custom processing function here;
            // METHOD_ADD(User::get, "/{2}/{1}", Get); // path is /demo/v1/User/{arg2}/{arg1}
            // METHOD_ADD(User::your_method_name, "/{1}/{2}/list", Get); // path is /demo/v1/User/{arg1}/{arg2}/list
            // ADD_METHOD_TO(User::your_method_name, "/absolute/path/{1}/{2}/list", Get); // path is /absolute/path/{arg1}/{arg2}/list
            METHOD_ADD(account::get_account, "/get_account/{1}", Post);              // Path: /bankcore/v1/account/get_account/{account_number}

            METHOD_LIST_END

            // Example Function Declaration:
            /*
            void create_account(const HttpRequestPtr &req,
                                std::function<void (const HttpResponsePtr &)> &&callback);
            */

            void get_account(const HttpRequestPtr &req,
                                std::function<void (const HttpResponsePtr &)> &&callback,
                                int64_t account_number);
        };
    }
}