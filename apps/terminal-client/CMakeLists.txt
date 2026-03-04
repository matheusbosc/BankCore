
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
        #library names here
)