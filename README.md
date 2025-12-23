# MinigamesHub 🎮

A comprehensive collection of 50+ brain games and puzzles built with C++17.

## Features

✅ **50+ Games** across 6 categories
✅ **Production-Ready** C++17 codebase
✅ **Cross-Platform** (Windows, Linux, macOS)
✅ **Modern CMake** build system with CPM package manager
✅ **Two Interfaces Available**:
   - 🖥️ **GUI Version** - Polished graphical interface using Dear ImGui + SDL2
   - 📟 **Console Version** - Traditional terminal-based interface
✅ **Modular Architecture** for easy extension

## Game Categories

### 🧠 Word & Language Games (14)
1. Crossword - Fill in the crossword puzzle
2. Sudoku - Classic number puzzle (9x9 grid)
3. Scrabble Word Builder - Build words from letter tiles
4. Boggle Word Search - Find words in a grid of letters
5. Anagrams - Rearrange letters to form words
6. Word Ladder - Change one letter at a time to reach target
7. **Hangman** - Guess the word letter by letter (Fully Implemented)
8. Word Search - Classic grid-based word finding
9. Palindromes - Identify or construct palindromes
10. Fill-in-the-Blanks - Complete phrases with missing words
11. Rhyme Match - Find words that rhyme
12. Synonym Swap - Replace words with correct synonyms
13. Speed Typing Words - Test accuracy and speed
14. Missing Letter - Complete partially erased words

### 🔢 Logic & Number Games (8)
1. Sudoku Variants - Killer sudoku, diagonal sudoku
2. Kakuro - Crossword meets math
3. KenKen - Math-based logic puzzle
4. Nonograms (Picross) - Reveal pictures using number clues
5. Magic Square Builder - Build magic square puzzles
6. Number Sequence Guess - Predict the next number
7. 24 Game - Combine numbers to reach 24
8. Binary Puzzle (Takuzu) - Binary logic puzzle

### 🧩 Spatial/Visual Puzzles (11)
1. Jigsaw Puzzle - Complete the jigsaw puzzle
2. Tangram - Make shapes from shapes
3. Block Fit - Tetris-like turn-based puzzle
4. Shape Rotation - Rotate shapes to match
5. Sliding Tile Puzzle - Classic 15-puzzle
6. Mirror Laser - Redirect laser beams using mirrors
7. Maze Solver - Solve the maze
8. Pattern Completion - Choose the missing tile
9. Symmetry Puzzle - Reflect shapes correctly
10. Spot the Difference - Find differences between images
11. Perspective Puzzle - Illusion-based matching

### 🎮 Strategy & Thinking Games (9)
1. **Minesweeper** - Classic mine detection game (Fully Implemented)
2. Chess Puzzles - Checkmate in X moves
3. Logic Grid Puzzles - Solve logic grid puzzles
4. Tower of Hanoi - Classic tower puzzle
5. Flow/Pipe Connect - Connect matching colors
6. Lights Out - Turn all lights off
7. Dots and Boxes - Classic dots and boxes
8. Nim - Mathematical strategy game
9. Hex or Go Mini-Boards - Board game variants

### ⚡ Quick/Reflex/Hybrid Games (6)
1. Memory Match (Concentration) - Card matching game
2. Simon Says - Pattern memory game
3. Reaction Time Test - Test your reaction speed
4. Timed Sorting - Categorize items quickly
5. Pattern Speed Test - Pattern recognition speed test
6. Color-Word Stroop Test - Stroop effect test

### 🧪 Experimental/Fun Brain Games (2)
1. Rule Discovery Game - Guess the hidden rule
2. AI Judge Puzzle - AI scores creativity or efficiency

## Building from Source

### Prerequisites

- C++17 compatible compiler (GCC 7+, Clang 5+, MSVC 2017+)
- CMake 3.14 or higher
- Git (for CPM package manager to download dependencies)

### Build Instructions

#### GUI Version (Recommended)

The GUI version uses Dear ImGui with SDL2 for a polished, modern interface:

```bash
# Clone the repository
git clone https://github.com/OmgRod/MinigamesHub.git
cd MinigamesHub

# Create build directory
mkdir build && cd build

# Configure and build (GUI enabled by default)
cmake ..
cmake --build .

# Run the GUI version
./minigames_hub
```

#### Console Version

For the traditional terminal-based interface:

```bash
# Same build process, then run:
./minigames_hub_console
```

#### Disable GUI Build

If you want to build only the console version:

```bash
cmake .. -DBUILD_GUI=OFF
cmake --build .
```

### Platform-Specific Notes

**Linux/macOS:**
```bash
cmake ..
make -j$(nproc)
./minigames_hub         # GUI version
./minigames_hub_console # Console version
```

**Windows (Visual Studio):**
```bash
cmake .. -G "Visual Studio 16 2019"
cmake --build . --config Release
.\Release\minigames_hub.exe          # GUI version
.\Release\minigames_hub_console.exe  # Console version
```

**Windows (clang-cl/LLVM):**
```bash
cmake .. -G Ninja -DCMAKE_C_COMPILER="clang-cl.exe" -DCMAKE_CXX_COMPILER="clang-cl.exe"
cmake --build .
```

## Architecture

The project follows a clean, modular architecture:

```
MinigamesHub/
├── cmake/              # CPM.cmake package manager
├── include/            # Header files
│   ├── game_base.h    # Base game interface
│   ├── game_engine.h  # Game engine
│   ├── menu_system.h  # Menu system
│   ├── utils.h        # Utility functions
│   └── games/         # Game headers by category
│       ├── word/
│       ├── logic/
│       ├── spatial/
│       ├── strategy/
│       ├── reflex/
│       └── experimental/
├── src/               # Implementation files
│   ├── main.cpp       # Console entry point
│   ├── main_gui.cpp   # GUI entry point
│   ├── game_engine.cpp
│   ├── menu_system.cpp
│   ├── utils.cpp
│   └── games/         # Game implementations
└── CMakeLists.txt     # CMake configuration
```

## GUI Features

The GUI version provides a modern, polished interface with:

- 🎨 **Modern UI** - Clean, dark-themed interface using Dear ImGui
- 🎯 **Easy Navigation** - Browse games by category
- 📊 **Game Information** - View descriptions and categories for each game
- 🖱️ **Mouse Support** - Click and double-click to navigate
- 📐 **Resizable Window** - Adjust to your preferred size
- 🎮 **SDL2 Backend** - Hardware-accelerated rendering

## Code Quality

- ✅ Modern C++17 features
- ✅ RAII and smart pointers
- ✅ Object-oriented design with inheritance
- ✅ Cross-platform compatibility
- ✅ Clean separation of concerns
- ✅ Extensible plugin-style architecture
- ✅ GUI and Console versions share same game logic

## Adding New Games

To add a new game:

1. Create header in `include/games/<category>/<game_name>.h`
2. Create implementation in `src/games/<category>/<game_name>.cpp`
3. Inherit from `GameBase` and implement required methods
4. Register the game in both `src/main.cpp` and `src/main_gui.cpp`
5. Update CMakeLists.txt

Example:
```cpp
class MyGame : public GameBase {
public:
    void initialize() override;
    void run() override;
    void cleanup() override;
    std::string getName() const override { return "My Game"; }
    std::string getDescription() const override { return "Description"; }
    std::string getCategory() const override { return "Category"; }
};
```

## Contributing

Contributions are welcome! Please feel free to submit pull requests or open issues.

## License

This project is open source and available under the MIT License.

## Acknowledgments

Built with:
- CMake for build configuration
- CPM.cmake for dependency management
- C++17 STL for core functionality

---

**Enjoy playing! 🎮**
