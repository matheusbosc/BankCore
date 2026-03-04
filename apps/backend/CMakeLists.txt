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
)

# Include directories for headers
target_include_directories(backend
        PRIVATE
        src/
)

# Link against dependencies
target_link_libraries(backend
        PRIVATE
        drogon
        drogonframework
)