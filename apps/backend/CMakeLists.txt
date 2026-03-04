include(FetchContent)

FetchContent_Declare(
    drogon
    GIT_REPOSITORY https://github.com/drogonframework/drogon.git
    GIT_TAG v1.9.5
)

FetchContent_MakeAvailable(drogon)

# Define the executable target
add_executable(backend
        src/main.cpp
        src/api/AccountController.cpp
        src/models/Account.h
        src/repositories/AccountRepository.cpp
        src/services/AccountService.cpp
        src/utils/Money.h
)

# Include directories for headers
target_include_directories(backend
        PRIVATE
        src/
        src/api
        src/models
        src/repositories
        src/services
        src/utils
)

# Link against dependencies
target_link_libraries(backend
        PRIVATE
        drogon
)