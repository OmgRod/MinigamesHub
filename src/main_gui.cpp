#include "game_engine.h"
#include "utils.h"
#include <SDL.h>
#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_sdlrenderer2.h>
#include <sstream>
#include <iostream>

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

// GUI wrapper for game output
class GUIOutputCapture {
public:
    std::stringstream buffer;
    std::string getOutput() {
        return buffer.str();
    }
    void clear() {
        buffer.str("");
        buffer.clear();
    }
};

static GUIOutputCapture guiOutput;
static std::vector<std::unique_ptr<GameBase>> allGames;
static GameBase* currentGame = nullptr;
static std::string gameOutput;
static std::string userInput;
static bool gameRunning = false;
static int selectedGameIndex = -1;
static int selectedCategory = -1;

void registerAllGames() {
    // Register Word & Language Games (14)
    allGames.push_back(std::make_unique<Crossword>());
    allGames.push_back(std::make_unique<Sudoku>());
    allGames.push_back(std::make_unique<Scrabble>());
    allGames.push_back(std::make_unique<Boggle>());
    allGames.push_back(std::make_unique<Anagrams>());
    allGames.push_back(std::make_unique<WordLadder>());
    allGames.push_back(std::make_unique<Hangman>());
    allGames.push_back(std::make_unique<WordSearch>());
    allGames.push_back(std::make_unique<Palindromes>());
    allGames.push_back(std::make_unique<FillBlanks>());
    allGames.push_back(std::make_unique<RhymeMatch>());
    allGames.push_back(std::make_unique<SynonymSwap>());
    allGames.push_back(std::make_unique<SpeedTyping>());
    allGames.push_back(std::make_unique<MissingLetter>());
    
    // Register Logic & Number Games (8)
    allGames.push_back(std::make_unique<SudokuVariants>());
    allGames.push_back(std::make_unique<Kakuro>());
    allGames.push_back(std::make_unique<KenKen>());
    allGames.push_back(std::make_unique<Nonograms>());
    allGames.push_back(std::make_unique<MagicSquare>());
    allGames.push_back(std::make_unique<NumberSequence>());
    allGames.push_back(std::make_unique<Game24>());
    allGames.push_back(std::make_unique<BinaryPuzzle>());
    
    // Register Spatial/Visual Puzzles (11)
    allGames.push_back(std::make_unique<Jigsaw>());
    allGames.push_back(std::make_unique<Tangram>());
    allGames.push_back(std::make_unique<BlockFit>());
    allGames.push_back(std::make_unique<ShapeRotation>());
    allGames.push_back(std::make_unique<SlidingTile>());
    allGames.push_back(std::make_unique<MirrorLaser>());
    allGames.push_back(std::make_unique<MazeSolver>());
    allGames.push_back(std::make_unique<PatternCompletion>());
    allGames.push_back(std::make_unique<SymmetryPuzzle>());
    allGames.push_back(std::make_unique<SpotDifference>());
    allGames.push_back(std::make_unique<PerspectivePuzzle>());
    
    // Register Strategy & Thinking Games (9)
    allGames.push_back(std::make_unique<Minesweeper>());
    allGames.push_back(std::make_unique<ChessPuzzles>());
    allGames.push_back(std::make_unique<LogicGrid>());
    allGames.push_back(std::make_unique<TowerHanoi>());
    allGames.push_back(std::make_unique<FlowConnect>());
    allGames.push_back(std::make_unique<LightsOut>());
    allGames.push_back(std::make_unique<DotsBoxes>());
    allGames.push_back(std::make_unique<Nim>());
    allGames.push_back(std::make_unique<HexGo>());
    
    // Register Quick/Reflex Games (6)
    allGames.push_back(std::make_unique<MemoryMatch>());
    allGames.push_back(std::make_unique<SimonSays>());
    allGames.push_back(std::make_unique<ReactionTime>());
    allGames.push_back(std::make_unique<TimedSorting>());
    allGames.push_back(std::make_unique<PatternSpeed>());
    allGames.push_back(std::make_unique<StroopTest>());
    
    // Register Experimental Games (2)
    allGames.push_back(std::make_unique<RuleDiscovery>());
    allGames.push_back(std::make_unique<AIJudge>());
}

void renderMainMenu() {
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);
    ImGui::Begin("MinigamesHub - 50+ Brain Games", nullptr,
                 ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | 
                 ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoBringToFrontOnFocus);

    // Title
    ImGui::PushFont(nullptr); // Use default font, but larger size
    ImGui::SetWindowFontScale(1.5f);
    ImGui::TextColored(ImVec4(0.2f, 0.8f, 1.0f, 1.0f), "MinigamesHub");
    ImGui::SetWindowFontScale(1.0f);
    ImGui::TextColored(ImVec4(0.7f, 0.7f, 0.7f, 1.0f), "A Collection of 50+ Brain Games & Puzzles");
    ImGui::Separator();
    ImGui::Spacing();

    // Category selection
    ImGui::Text("Select a Category:");
    ImGui::Spacing();
    
    const char* categories[] = {
        "📝 Word & Language Games (13)",
        "🔢 Logic & Number Games (9)",
        "🧩 Spatial/Visual Puzzles (11)",
        "♟️  Strategy & Thinking Games (9)",
        "⚡ Quick/Reflex Games (6)",
        "🧪 Experimental Games (2)"
    };
    
    ImGui::BeginChild("Categories", ImVec2(300, 0), true);
    for (int i = 0; i < 6; i++) {
        if (ImGui::Selectable(categories[i], selectedCategory == i)) {
            selectedCategory = i;
            selectedGameIndex = -1;
        }
    }
    ImGui::EndChild();
    
    ImGui::SameLine();
    
    // Game list
    ImGui::BeginChild("Games", ImVec2(0, 0), true);
    if (selectedCategory >= 0) {
        ImGui::Text("Games in this category:");
        ImGui::Separator();
        ImGui::Spacing();
        
        // Determine game range based on category
        int startIdx = 0, endIdx = 0;
        switch (selectedCategory) {
            case 0: startIdx = 0; endIdx = 13; break;   // Word & Language
            case 1: startIdx = 13; endIdx = 22; break;  // Logic & Number (13+9)
            case 2: startIdx = 22; endIdx = 33; break;  // Spatial (22+11)
            case 3: startIdx = 33; endIdx = 42; break;  // Strategy (33+9)
            case 4: startIdx = 42; endIdx = 48; break;  // Reflex (42+6)
            case 5: startIdx = 48; endIdx = 50; break;  // Experimental (48+2)
        }
        
        for (int i = startIdx; i < endIdx && i < static_cast<int>(allGames.size()); i++) {
            std::string gameLabel = allGames[i]->getName() + "\n   " + allGames[i]->getDescription();
            if (ImGui::Selectable(gameLabel.c_str(), selectedGameIndex == i, ImGuiSelectableFlags_AllowDoubleClick)) {
                selectedGameIndex = i;
                if (ImGui::IsMouseDoubleClicked(0)) {
                    currentGame = allGames[i].get();
                    gameOutput = "Starting " + currentGame->getName() + "...\n\n";
                    gameRunning = true;
                    currentGame->initialize();
                }
            }
        }
    } else {
        ImGui::TextWrapped("Please select a category from the left panel to view games.");
    }
    ImGui::EndChild();
    
    ImGui::End();
}

void renderGameWindow() {
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);
    ImGui::Begin(("Playing: " + currentGame->getName()).c_str(), nullptr,
                 ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | 
                 ImGuiWindowFlags_NoCollapse);

    // Game output area
    ImGui::BeginChild("GameOutput", ImVec2(0, -100), true, ImGuiWindowFlags_HorizontalScrollbar);
    ImGui::TextWrapped("%s", gameOutput.c_str());
    ImGui::EndChild();
    
    // Input area
    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Text("Game Information:");
    ImGui::BulletText("Category: %s", currentGame->getCategory().c_str());
    ImGui::BulletText("Description: %s", currentGame->getDescription().c_str());
    
    ImGui::Spacing();
    if (ImGui::Button("Back to Menu", ImVec2(200, 40))) {
        currentGame->cleanup();
        currentGame = nullptr;
        gameRunning = false;
        gameOutput.clear();
        selectedGameIndex = -1;
    }
    
    ImGui::End();
}

int main(int argc, char* argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
        std::cerr << "Error: SDL_Init(): " << SDL_GetError() << std::endl;
        return -1;
    }

    // Create window
    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Window* window = SDL_CreateWindow(
        "MinigamesHub - 50+ Brain Games",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        1280, 720,
        window_flags
    );
    if (window == nullptr) {
        std::cerr << "Error: SDL_CreateWindow(): " << SDL_GetError() << std::endl;
        return -1;
    }

    // Create renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Error: SDL_CreateRenderer(): " << SDL_GetError() << std::endl;
        return -1;
    }

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    
    // Customize style for a more polished look
    ImGuiStyle& style = ImGui::GetStyle();
    style.WindowRounding = 8.0f;
    style.FrameRounding = 4.0f;
    style.GrabRounding = 4.0f;
    style.ScrollbarRounding = 4.0f;
    style.WindowPadding = ImVec2(15, 15);
    style.FramePadding = ImVec2(8, 4);
    style.ItemSpacing = ImVec2(12, 8);
    
    // Custom color scheme
    ImVec4* colors = style.Colors;
    colors[ImGuiCol_WindowBg] = ImVec4(0.10f, 0.10f, 0.13f, 1.00f);
    colors[ImGuiCol_ChildBg] = ImVec4(0.13f, 0.13f, 0.16f, 1.00f);
    colors[ImGuiCol_Border] = ImVec4(0.25f, 0.25f, 0.28f, 1.00f);
    colors[ImGuiCol_FrameBg] = ImVec4(0.16f, 0.16f, 0.19f, 1.00f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.20f, 0.20f, 0.23f, 1.00f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.24f, 0.24f, 0.27f, 1.00f);
    colors[ImGuiCol_TitleBg] = ImVec4(0.12f, 0.12f, 0.15f, 1.00f);
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.15f, 0.15f, 0.18f, 1.00f);
    colors[ImGuiCol_Button] = ImVec4(0.20f, 0.60f, 0.90f, 0.80f);
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.30f, 0.70f, 1.00f, 1.00f);
    colors[ImGuiCol_ButtonActive] = ImVec4(0.15f, 0.50f, 0.80f, 1.00f);
    colors[ImGuiCol_Header] = ImVec4(0.20f, 0.60f, 0.90f, 0.60f);
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.30f, 0.70f, 1.00f, 0.80f);
    colors[ImGuiCol_HeaderActive] = ImVec4(0.20f, 0.60f, 0.90f, 1.00f);

    // Setup Platform/Renderer backends
    ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer2_Init(renderer);

    // Register all games
    registerAllGames();

    // Main loop
    bool done = false;
    while (!done) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            ImGui_ImplSDL2_ProcessEvent(&event);
            if (event.type == SDL_QUIT)
                done = true;
            if (event.type == SDL_WINDOWEVENT && 
                event.window.event == SDL_WINDOWEVENT_CLOSE && 
                event.window.windowID == SDL_GetWindowID(window))
                done = true;
        }

        // Start the Dear ImGui frame
        ImGui_ImplSDLRenderer2_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        // Render UI
        if (gameRunning && currentGame != nullptr) {
            renderGameWindow();
        } else {
            renderMainMenu();
        }

        // Rendering
        ImGui::Render();
        SDL_SetRenderDrawColor(renderer, 20, 20, 25, 255);
        SDL_RenderClear(renderer);
        ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());
        SDL_RenderPresent(renderer);
    }

    // Cleanup
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
