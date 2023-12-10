// Version: 1.0
// FCAI � OOP Programming � 2023 - Assignment 3
// Program Name:	Game OF Life.cpp
// Last Modification Date: 10/12/2023
// Author and ID and Group:	Mohamed Essam El-Din Hassan 20210579
// Teaching : Dr. Mohammad El-Ramly

#include "A3_S6_20210579_6.cpp"

int main()
{
    // Clear the file content before starting a new simulation run
    ofstream clearFile("Result.txt", ios::out | ios::trunc);
    clearFile.close();

    // Create a Universe with a 20x20 grid
    Universe universe(30, 30);

    // Run the simulation for 10 iterations
    universe.run(1000);

    return 0;
}
