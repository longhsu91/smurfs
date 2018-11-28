
project(smurfs_test)

# executable
add_executable(${PROJECT_NAME}_list test_list.c)
add_executable(${PROJECT_NAME}_stack test_stack.c)

# link library
set(${PROJECT_NAME}_libraries
    smurfs
)

set(${PROJECT_NAME}_names
    ${PROJECT_NAME}_list
    ${PROJECT_NAME}_stack
)

target_link_libraries(${PROJECT_NAME}_list ${${PROJECT_NAME}_libraries})
target_link_libraries(${PROJECT_NAME}_stack ${${PROJECT_NAME}_libraries})

# install
install (TARGETS ${${PROJECT_NAME}_names} DESTINATION bin)