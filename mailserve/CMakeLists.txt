cmake_minimum_required(VERSION 3.14)
project(mailserve VERSION 0.1.0 LANGUAGES C)

add_library(libmailserve INTERFACE)
target_include_directories(libmailserve INTERFACE inc/)

set(MAILSERVE_SOURCES 
    src/io/fs.c

    src/main.c 
    src/server.c)
    
add_executable(mailserve ${MAILSERVE_SOURCES})
target_link_libraries(mailserve PUBLIC libmailserve)