
# Define the executable target
add_executable(web-client
        src/main.cpp
)

# Include directories for headers
target_include_directories(web-client
        PRIVATE
        src/
)

# Link against dependencies
target_link_libraries(web-client
        PRIVATE
        #library names here
)