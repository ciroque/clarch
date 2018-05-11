cmake_minimum_required(VERSION 3.10)
project(clarch)

set(CMAKE_CXX_STANDARD 11)

add_executable(clarch main.cpp src/Args.cpp src/Args.h src/FileReader.cpp src/FileReader.h src/scanners/Scanner.h src/FileStats.cpp src/FileStats.h src/scanners/elixir/ElixirScanner.cpp src/scanners/elixir/ElixirScanner.h src/StringUtils.cpp src/StringUtils.h src/DirectoryReader.cpp src/DirectoryReader.h src/renderers/JsonRenderer.cpp src/renderers/JsonRenderer.h src/renderers/Renderer.h)

#target_link_libraries(${PROJECT_NAME} libstdc++fs)

message(WARNING "${CMAKE_CXX_FLAGS} ${CMAKE_SHARED_LINKER_FLAGS} ${CMAKE_MODULE_LINKER_FLAGS}")
