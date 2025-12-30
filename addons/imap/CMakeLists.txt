cmake_minimum_required(VERSION 3.14)
project(mailserve VERSION 0.1.0 LANGUAGES C)

set(IMAP_SOURCES src/addon.c)

add_library(mailserve_imap SHARED ${IMAP_SOURCES})
target_link_libraries(mailserve_imap PUBLIC libmailserve)
set_target_properties(mailserve_imap PROPERTIES PREFIX "addons/")