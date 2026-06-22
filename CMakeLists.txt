cmake_minimum_required(VERSION 3.25)

project(UnitUnround)

find_package(Geode REQUIRED)

add_geode_mod(
    ${supertask.unit_unround}
    NO_SUBFOLDERS
    SOURCES 
        src/main.cpp
)

target_compile_definitions(${supertask.unit_unround} PRIVATE GEODE_EXTENSION)