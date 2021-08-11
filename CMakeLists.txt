cmake_minimum_required(VERSION 3.8)

set(VENDOR_FOLDER ${CMAKE_SOURCE_DIR}/Vendor)

project(Lava CXX)
file(GLOB_RECURSE ${PROJECT_NAME}Files ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/**.cpp ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/**.hpp)
add_executable(${PROJECT_NAME} ${${PROJECT_NAME}Files})

add_subdirectory(${VENDOR_FOLDER}/glfw)
target_include_directories(${PROJECT_NAME} PRIVATE ${VENDOR_FOLDER}/glfw/include)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

add_subdirectory(${VENDOR_FOLDER}/glm)
target_include_directories(${PROJECT_NAME} PRIVATE ${VENDOR_FOLDER}/glm/glm)
target_link_libraries(${PROJECT_NAME} PRIVATE glm)

find_package(Vulkan REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${Vulkan_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${Vulkan_LIBRARIES})