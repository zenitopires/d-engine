cmake_minimum_required(VERSION 3.20)
project(d-engine LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Create the executable first
add_executable(app)

set_target_properties(app PROPERTIES C_STANDARD 23)
set_target_properties(app PROPERTIES C_STANDARD_REQUIRED YES)

# Include local headers
target_include_directories(app PRIVATE
    vendor/glad/include
    vendor/log.c/src
    vendor/cglm/include
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

target_sources(app PRIVATE
    main.c
    d-engine/core/os/window/WindowProperties.c
    d-engine/core/os/window/Window.c
    d-engine/core/gfx/VertexBuffer.c
    d-engine/core/gfx/IndexBuffer.c
    d-engine/core/gfx/VertexArrayObject.c
    d-engine/core/gfx/Shader.c
    d-engine/core/gfx/Renderer.c
    d-engine/core/application/Application.c
    d-engine/core/log/log.c
    vendor/glad/src/glad.c
    vendor/log.c/src/log.c
)

target_link_libraries(app PRIVATE SDL3::SDL3)

add_custom_command(TARGET app POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        ${CMAKE_CURRENT_BINARY_DIR}/assets
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(DEBUG)
endif()
