

add_executable(TestGame)
target_sources(TestGame
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)
target_include_directories(TestGame
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
target_link_libraries(TestGame PRIVATE Cruise)
