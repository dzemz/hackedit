project(HackEdit.Common.Logging.Tests)

file(GLOB_RECURSE SOURCE_FILES *.cpp)
set(LIBS HackEdit.Common.Logging)

create_test(${PROJECT_NAME} ${LIBS})
