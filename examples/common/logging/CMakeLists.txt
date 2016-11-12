project(Examples.Common.Logging)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} HackEdit.Common.Logging)
configure_file(example-log-config.ini example-log-config.ini)