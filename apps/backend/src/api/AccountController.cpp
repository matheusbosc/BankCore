/// @author Matheus Boscariol
/// @date 3/4/26
/// @note Licensed under GNU AGPL License
/// @details Parse JSON, Route definitions, returning responses, calling service. NO DATABASE LOGIC

#include "AccountController.h"
#include "Account.h"
#include "AccountService.h"

using namespace bankcore::v1;

/// @brief Gets account details from the database.
void askd_account(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int64_t account_number) {
    auto requestJson = req->getJsonObject();

    if (!requestJson) {
        // 400 Bad Request
        Json::Value ret;
        ret["result"]="400 bad request";

        auto resp=HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(k400BadRequest);

        callback(resp);
        return;
    }

    // VERIFY NAME
    if (!requestJson->isMember("name") || !(*requestJson)["name"].asString().data()) {
        // 400 Bad Request
        Json::Value ret;
        ret["result"]="400 bad request";

        auto resp=HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(k400BadRequest);

        callback(resp);
        return;
    }

    std::string name = (*requestJson)["name"].asString();
    // END VERIFY NAME

    // 400 Bad Request
    Json::Value ret;
    ret["account_number"]="200 ok";
    ret["account_number"]=std::to_string(account_number);
    ret["name"]=name;

    auto resp=HttpResponse::newHttpJsonResponse(ret);
    resp->setStatusCode(k200OK);

    callback(resp);
    return;


}


void account::create_account(const HttpRequestPtr &req,
                                std::function<void (const HttpResponsePtr &)> &&callback) {

    auto json = req->getJsonObject();
    if (!json) {

        Json::Value ret;
        ret["result"]="400 bad request";

        auto resp=HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(k400BadRequest);

        callback(resp);
        return;
    }

    if (!requestJson->isMember("id") || !(*requestJson)["id"].asString().data()
        !requestJson->isMember("user_id") || !(*requestJson)["user_id"].asString().data()
        !requestJson->isMember("balance_cents") || !(*requestJson)["balance_cents"].asInt64().data()) {
        // 400 Bad Request
        Json::Value ret;
        ret["result"]="400 bad request";

        auto resp=HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(k400BadRequest);

        callback(resp);
        return;
    }

    std::string id = (*json)["id"].asString();
    std::string userId = (*json)["user_id"].asString();
    int64_t balanceCents = (*json)["balance_cents"].asInt64();

    Account accountInfo = Account(id, userId, balanceCents);



    // Call the services function

    // return information

}

void account::list_accounts(const HttpRequestPtr &req,
                    std::function<void (const HttpResponsePtr &)> &&callback) {

}

void account::get_account(const HttpRequestPtr &req,
                    std::function<void (const HttpResponsePtr &)> &&callback,
                    int64_t account_number) {

}

void account::update_account(const HttpRequestPtr &req,
                    std::function<void (const HttpResponsePtr &)> &&callback,
                    int64_t account_number) {

}

void account::delete_account(const HttpRequestPtr &req,
                    std::function<void (const HttpResponsePtr &)> &&callback,
                    int64_t account_number) {

}

void account::deposit(const HttpRequestPtr &req,
                    std::function<void (const HttpResponsePtr &)> &&callback,
                    int64_t account_number) {

}

void account::withdraw(const HttpRequestPtr &req,
                    std::function<void (const HttpResponsePtr &)> &&callback,
                    int64_t account_number) {

}

void account::transfer(const HttpRequestPtr &req,
                    std::function<void (const HttpResponsePtr &)> &&callback,
                    int64_t from_account,
                    int64_t to_account) {

}