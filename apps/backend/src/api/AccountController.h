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

            METHOD_ADD(account::create_account, "/", Post);              // POST /bankcore/v1/account/                      Create Account
            METHOD_ADD(account::list_accounts, "/", Get);                // Get /bankcore/v1/account/                       Get All accounts (numbers/id)

            METHOD_ADD(account::get_account, "/{1}", Get);               // Get /bankcore/v1/account/{id}                   Get Account Info
            METHOD_ADD(account::update_account, "/{1}", Put);            // Put /bankcore/v1/account/{id}                   Update Account Info
            METHOD_ADD(account::delete_account, "/{1}", Delete);         // Delete /bankcore/v1/account/{id}                Delete Account

            METHOD_ADD(account::deposit, "/{1}/deposit", Post);          // Post /bankcore/v1/account/{id}/deposit          Deposit into account
            METHOD_ADD(account::withdraw, "/{1}/withdraw", Post);        // Post /bankcore/v1/account/{id}/withdraw         Withdraw into account

            METHOD_ADD(account::transfer, "/{1}/transfer/{2}", Post);    // Post /bankcore/v1/account/{id}/transfer/{2}     Transfer money

            METHOD_LIST_END

            // Example Function Declaration:
            /*
            void create_account(const HttpRequestPtr &req,
                                std::function<void (const HttpResponsePtr &)> &&callback);
            */

            void create_account(const HttpRequestPtr &req,
                                std::function<void (const HttpResponsePtr &)> &&callback);

            void list_accounts(const HttpRequestPtr &req,
                                std::function<void (const HttpResponsePtr &)> &&callback);

            void get_account(const HttpRequestPtr &req,
                                std::function<void (const HttpResponsePtr &)> &&callback,
                                int64_t account_number);

            void update_account(const HttpRequestPtr &req,
                                std::function<void (const HttpResponsePtr &)> &&callback,
                                int64_t account_number);

            void delete_account(const HttpRequestPtr &req,
                                std::function<void (const HttpResponsePtr &)> &&callback,
                                int64_t account_number);

            void deposit(const HttpRequestPtr &req,
                                std::function<void (const HttpResponsePtr &)> &&callback,
                                int64_t account_number);

            void withdraw(const HttpRequestPtr &req,
                                std::function<void (const HttpResponsePtr &)> &&callback,
                                int64_t account_number);

            void transfer(const HttpRequestPtr &req,
                                std::function<void (const HttpResponsePtr &)> &&callback,
                                int64_t from_account,
                                int64_t to_account);
        };
    }
}