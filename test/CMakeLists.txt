
project(smurfs_test)

# executable
add_executable(${PROJECT_NAME} test_list.c)

# link library
set(${PROJECT_NAME}_libraries
    smurfs
)
target_link_libraries(${PROJECT_NAME} ${${PROJECT_NAME}_libraries})

# install
install (TARGETS ${PROJECT_NAME} DESTINATION bin)