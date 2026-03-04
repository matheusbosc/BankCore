/// @author Matheus Boscariol
/// @date 3/4/26
/// @note Licensed under GNU AGPL License
/// @details Parse JSON, Route definitions, returning responses, calling service. NO DATABASE LOGIC

#include "AccountController.h"

using namespace bankcore::v1;

/// @brief Gets account details from the database.
void Account::get_account(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int64_t account_number) {
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
