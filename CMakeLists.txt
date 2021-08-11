cmake_minimum_required(VERSION 3.8)

project(Lava CXX)
file(GLOB_RECURSE ${PROJECT_NAME}Files ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/**.cpp ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/**.hpp)
add_executable(${PROJECT_NAME} ${${PROJECT_NAME}Files})