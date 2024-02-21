project(Game)
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)

include_directories(..)
add_library(Game STATIC ./Game.cpp ../Game.h)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-network sfml-graphics sfml-window)