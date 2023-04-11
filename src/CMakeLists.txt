#include_directories (../include)
#PROJECT_SOURCE_DIR:root dir
#EXECUTABLE_OUTPUT_PATH:can use file position
include_directories (${PROJECT_SOURCE_DIR}/include)

aux_source_directory (. SOURCES)
add_executable (${PROJECT_NAME}  ${SOURCES} )

#set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
