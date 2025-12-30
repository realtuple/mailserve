cmake_minimum_required(VERSION 3.14)
project(mailserve VERSION 0.1.0 LANGUAGES C)

set(SMPT_SOURCES src/addon.c)

add_library(mailserve_smpt SHARED ${SMPT_SOURCES})
target_link_libraries(mailserve_smpt PUBLIC libmailserve)
set_target_properties(mailserve_smpt PROPERTIES PREFIX "addons/")