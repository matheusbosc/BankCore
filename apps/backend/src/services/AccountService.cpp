/// @author Matheus Boscariol
/// @date 3/4/26
/// @note Licensed under GNU AGPL License
/// @details Business rules, validation, transaction boundries. Calls the repository.

#include "AccountService.h"

#include "AccountRepository.h"
#include "drogon/HttpAppFramework.h"

std::optional<Account> l_create_account(Account &account) {
    AccountRepository repo = AccountRepository(drogon::app().getDbClient());

    auto new_account_id = repo.s_create_account(account);

    if (!new_account_id) {
        return std::nullopt;
    }

    auto new_account = repo.s_get_account_by_id(new_account_id.value());

    return new_account;

}

std::optional<Account> l_get_account(std::string account_id) {
    AccountRepository repo = AccountRepository(drogon::app().getDbClient());

    auto account_info = repo.s_get_account_by_id(account_id);

    return account_info;
}

std::optional<std::vector<Account>> l_get_accounts(std::string user_id, int limit) {
    AccountRepository repo = AccountRepository(drogon::app().getDbClient());

    if (user_id.empty()) {
        auto account_info = repo.s_get_all_accounts(100);

        return account_info;
    }

    auto account_info = repo.s_get_accounts_by_user(user_id);

    return account_info;
}

int l_delete_account(std::string account_id) {
    AccountRepository repo = AccountRepository(drogon::app().getDbClient());

    return repo.s_delete_account(account_id);
}
