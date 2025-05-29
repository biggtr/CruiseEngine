

add_executable(TestGame)
target_sources(TestGame
    PRIVATE
    src/TestGame.cpp
    src/TestGameEntry.cpp
)
target_include_directories(TestGame
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
target_link_libraries(TestGame PRIVATE Cruise)
