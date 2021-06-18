set(SOURCES
    main.cpp
    duck.cpp
)

set(LIB_SOURCES
    ${PROJECT_SOURCE_DIR}/src/duck.cpp
)

add_executable(${TARGET} ${SOURCES})
target_include_directories(${TARGET} PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_library(${LIBRARY_TARGET} ${LIB_SOURCES})
target_include_directories(${LIBRARY_TARGET} PUBLIC ${PROJECT_SOURCE_DIR}/include)
