add_library(mailserve_smpt SHARED main.c)
set_target_properties(mailserve_smpt PROPERTIES PREFIX "addons/")