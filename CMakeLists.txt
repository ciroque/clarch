cmake_minimum_required(VERSION 3.10)
project(clarch)

set(CMAKE_CXX_STANDARD 11)

add_executable(clarch main.cpp src/Args.cpp src/Args.h src/FileReader.cpp src/FileReader.h src/scanners/Scanner.h src/FileStats.cpp src/FileStats.h src/scanners/elixir/ElixirScanner.cpp src/scanners/elixir/ElixirScanner.h src/StringUtils.cpp src/StringUtils.h)
