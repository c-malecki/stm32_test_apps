cmake_minimum_required(VERSION 3.22)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

set(CMAKE_PROJECT_NAME ds18b20_impl)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

project(${CMAKE_PROJECT_NAME})
message("Build type: " ${CMAKE_BUILD_TYPE})

enable_language(C ASM)

add_executable(${CMAKE_PROJECT_NAME})

add_subdirectory(cmake/stm32cubemx)

target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    Lib/Src/ds18b20.c
    Lib/Src/ow.c
)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    Lib/Inc
)

target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
    USE_HAL_DRIVER
    STM32F103xB
)

target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE
    $<$<CONFIG:Debug>:-Og -g3>
)

target_link_options(${CMAKE_PROJECT_NAME} PRIVATE
    $<$<CONFIG:Debug>:-g3>
    -Wl,-Map=${CMAKE_PROJECT_NAME}.map
)

# Predictable ELF name
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
    OUTPUT_NAME "${CMAKE_PROJECT_NAME}"
    SUFFIX ".elf"
)

list(REMOVE_ITEM CMAKE_C_IMPLICIT_LINK_LIBRARIES ob)

target_link_libraries(${CMAKE_PROJECT_NAME}
    stm32cubemx
)