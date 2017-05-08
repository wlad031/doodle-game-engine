CMAKE_MINIMUM_REQUIRED(VERSION 3.5.0)
PROJECT(DoodleGameEngine)

AUX_SOURCE_DIRECTORY(src SOURCE_DIRECTORY)

SET(
        SOURCE_FILES
        entrypoint.cpp
        ${SOURCE_DIRECTORY}
)

ADD_EXECUTABLE(
        DoodleGameEngine
        ${SOURCE_FILES}
)

INCLUDE_DIRECTORIES(
        src/
        "${PROJECT_BINARY_DIR}"
)

TARGET_LINK_LIBRARIES(
        DoodleGameEngine
)