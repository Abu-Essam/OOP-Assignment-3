#include "A3_S6_20210579_6.h"

// Constructor definition
Universe::Universe(int rows, int columns) : rows(rows), columns(columns)
{
    grid.resize(rows, vector<int>(columns, 0));     // Initialize grid with all dead cells
    nextGrid.resize(rows, vector<int>(columns, 0)); // Initialize nextGrid

    initialize(); // Set initial pattern, e.g., glider, in the center of the grid
}

// Method to initialize the grid with a predefined pattern, e.g., glider
void Universe::initialize()
{
    // Define the initial pattern (e.g., glider)
    vector<vector<int>> gliderPattern = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 1, 1}};

    // Calculate the starting position to place the pattern at the center of the grid
    int startRow = rows / 2 - gliderPattern.size() / 2;
    int startCol = columns / 2 - gliderPattern[0].size() / 2;

    // Place the pattern in the grid
    for (size_t i = 0; i < gliderPattern.size(); ++i)
    {
        for (size_t j = 0; j < gliderPattern[0].size(); ++j)
        {
            grid[startRow + i][startCol + j] = gliderPattern[i][j];
        }
    }
}

// void Universe::initialize()
// {
//     grid.resize(rows, std::vector<int>(columns, 0)); // Initialize grid with all dead cells

//     // Block-laying switch engine pattern initialization
//     grid[5][1] = 1;
//     grid[5][2] = 1;
//     grid[6][1] = 1;
//     grid[6][2] = 1;

//     grid[3][13] = 1;
//     grid[3][14] = 1;
//     grid[4][12] = 1;
//     grid[4][16] = 1;
//     grid[5][11] = 1;
//     grid[5][17] = 1;
//     grid[6][11] = 1;
//     grid[6][15] = 1;
//     grid[6][17] = 1;
//     grid[6][18] = 1;
//     grid[7][11] = 1;
//     grid[7][17] = 1;
//     grid[8][12] = 1;
//     grid[8][16] = 1;
//     grid[9][13] = 1;
//     grid[9][14] = 1;

//     grid[1][25] = 1;
//     grid[2][23] = 1;
//     grid[2][25] = 1;
//     grid[3][21] = 1;
//     grid[3][22] = 1;
//     grid[4][21] = 1;
//     grid[4][22] = 1;
//     grid[5][21] = 1;
//     grid[5][22] = 1;
//     grid[6][23] = 1;
//     grid[6][25] = 1;
//     grid[7][25] = 1;

//     grid[3][35] = 1;
//     grid[3][36] = 1;
//     grid[4][35] = 1;
//     grid[4][36] = 1;

//     // Write the initial grid to the "Result.txt" file
// }

// void Universe::initialize() {
//     grid.resize(rows, std::vector<int>(columns, 0)); // Initialize grid with all dead cells

//     // Pulsar pattern initialization
//     int center = rows / 2 - 3;

//     grid[center][center + 2] = 1;
//     grid[center][center + 3] = 1;
//     grid[center][center + 4] = 1;
//     grid[center][center + 8] = 1;
//     grid[center][center + 9] = 1;
//     grid[center][center + 10] = 1;

//     grid[center + 5][center] = 1;
//     grid[center + 5][center + 5] = 1;
//     grid[center + 5][center + 7] = 1;
//     grid[center + 5][center + 12] = 1;

//     grid[center + 7][center] = 1;
//     grid[center + 7][center + 5] = 1;
//     grid[center + 7][center + 7] = 1;
//     grid[center + 7][center + 12] = 1;

//     grid[center + 8][center + 2] = 1;
//     grid[center + 8][center + 3] = 1;
//     grid[center + 8][center + 4] = 1;
//     grid[center + 8][center + 8] = 1;
//     grid[center + 8][center + 9] = 1;
//     grid[center + 8][center + 10] = 1;

//     grid[center + 2][center + 2] = 1;
//     grid[center + 2][center + 3] = 1;
//     grid[center + 2][center + 4] = 1;
//     grid[center + 2][center + 8] = 1;
//     grid[center + 2][center + 9] = 1;
//     grid[center + 2][center + 10] = 1;

//     grid[center + 3][center] = 1;
//     grid[center + 3][center + 5] = 1;
//     grid[center + 3][center + 7] = 1;
//     grid[center + 3][center + 12] = 1;

//     grid[center + 3][center + 2] = 1;
//     grid[center + 3][center + 3] = 1;
//     grid[center + 3][center + 4] = 1;
//     grid[center + 3][center + 8] = 1;
//     grid[center + 3][center + 9] = 1;
//     grid[center + 3][center + 10] = 1;

//     // Write the initial grid to the "Result.txt" file
// }

// Method to count alive neighbors for a given cell
int Universe::countNeighbors(int x, int y)
{
    int count = 0;
    for (int i = -1; i <= 1; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
            int row = (x + i + rows) % rows;       // Handle edge conditions using modulo
            int col = (y + j + columns) % columns; // Handle edge conditions using modulo
            count += grid[row][col];
        }
    }
    count -= grid[x][y]; // Exclude the cell itself from the count
    return count;
}

// Method to compute the next generation of the grid based on Game of Life rules
void Universe::nextGeneration()
{
    vector<vector<int>> newGrid(rows, vector<int>(columns, 0));

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            int neighbors = countNeighbors(i, j);
            if (grid[i][j] == 1)
            {
                if (neighbors < 2 || neighbors > 3)
                {
                    newGrid[i][j] = 0; // Cell dies due to underpopulation or overpopulation
                }
                else
                {
                    newGrid[i][j] = 1; // Cell survives
                }
            }
            else
            {
                if (neighbors == 3)
                {
                    newGrid[i][j] = 1; // Cell becomes alive due to reproduction
                }
            }
        }
    }

    nextGrid = newGrid; // Update nextGrid with the new generation
}

// Method to display the current state of the grid
void Universe::display(int iteration) const
{
    std::ofstream file("Result.txt", std::ios_base::app);

    if (file.is_open())
    {
        file << "Iteration: " << iteration << std::endl;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                if (grid[i][j] == 1)
                {
                    file << "| X ";
                }
                else
                {
                    file << "| - ";
                }
            }
            file << '|' << std::endl;
        }
        file << std::endl;
        file.close();
    }
    else
    {
        std::cout << "Unable to open the file for writing." << std::endl;
    }
}

// Method to run the simulation for a specified number of iterations
void Universe::run(int maxIterations)
{
    int iteration = 0;
    bool stable = false;
    bool allDead = false;

    while (iteration < maxIterations && !stable && !allDead)
    {
        nextGeneration();

        display(iteration);
        // Write the current grid to the "Result.txt" file and display

        // Check for a stable configuration (pulsar repeats every 3 iterations)
        if (iteration > 2 && grid == nextGrid)
        {
            display(iteration + 1);
            std::cout << "Simulation reached a stable configuration at iteration " << iteration << "." << std::endl;
            stable = true;
        }

        // Check for all cells dead condition
        allDead = true;
        for (const auto &row : grid)
        {
            for (int cell : row)
            {
                if (cell == 1)
                {
                    allDead = false;
                    break;
                }
            }
            if (!allDead)
            {
                break;
            }
        }

        if (allDead)
        {
            std::cout << "All cells have died at iteration " << iteration << ". Simulation stopped." << std::endl;
        }

        grid = nextGrid;                                     // Update grid with the next generation
        nextGrid.clear();                                    // Clear nextGrid for the next iteration
        nextGrid.resize(rows, std::vector<int>(columns, 0)); // Resize and prepare nextGrid

        iteration++;
        std::cout << "Iteration: " << iteration << std::endl; // Debug output for iteration count
    }

    if (!stable && !allDead)
    {
        std::cout << "Simulation completed after " << maxIterations << " iterations." << std::endl;
    }
}
