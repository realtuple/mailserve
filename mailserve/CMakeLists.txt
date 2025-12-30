set(MAILSERVE_SOURCES 
    src/main.c 
    src/server.c)

add_executable(mailserve ${MAILSERVE_SOURCES})
target_include_directories(mailserve PUBLIC inc/)