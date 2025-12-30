cmake_minimum_required(VERSION 3.14)
project(mailserve VERSION 0.1.0 LANGUAGES C)

# Flat output
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)

add_subdirectory(mailserve/)

file(GLOB LIBNET_ADDONS LIST_DIRECTORIES true "addons/*")

foreach(LIBNET_ADDON IN LISTS LIBNET_ADDONS)
    add_subdirectory(${LIBNET_ADDON})
    message("-- [mailserve] Appending addon ${LIBNET_ADDON}")
endforeach()
