cmake_minimum_required(VERSION 3.26)
project(ChoTR_1)
set(CMAKE_CXX_STANDARD 20)
include(FetchContent)
FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt
        GIT_TAG 10.1.1
)
FetchContent_Declare(
        sfml
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.0
)
FetchContent_MakeAvailable(fmt)
FetchContent_MakeAvailable(sfml)
add_executable(ChoTR_1 main.cpp
        src/game/Game.cpp
        src/game/Game.h
        ui/Button.cpp
        ui/Button.h
        src/game/MenuState.cpp
        src/game/MenuState.h
        src/game/GameStateManager.cpp
        src/game/GameStateManager.h
        src/game/GameState.h)
target_link_libraries(
        ChoTR_1
        fmt
        sfml-graphics
        sfml-window
        sfml-system
)
IF (WIN32)
    add_custom_command(TARGET ChoTR_1 POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:ChoTR_1> $<TARGET_FILE_DIR:ChoTR_1>
            COMMAND_EXPAND_LISTS
    )
ENDIF ()