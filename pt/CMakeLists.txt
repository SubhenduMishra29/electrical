# CMakeLists.txt

cmake_minimum_required(VERSION 3.0)
project(PotentialTransformerDemo)

# Add the library target
add_library(PotentialTransformer
    PotentialTransformer.cpp
)

# Add the include directory to the library target
target_include_directories(PotentialTransformer
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

# Add the executable target for main.cpp
add_executable(MainTest
    main.cpp
)

# Link the executable target with the library
target_link_libraries(MainTest
    PRIVATE PotentialTransformer
)
