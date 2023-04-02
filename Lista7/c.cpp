#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//DES -- Diagonal Esqueda Superior
//MC  -- Mesma coluna
//CSD -- Coluna superior Direita

void printBoard(vector<vector<char>> board, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
}

bool isBoardSafe(vector<vector<char>> &board, int row, int column) {
    int n = board.size();
    //DES
    for(int i = row-1, j = column-1; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 'Q') {
            return false;
        }
    }
    //MC
    for(int i = row-1; i >= 0; i--) {
        if(board[i][column] == 'Q') {
            return false;
        }
    }
    //CSD
    for(int i = row-1, j = column+1; i >= 0 && j < n; i--, j++) {
        if(board[i][j] == 'Q') {
            return false;
        }
    }
    return true;
}

bool placeNQueens(vector<vector<char>> &board, int n, int row) {
    if(row == n) {
        printBoard(board, n);
        cout << endl;
        return true;
    }
    bool ans = false;
    for(int j = 0; j < n; j++) {
        if(isBoardSafe(board, row, j)) {
            board[row][j] = 'Q';
            if(placeNQueens(board, n, row+1)) {
                ans = true;
            }
            board[row][j] = '-';
        }
    }
    return ans;
}

void pQueens(int n) {
    vector<vector<char>> board(n, vector<char>(n, '-'));
    bool ans = placeNQueens(board, n, 0);
    if(!ans) {
        cout << "Not Possible";
    }
}

int main() {
    int n;
    cin >> n;
    pQueens(n);
	return 0;
}