
set(${PROJECT_NAME}_sources
    list.c
)

add_library(${PROJECT_NAME} SHARED ${${PROJECT_NAME}_sources})

# install
install (TARGETS smurfs DESTINATION lib)
install (FILES "${PROJECT_SOURCE_DIR}/include/list.h" DESTINATION include)