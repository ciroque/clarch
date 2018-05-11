cmake_minimum_required(VERSION 3.10)
project(clarch)

set(CMAKE_CXX_STANDARD 11)

add_executable(clarch main.cpp src/Args.cpp src/Args.h src/filesystem/FileReader.cpp src/filesystem/FileReader.h src/scanners/Scanner.h src/stats/ModuleStats.cpp src/stats/ModuleStats.h src/scanners/elixir/ElixirScanner.cpp src/scanners/elixir/ElixirScanner.h src/utility/StringUtils.cpp src/utility/StringUtils.h src/filesystem/DirectoryReader.cpp src/filesystem/DirectoryReader.h src/renderers/JsonRenderer.cpp src/renderers/JsonRenderer.h src/renderers/Renderer.h)

#target_link_libraries(${PROJECT_NAME} libstdc++fs)

message(WARNING "${CMAKE_CXX_FLAGS} ${CMAKE_SHARED_LINKER_FLAGS} ${CMAKE_MODULE_LINKER_FLAGS}")
