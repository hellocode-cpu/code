#include <iostream>
#include <vector>
#include <string>
#include <functional>

class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> sol;
        std::vector<std::vector<int>> board(n, std::vector<int>(n, 0));

        // Function to check if placing a queen at (i, j) is safe
        auto isSafe = [&](int i, int j) {
            for (int row = 0; row < i; ++row) {
                if (board[row][j] == 1) return false;
            }

            int row = i, col = j;

            // Check left diagonal
            while (row >= 0 && col >= 0) {
                if (board[row][col] == 1) return false;
                --row;
                --col;
            }

            row = i;
            col = j;

            // Check right diagonal
            while (row >= 0 && col < n) {
                if (board[row][col] == 1) return false;
                --row;
                ++col;
            }

            return true;
        };

        // Recursive function to solve the N-Queens problem
        std::function<void(int)> nqueen = [&](int row) {
            if (row == n) {
                std::vector<std::string> solution;
                for (int i = 0; i < n; ++i) {
                    std::string row_str;
                    for (int j = 0; j < n; ++j) {
                        row_str += (board[i][j] == 1 ? "Q" : ".");
                    }
                    solution.push_back(row_str);
                }
                sol.push_back(solution);
                return;
            }
            for (int col = 0; col < n; ++col) {
                if (isSafe(row, col)) {
                    board[row][col] = 1;
                    nqueen(row + 1);
                    board[row][col] = 0;  // Backtrack
                }
            }
        };

        nqueen(0);
        return sol;
    }
};

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    Solution solution;
    std::vector<std::vector<std::string>> result = solution.solveNQueens(n);

    std::cout << "The solutions are:\n";
    for (const auto& sol : result) {
        for (const auto& row : sol) {
            std::cout << row << "\n";
        }
        std::cout << "\n";
    }

    return 0;
}
