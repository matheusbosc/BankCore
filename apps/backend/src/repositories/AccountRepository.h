/// @author Matheus Boscariol
/// @date 3/4/26
/// @note Licensed under GNU AGPL License

#pragma once

#include "Account.h"
#include "drogon/orm/DbClient.h"

class AccountRepository {
public:
    AccountRepository(drogon::orm::DbClientPtr db);

    std::optional<Account> s_get_account_by_id(std::string id);

    std::optional<std::vector<Account>> s_get_accounts_by_user(std::string user_id);

    std::optional<std::vector<Account>> s_get_all_accounts(int limit);

    std::optional<std::string> s_create_account(const Account& account);

    int s_delete_account(std::string id);

private:
    drogon::orm::DbClientPtr db_client;
};