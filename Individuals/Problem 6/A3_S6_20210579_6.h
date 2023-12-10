#ifndef A2_S6_20210579_6_H
#define A2_S6_20210579_6_H

#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
class Universe
{
private:
    int rows;
    int columns;
    vector<vector<int>> grid;
    vector<vector<int>> nextGrid;

public:
    // Constructor to initialize the Universe with specified rows and columns
    Universe(int rows, int columns);

    // Method to initialize the grid with a predefined pattern
    void initialize();

    // Method to count alive neighbors for a given cell
    int countNeighbors(int x, int y);

    // Method to compute the next generation of the grid based on Game of Life rules
    void nextGeneration();

    // Method to display the current state of the grid
    void display(int iteration) const;

    // Method to run the simulation for a specified number of iterations
    void run(int iterations);
};

#endif /* GAMEOFLIFE_H */
