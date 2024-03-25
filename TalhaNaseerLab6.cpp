#include <iostream>
#include <fstream>
#include <iomanip> // For setw

const int MAX_SIZE = 10; // Maximum size of the square matrix

// Function to read matrix data from a file
void readMatrixFromFile(int firstMatrix[][MAX_SIZE], int size, std::ifstream& file) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            file >> firstMatrix[i][j];
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << std::setw(5) << matrix[i][j] << " "; // Modified setw value
        }
        std::cout << std::endl;
    }
}

// Function to add two matrices
void addMatrices(int firstMatrix[][MAX_SIZE], int secondMatrix[][MAX_SIZE], int result[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = firstMatrix[i][j] + secondMatrix[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int firstMatrix[][MAX_SIZE], int secondMatrix[][MAX_SIZE], int result[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}

// Function to subtract one matrix from another
void subtractMatrices(int firstMatrix[][MAX_SIZE], int secondMatrix[][MAX_SIZE], int result[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = firstMatrix[i][j] - secondMatrix[i][j];
        }
    }
}

// Function to update an element of the matrix
void updateElement(int matrix[][MAX_SIZE], int row, int col, int newValue, int size) {
    if (row >= 0 && row < size && col >= 0 && col < size) {
        matrix[row][col] = newValue;
    } else {
        std::cerr << "Invalid row or column index! Please try again." << std::endl; // Modified error message
    }
}

// Function to find the maximum value in a matrix
int getMaxValue(int matrix[][MAX_SIZE], int size) {
    int maxVal = matrix[0][0];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
            }
        }
    }
    return maxVal;
}

// Function to transpose a matrix
void transposeMatrix(int matrix[][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
}

int main() {
    std::string filename;
    std::cout << "Enter the name of the input file: ";
    std::cin >> filename;

    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Error: Failed to open the input file." << std::endl; // Modified error message
        return 1;
    }

    int size;
    inputFile >> size;

    int firstMatrix[MAX_SIZE][MAX_SIZE];
    int secondMatrix[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    // Read matrices A and B from the input file
    readMatrixFromFile(firstMatrix, size, inputFile);
    readMatrixFromFile(secondMatrix, size, inputFile);

    // Close the input file
    inputFile.close();

    std::cout << "Matrix 1:" << std::endl; // Modified output message
    printMatrix(firstMatrix, size);
    std::cout << std::endl;

    std::cout << "Matrix 2:" << std::endl; // Modified output message
    printMatrix(secondMatrix, size);
    std::cout << std::endl;

    // Menu for matrix operations
    int choice;
    do {
        std::cout << "Choose an operation:" << std::endl;
        std::cout << "1. Add two matrices" << std::endl;
        std::cout << "2. Multiply two matrices" << std::endl;
        std::cout << "3. Subtract the second matrix from the first matrix" << std::endl;
        std::cout << "4. Update an element of the first matrix" << std::endl;
        std::cout << "5. Get the max value of the first matrix" << std::endl;
        std::cout << "6. Transpose the first matrix" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addMatrices(firstMatrix, secondMatrix, result, size);
                std::cout << "Matrix Sum (Matrix 1 + Matrix 2):" << std::endl; // Modified output message
                printMatrix(result, size);
                break;
            case 2:
                multiplyMatrices(firstMatrix, secondMatrix, result, size);
                std::cout << "Matrix Product (Matrix 1 * Matrix 2):" << std::endl; // Modified output message
                printMatrix(result, size);
                break;
            case 3:
                subtractMatrices(firstMatrix, secondMatrix, result, size);
                std::cout << "Matrix Difference (Matrix 1 - Matrix 2):" << std::endl; // Modified output message
               
printMatrix(result, size);
                break;
            case 4:
                int row, col, newValue;
                std::cout << "Enter the row index: "; // Modified prompt message
                std::cin >> row;
                std::cout << "Enter the column index: "; // Modified prompt message
                std::cin >> col;
                std::cout << "Enter the new value: "; // Modified prompt message
                std::cin >> newValue;
                updateElement(firstMatrix, row, col, newValue, size);
                std::cout << "Updated Matrix 1:" << std::endl; // Modified output message
                printMatrix(firstMatrix, size);
                break;
            case 5:
                std::cout << "Max value of Matrix 1: " << getMaxValue(firstMatrix, size) << std::endl; // Modified output message
                break;
            case 6:
                transposeMatrix(firstMatrix, size);
                std::cout << "Transposed Matrix 1:" << std::endl; // Modified output message
                printMatrix(firstMatrix, size);
                break;
            case 0:
                std::cout << "Exiting the program..." << std::endl; // Modified output message
                break; 
            default:
                std::cout << "Invalid choice. Please try again." << std::endl; // Added default case for invalid choices
                break;
        }
    } while (choice != 0);

    return 0;
}
