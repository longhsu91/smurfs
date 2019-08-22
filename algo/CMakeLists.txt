
project(algo)

# executable
add_executable(topk_${PROJECT_NAME} topk.c)

# link library
set(${PROJECT_NAME}_libraries
    smurfs
)

target_link_libraries(topk_${PROJECT_NAME} ${${PROJECT_NAME}_libraries})
