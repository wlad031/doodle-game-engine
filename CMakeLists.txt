CMAKE_MINIMUM_REQUIRED(VERSION 3.3.0)
PROJECT(DoodleGameEngine)

# Set some useful path-variables
SET(BUILD_DIRECTORY_NAME "build")
SET(BINARY_DIRECTORY_NAME "bin")
SET(LIB_DIRECTORY_NAME "lib")
SET(ARCHIVE_DIRECTORY_NAME "archive")

SET(PROJECT_DIRECTORY \"${PROJECT_SOURCE_DIR}/\")
SET(PROJECT_LIB_DIRECTORY ${PROJECT_SOURCE_DIR}/${LIB_DIRECTORY_NAME})

SET(
        CMAKE_ARCHIVE_OUTPUT_DIRECTORY
        ${PROJECT_SOURCE_DIR}/${BUILD_DIRECTORY_NAME}/${ARCHIVE_DIRECTORY_NAME}
)
SET(
        CMAKE_LIBRARY_OUTPUT_DIRECTORY
        ${PROJECT_SOURCE_DIR}/${BUILD_DIRECTORY_NAME}/${LIB_DIRECTORY_NAME}
)
SET(
        CMAKE_RUNTIME_OUTPUT_DIRECTORY
        ${PROJECT_SOURCE_DIR}/${BUILD_DIRECTORY_NAME}/${BINARY_DIRECTORY_NAME}
)

SET_TARGET_PROPERTIES(
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY CMAKE_ARCHIVE_OUTPUT_DIRECTORY
        LIBRARY_OUTPUT_DIRECTORY CMAKE_LIBRARY_OUTPUT_DIRECTORY
        RUNTIME_OUTPUT_DIRECTORY CMAKE_RUNTIME_OUTPUT_DIRECTORY
)

INCLUDE(ExternalProject)

SET(EASYLOGGINGPP_NAME Easyloggingpp)
SET(
        EASYLOGGINGPP_DIRECTORY
        ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${EASYLOGGINGPP_NAME}
)
SET(
        EASYLOGGINGPP_BUILD_DIRECTORY
        ${EASYLOGGINGPP_DIRECTORY}/${BUILD_DIRECTORY_NAME}
)
SET(
        EASYLOGGINGPP_INCLUDE
        ${EASYLOGGINGPP_BUILD_DIRECTORY}/INSTALL/include
)
EXTERNALPROJECT_ADD(
        Easyloggingpp
        GIT_REPOSITORY https://github.com/easylogging/easyloggingpp
        GIT_TAG v9.83
        SOURCE_DIR ${EASYLOGGINGPP_DIRECTORY}
        BINARY_DIR ${EASYLOGGINGPP_BUILD_DIRECTORY}
        UPDATE_COMMAND ""
        PATCH_COMMAND ""
        CMAKE_GENERATOR ${gen}
        CMAKE_ARGS
        ${ep_common_args}
        -DCMAKE_BUILD_TYPE:STRING=Release
        -DCMAKE_INSTALL_PREFIX:PATH=${EASYLOGGINGPP_BUILD_DIRECTORY}/INSTALL
)
INCLUDE_DIRECTORIES("${EASYLOGGINGPP_INCLUDE}")

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

TARGET_COMPILE_FEATURES(DoodleGameEngine PUBLIC cxx_std_1z)
TARGET_INCLUDE_DIRECTORIES(
        DoodleGameEngine INTERFACE
        src/
        "${PROJECT_BINARY_DIR}"
)

ADD_DEPENDENCIES(DoodleGameEngine Easyloggingpp)
