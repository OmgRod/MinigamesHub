cmake_minimum_required(VERSION 3.14)

project(MinigamesHub VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include CPM for package management
include(cmake/CPM.cmake)

# Compiler warnings
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

# Source files
set(SOURCES
    src/main.cpp
    src/game_engine.cpp
    src/menu_system.cpp
    src/utils.cpp
    
    # Word & Language Games
    src/games/word/crossword.cpp
    src/games/word/sudoku.cpp
    src/games/word/scrabble.cpp
    src/games/word/boggle.cpp
    src/games/word/anagrams.cpp
    src/games/word/word_ladder.cpp
    src/games/word/hangman.cpp
    src/games/word/word_search.cpp
    src/games/word/palindromes.cpp
    src/games/word/fill_blanks.cpp
    src/games/word/rhyme_match.cpp
    src/games/word/synonym_swap.cpp
    src/games/word/speed_typing.cpp
    src/games/word/missing_letter.cpp
    
    # Logic & Number Games
    src/games/logic/sudoku_variants.cpp
    src/games/logic/kakuro.cpp
    src/games/logic/kenken.cpp
    src/games/logic/nonograms.cpp
    src/games/logic/magic_square.cpp
    src/games/logic/number_sequence.cpp
    src/games/logic/game_24.cpp
    src/games/logic/binary_puzzle.cpp
    
    # Spatial/Visual Puzzles
    src/games/spatial/jigsaw.cpp
    src/games/spatial/tangram.cpp
    src/games/spatial/block_fit.cpp
    src/games/spatial/shape_rotation.cpp
    src/games/spatial/sliding_tile.cpp
    src/games/spatial/mirror_laser.cpp
    src/games/spatial/maze_solver.cpp
    src/games/spatial/pattern_completion.cpp
    src/games/spatial/symmetry.cpp
    src/games/spatial/spot_difference.cpp
    src/games/spatial/perspective.cpp
    
    # Strategy & Thinking Games
    src/games/strategy/minesweeper.cpp
    src/games/strategy/chess_puzzles.cpp
    src/games/strategy/logic_grid.cpp
    src/games/strategy/tower_hanoi.cpp
    src/games/strategy/flow_connect.cpp
    src/games/strategy/lights_out.cpp
    src/games/strategy/dots_boxes.cpp
    src/games/strategy/nim.cpp
    src/games/strategy/hex_go.cpp
    
    # Quick/Reflex Games
    src/games/reflex/memory_match.cpp
    src/games/reflex/simon_says.cpp
    src/games/reflex/reaction_time.cpp
    src/games/reflex/timed_sorting.cpp
    src/games/reflex/pattern_speed.cpp
    src/games/reflex/stroop_test.cpp
    
    # Experimental Games
    src/games/experimental/rule_discovery.cpp
    src/games/experimental/ai_judge.cpp
)

set(HEADERS
    include/game_engine.h
    include/menu_system.h
    include/utils.h
    include/game_base.h
    
    # Word & Language Games
    include/games/word/crossword.h
    include/games/word/sudoku.h
    include/games/word/scrabble.h
    include/games/word/boggle.h
    include/games/word/anagrams.h
    include/games/word/word_ladder.h
    include/games/word/hangman.h
    include/games/word/word_search.h
    include/games/word/palindromes.h
    include/games/word/fill_blanks.h
    include/games/word/rhyme_match.h
    include/games/word/synonym_swap.h
    include/games/word/speed_typing.h
    include/games/word/missing_letter.h
    
    # Logic & Number Games
    include/games/logic/sudoku_variants.h
    include/games/logic/kakuro.h
    include/games/logic/kenken.h
    include/games/logic/nonograms.h
    include/games/logic/magic_square.h
    include/games/logic/number_sequence.h
    include/games/logic/game_24.h
    include/games/logic/binary_puzzle.h
    
    # Spatial/Visual Puzzles
    include/games/spatial/jigsaw.h
    include/games/spatial/tangram.h
    include/games/spatial/block_fit.h
    include/games/spatial/shape_rotation.h
    include/games/spatial/sliding_tile.h
    include/games/spatial/mirror_laser.h
    include/games/spatial/maze_solver.h
    include/games/spatial/pattern_completion.h
    include/games/spatial/symmetry.h
    include/games/spatial/spot_difference.h
    include/games/spatial/perspective.h
    
    # Strategy & Thinking Games
    include/games/strategy/minesweeper.h
    include/games/strategy/chess_puzzles.h
    include/games/strategy/logic_grid.h
    include/games/strategy/tower_hanoi.h
    include/games/strategy/flow_connect.h
    include/games/strategy/lights_out.h
    include/games/strategy/dots_boxes.h
    include/games/strategy/nim.h
    include/games/strategy/hex_go.h
    
    # Quick/Reflex Games
    include/games/reflex/memory_match.h
    include/games/reflex/simon_says.h
    include/games/reflex/reaction_time.h
    include/games/reflex/timed_sorting.h
    include/games/reflex/pattern_speed.h
    include/games/reflex/stroop_test.h
    
    # Experimental Games
    include/games/experimental/rule_discovery.h
    include/games/experimental/ai_judge.h
)

# Create executable
add_executable(minigames_hub ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(minigames_hub PRIVATE include)

# Platform-specific settings
if(WIN32)
    target_compile_definitions(minigames_hub PRIVATE PLATFORM_WINDOWS)
elseif(UNIX AND NOT APPLE)
    target_compile_definitions(minigames_hub PRIVATE PLATFORM_LINUX)
elseif(APPLE)
    target_compile_definitions(minigames_hub PRIVATE PLATFORM_MACOS)
endif()

# Installation
install(TARGETS minigames_hub DESTINATION bin)
