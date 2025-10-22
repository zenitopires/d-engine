cmake_minimum_required(VERSION 3.20)
project(d-engine LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Create the executable first
add_executable(d-test)

# Include local headers
target_include_directories(d-test PRIVATE
    vendor/glad/include
    vendor/log.c/src
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Option to use vendored SDL3
option(USE_VENDORED_SDL "Use vendored SDL3" ON)

if (USE_VENDORED_SDL)
    include(FetchContent)
    FetchContent_Declare(
        SDL3
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG release-3.2.0
        GIT_SHALLOW TRUE
    )

    set(SDL_SHARED ON CACHE BOOL "Build shared SDL3" FORCE)
    set(SDL_STATIC OFF CACHE BOOL "Build static SDL3" FORCE)

    FetchContent_MakeAvailable(SDL3)
else()
    find_package(SDL3 REQUIRED CONFIG)
endif()

target_sources(d-test PRIVATE
    main.c
    d-engine/core/os/window/WindowProperties.c
    d-engine/core/os/window/Window.c
    d-engine/core/gfx/VertexBuffer.c
    d-engine/core/gfx/IndexBuffer.c
    d-engine/core/gfx/VertexArrayObject.c
    d-engine/core/gfx/Shader.c
    d-engine/core/debug/debug.h
    vendor/glad/src/glad.c
    vendor/log.c/src/log.c
)

target_link_libraries(d-test PRIVATE SDL3::SDL3)

add_custom_command(TARGET d-test POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        ${CMAKE_CURRENT_BINARY_DIR}/assets
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(DEBUG)
endif()
