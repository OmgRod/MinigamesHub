#include "game_engine.h"
#include "utils.h"

// Word & Language Games
#include "games/word/crossword.h"
#include "games/word/sudoku.h"
#include "games/word/scrabble.h"
#include "games/word/boggle.h"
#include "games/word/anagrams.h"
#include "games/word/word_ladder.h"
#include "games/word/hangman.h"
#include "games/word/word_search.h"
#include "games/word/palindromes.h"
#include "games/word/fill_blanks.h"
#include "games/word/rhyme_match.h"
#include "games/word/synonym_swap.h"
#include "games/word/speed_typing.h"
#include "games/word/missing_letter.h"

// Logic & Number Games
#include "games/logic/sudoku_variants.h"
#include "games/logic/kakuro.h"
#include "games/logic/kenken.h"
#include "games/logic/nonograms.h"
#include "games/logic/magic_square.h"
#include "games/logic/number_sequence.h"
#include "games/logic/game_24.h"
#include "games/logic/binary_puzzle.h"

// Spatial/Visual Puzzles
#include "games/spatial/jigsaw.h"
#include "games/spatial/tangram.h"
#include "games/spatial/block_fit.h"
#include "games/spatial/shape_rotation.h"
#include "games/spatial/sliding_tile.h"
#include "games/spatial/mirror_laser.h"
#include "games/spatial/maze_solver.h"
#include "games/spatial/pattern_completion.h"
#include "games/spatial/symmetry.h"
#include "games/spatial/spot_difference.h"
#include "games/spatial/perspective.h"

// Strategy & Thinking Games
#include "games/strategy/minesweeper.h"
#include "games/strategy/chess_puzzles.h"
#include "games/strategy/logic_grid.h"
#include "games/strategy/tower_hanoi.h"
#include "games/strategy/flow_connect.h"
#include "games/strategy/lights_out.h"
#include "games/strategy/dots_boxes.h"
#include "games/strategy/nim.h"
#include "games/strategy/hex_go.h"

// Quick/Reflex Games
#include "games/reflex/memory_match.h"
#include "games/reflex/simon_says.h"
#include "games/reflex/reaction_time.h"
#include "games/reflex/timed_sorting.h"
#include "games/reflex/pattern_speed.h"
#include "games/reflex/stroop_test.h"

// Experimental Games
#include "games/experimental/rule_discovery.h"
#include "games/experimental/ai_judge.h"

#include <iostream>
#include <memory>

int main() {
    try {
        GameEngine engine;
        engine.initialize();
        
        // Register Word & Language Games (14)
        engine.registerGame(std::make_unique<Crossword>());
        engine.registerGame(std::make_unique<Sudoku>());
        engine.registerGame(std::make_unique<Scrabble>());
        engine.registerGame(std::make_unique<Boggle>());
        engine.registerGame(std::make_unique<Anagrams>());
        engine.registerGame(std::make_unique<WordLadder>());
        engine.registerGame(std::make_unique<Hangman>());
        engine.registerGame(std::make_unique<WordSearch>());
        engine.registerGame(std::make_unique<Palindromes>());
        engine.registerGame(std::make_unique<FillBlanks>());
        engine.registerGame(std::make_unique<RhymeMatch>());
        engine.registerGame(std::make_unique<SynonymSwap>());
        engine.registerGame(std::make_unique<SpeedTyping>());
        engine.registerGame(std::make_unique<MissingLetter>());
        
        // Register Logic & Number Games (8)
        engine.registerGame(std::make_unique<SudokuVariants>());
        engine.registerGame(std::make_unique<Kakuro>());
        engine.registerGame(std::make_unique<KenKen>());
        engine.registerGame(std::make_unique<Nonograms>());
        engine.registerGame(std::make_unique<MagicSquare>());
        engine.registerGame(std::make_unique<NumberSequence>());
        engine.registerGame(std::make_unique<Game24>());
        engine.registerGame(std::make_unique<BinaryPuzzle>());
        
        // Register Spatial/Visual Puzzles (11)
        engine.registerGame(std::make_unique<Jigsaw>());
        engine.registerGame(std::make_unique<Tangram>());
        engine.registerGame(std::make_unique<BlockFit>());
        engine.registerGame(std::make_unique<ShapeRotation>());
        engine.registerGame(std::make_unique<SlidingTile>());
        engine.registerGame(std::make_unique<MirrorLaser>());
        engine.registerGame(std::make_unique<MazeSolver>());
        engine.registerGame(std::make_unique<PatternCompletion>());
        engine.registerGame(std::make_unique<SymmetryPuzzle>());
        engine.registerGame(std::make_unique<SpotDifference>());
        engine.registerGame(std::make_unique<PerspectivePuzzle>());
        
        // Register Strategy & Thinking Games (9)
        engine.registerGame(std::make_unique<Minesweeper>());
        engine.registerGame(std::make_unique<ChessPuzzles>());
        engine.registerGame(std::make_unique<LogicGrid>());
        engine.registerGame(std::make_unique<TowerHanoi>());
        engine.registerGame(std::make_unique<FlowConnect>());
        engine.registerGame(std::make_unique<LightsOut>());
        engine.registerGame(std::make_unique<DotsBoxes>());
        engine.registerGame(std::make_unique<Nim>());
        engine.registerGame(std::make_unique<HexGo>());
        
        // Register Quick/Reflex Games (6)
        engine.registerGame(std::make_unique<MemoryMatch>());
        engine.registerGame(std::make_unique<SimonSays>());
        engine.registerGame(std::make_unique<ReactionTime>());
        engine.registerGame(std::make_unique<TimedSorting>());
        engine.registerGame(std::make_unique<PatternSpeed>());
        engine.registerGame(std::make_unique<StroopTest>());
        
        // Register Experimental Games (2)
        engine.registerGame(std::make_unique<RuleDiscovery>());
        engine.registerGame(std::make_unique<AIJudge>());
        
        // Run the game engine
        engine.run();
        engine.shutdown();
        
        std::cout << "\nThank you for playing MinigamesHub!\n";
        
    } catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
