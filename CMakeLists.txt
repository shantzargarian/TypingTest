cmake_minimum_required(VERSION 3.17)
project(TypingTest)

set(CMAKE_CXX_STANDARD 14)

add_executable(TypingTest main.cpp Screen.cpp Screen.h Game.cpp Game.h MouseEvents.cpp MouseEvents.h Component.h Font.cpp Font.h MatchStatus.h)
target_link_libraries(TypingTest sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
