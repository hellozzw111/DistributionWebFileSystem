add_subdirectory(buffer)
add_subdirectory(config)
add_subdirectory(http)
add_subdirectory(kafka)
add_subdirectory(log)
add_subdirectory(pool)
add_subdirectory(server)
add_subdirectory(timer)

set(SRC_LIST main.cpp)
add_executable(webserver ${SRC_LIST})
target_link_libraries(webserver rdkafka++ pthread mysqlclient)

