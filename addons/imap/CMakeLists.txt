add_library(mailserve_imap SHARED main.c)
set_target_properties(mailserve_imap PROPERTIES PREFIX "addons/")
target_include_directories(mailserve_imap PUBLIC ../../inc)