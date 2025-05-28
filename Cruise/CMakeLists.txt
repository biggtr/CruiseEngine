find_package(X11 REQUIRED)

add_library(Cruise STATIC)

file(GLOB_RECURSE SOURCES "src/*.cpp")
target_sources(Cruise
    PRIVATE
    ${SOURCES}
)

target_include_directories(Cruise
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(Cruise ${X11_LIBRARIES})

