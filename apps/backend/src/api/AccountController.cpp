/// @author Matheus Boscariol
/// @date 3/4/26
/// @note Licensed under GNU AGPL License
/// @details Parse JSON, Route definitions, returning responses, calling service. NO DATABASE LOGIC

#include "AccountController.h"
#include "Account.h"
#include "AccountService.h"

using namespace bankcore::v1;

void account::create_account(const HttpRequestPtr &req,
                                std::function<void (const HttpResponsePtr &)> &&callback) {

    auto json = req->getJsonObject();
    if (!json) {

        Json::Value ret;
        ret["result"]="400: Missing Data";

        auto resp=HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(k400BadRequest);

        callback(resp);
        return;
    }

    if (!json->isMember("user_id") || !(*json)["user_id"].asString().data()) {
        // 400 Bad Request
        Json::Value ret;
        ret["result"]="400: Missing Data";

        auto resp=HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(k400BadRequest);

        callback(resp);
        return;
    }

    std::string userId = (*json)["user_id"].asString();

    // CALL THE SERVICES FUNCTION

    Account accountInfo;
    accountInfo.userId = userId;
    accountInfo.account_type = "checking";

    auto new_account = l_create_account(accountInfo);

    if (!new_account) {
        // 400 Bad Request
        Json::Value ret;
        ret["result"]="400 bad request";

        auto resp=HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(k400BadRequest);

        callback(resp);
        return;
    }

    // CREATE JSON AND RETURN

        Json::Value ret;
        ret["result"]= "200 ok";
        ret["acc_id"]= new_account->id;
        ret["user_id"]= new_account->userId;
        ret["created_time"]= new_account->creation_timestamp;
        ret["account_type"]= new_account->account_type;
        ret["balance"]= new_account->balanceCents;

        auto resp=HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(k201Created);

        callback(resp);
}

void account::list_accounts(const HttpRequestPtr &req,
                    std::function<void (const HttpResponsePtr &)> &&callback) {

    int limit = 100;

    auto accounts = l_get_accounts("", 100);

    if (!accounts) {
        // 400 Bad Request
        Json::Value ret;
        ret["result"]="404: Accounts Not Found";

        auto resp=HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(k404NotFound);

        callback(resp);
        return;
    }

    Json::Value ret;
    ret["result"]= "200 ok";
    ret["limit"]= limit;

    Json::Value accountsJson(Json::arrayValue);

    for (int i = 0; i < accounts->size(); i++) {
        Json::Value acc;
        acc["acc_id"]= accounts.value()[i].id;
        acc["user_id"]= accounts.value()[i].userId;
        acc["created_time"]= accounts.value()[i].creation_timestamp;
        acc["account_type"]= accounts.value()[i].account_type;
        acc["balance"]= accounts.value()[i].balanceCents;

        accountsJson.append(acc);
    }

    ret["accounts"] = accountsJson;

    auto resp=HttpResponse::newHttpJsonResponse(ret);
    resp->setStatusCode(k200OK);

    callback(resp);

}

void account::get_account(const HttpRequestPtr &req,
                    std::function<void (const HttpResponsePtr &)> &&callback,
                    std::string account_number) {

    auto accounts = l_get_account(account_number);

    if (!accounts) {
        // 400 Bad Request
        Json::Value ret;
        ret["result"]="404: Account Not Found";

        auto resp=HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(k404NotFound);

        callback(resp);
        return;
    }

    Json::Value ret;
    ret["result"]= "200 ok";

        ret["acc_id"]= accounts.value().id;
        ret["user_id"]= accounts.value().userId;
        ret["created_time"]= accounts.value().creation_timestamp;
        ret["account_type"]= accounts.value().account_type;
        ret["balance"]= accounts.value().balanceCents;

    auto resp=HttpResponse::newHttpJsonResponse(ret);
    resp->setStatusCode(k200OK);

    callback(resp);

}

void account::update_account(const HttpRequestPtr &req,
                    std::function<void (const HttpResponsePtr &)> &&callback,
                    std::string account_number) {

}

void account::delete_account(const HttpRequestPtr &req,
                    std::function<void (const HttpResponsePtr &)> &&callback,
                    std::string account_number) {

    if (l_delete_account(account_number) == -1) {
        // 400 Bad Request
        Json::Value ret;
        ret["result"]="404: Account Not Found";

        auto resp=HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(k404NotFound);

        callback(resp);
        return;
    }

    Json::Value ret;
    ret["result"]="200 ok";

    auto resp=HttpResponse::newHttpJsonResponse(ret);
    resp->setStatusCode(k404NotFound);

    callback(resp);
    return;

}

void account::deposit(const HttpRequestPtr &req,
                    std::function<void (const HttpResponsePtr &)> &&callback,
                    std::string account_number) {

}

void account::withdraw(const HttpRequestPtr &req,
                    std::function<void (const HttpResponsePtr &)> &&callback,
                    std::string account_number) {

}

void account::transfer(const HttpRequestPtr &req,
                    std::function<void (const HttpResponsePtr &)> &&callback,
                    std::string from_account,
                    std::string to_account) {

}