/// @author Matheus Boscariol
/// @date 3/4/26
/// @note Licensed under GNU AGPL License
/// @details SQL queries, PostgreSQL interaction, NO BUSINESS LOGIC

#include "AccountRepository.h"

AccountRepository::AccountRepository(drogon::orm::DbClientPtr db) {
    db_client = db;
}

std::optional<std::string> AccountRepository::s_create_account(const Account &account) {

    int64_t zero = 0;

    auto insert = db_client->execSqlSync(
        "INSERT INTO accounts(user_id, account_type, balance_cent) VALUES($1,$2,$3) RETURNING id;",
        account.userId,
        account.account_type,
        zero
    );

    if(insert.size() == 0)
        return std::nullopt;

    return insert[0]["id"].as<std::string>();
}

std::optional<Account> AccountRepository::s_get_account_by_id(std::string id) {
    auto get = db_client->execSqlSync(
        "SELECT * FROM accounts WHERE id = $1",
        id
    );

    if(get.size() == 0)
        return std::nullopt;

    Account acc;
    acc.id = get[0]["id"].as<std::string>();
    acc.userId = get[0]["user_id"].as<std::string>();
    acc.account_type = get[0]["account_type"].as<std::string>();
    acc.balanceCents = get[0]["balance_cent"].as<int64_t>();
    acc.creation_timestamp = get[0]["created_at"].as<std::string>();

    return acc;
}

int AccountRepository::s_delete_account(std::string id) {
    try {
        auto sql = db_client->execSqlSync(
        "DELETE FROM accounts WHERE id = $1",
        id
    );
    } catch (const std::exception &e) {
        return -1;
    }

    return 0;
}


std::optional<std::vector<Account>> AccountRepository::s_get_accounts_by_user(std::string user_id) {
    auto get = db_client->execSqlSync(
        "SELECT * FROM accounts WHERE user_id = $1",
        user_id
    );

    if(get.size() == 0)
        return std::nullopt;

    std::vector<Account> accounts;

    for (int i = 0; i < get.size(); i++) {
        Account acc;
        acc.id = get[i]["id"].as<std::string>();
        acc.userId = get[i]["user_id"].as<std::string>();
        acc.account_type = get[i]["account_type"].as<std::string>();
        acc.balanceCents = get[i]["balance_cent"].as<int64_t>();
        acc.creation_timestamp = get[i]["created_at"].as<std::string>();

        accounts.push_back(acc);
    }

    return accounts;
}

std::optional<std::vector<Account>> AccountRepository::s_get_all_accounts(int limit) {

    if (limit > 100)
        limit = 100;

    auto get = db_client->execSqlSync(
        "SELECT * FROM accounts LIMIT 10"

    );

    if(get.size() == 0)
        return std::nullopt;

    std::vector<Account> accounts;

    for (int i = 0; i < get.size(); i++) {
        Account acc;
        acc.id = get[i]["id"].as<std::string>();
        acc.userId = get[i]["user_id"].as<std::string>();
        acc.account_type = get[i]["account_type"].as<std::string>();
        acc.balanceCents = get[i]["balance_cent"].as<int64_t>();
        acc.creation_timestamp = get[i]["created_at"].as<std::string>();

        accounts.push_back(acc);
    }

    return accounts;
}





