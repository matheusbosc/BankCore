
# Define the executable target
add_executable(cli-client
        src/main.cpp
)

# Include directories for headers
target_include_directories(cli-client
        PRIVATE
        src/
)

# Link against dependencies
target_link_libraries(cli-client
        PRIVATE
        #library names here
)