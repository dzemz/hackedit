project(HackEdit.Editor.Backend.Tests)

file(GLOB_RECURSE SOURCE_FILES *.cpp)
set(LIBS HackEdit.Editor.Backend)

create_test(${PROJECT_NAME} ${LIBS})
qt5_use_modules(${PROJECT_NAME} Core Test)

