set(AppList "Balistics")

file(GLOB GENERIC_APP_SRC "./*.cpp")
file(GLOB GENERIC_APP_HDR "./*.hpp")

foreach(App ${AppList})

    file(GLOB_RECURSE APP_SRC "./${App}/*.cpp")
    file(GLOB_RECURSE APP_HDR "./${App}/*.hpp")

    add_executable(${App} ${SRC} ${GENERIC_APP_SRC} ${APP_SRC} ${HDR} ${APP_HDR} ${GENERIC_APP_HDR})

    target_include_directories(${App} PUBLIC "../inc")
    target_include_directories(${App} PUBLIC "./inc")
    target_include_directories(${App} PRIVATE "./")
    target_include_directories(${App} PRIVATE "./${App}")
    target_link_libraries(${App} GL GLU glut)

endforeach()

