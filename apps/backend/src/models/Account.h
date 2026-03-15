/// @author Matheus Boscariol
/// @date 3/4/26
/// @note Licensed under GNU AGPL License
/// @details Structure for account info

#pragma once

#include <string>
#include <json/value.h>

class Account {
    public:
    std::string id;
    std::string userId;
    std::string account_type;
    int64_t balanceCents;
    std::string creation_timestamp;

    Json::Value AccountToJson() {
        Json::Value json;

        json["acc_id"]= id;
        json["user_id"]= userId;
        json["created_time"]= creation_timestamp;
        json["account_type"]= account_type;
        json["balance"]= balanceCents;

        return json;
    }

    void JsonToAccount(Json::Value json) {
        id = json["acc_id"].asString();
        userId = json["user_id"].asString();
        account_type = json["account_type"].asString();
        balanceCents = json["balance"].asInt64();
        creation_timestamp = json["created_time"].asString();
    }
};
