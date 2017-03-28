

add_executable(getdate getdate.c)

add_custom_command(
	TARGET getdate
	POST_BUILD COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/getdate
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../../include/yalecad)
				   
