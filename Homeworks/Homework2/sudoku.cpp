#include <iostream>
using namespace std;

const int n = 9;

bool checksudoku(int[n][n]);
bool checkbounds(int[n][n]);
bool checkrow(int[n][n], int);
bool checkcol(int[n][n], int);
bool check3x3(int[n][n], int, int);

int main() {
    int correct1[n][n] =  { {1, 9, 4, 8, 7, 5, 6, 2, 3},
                            {8, 5, 3, 9, 6, 2, 4, 7, 1},
                            {2, 6, 7, 3, 1, 4, 9, 8, 5},
                            {9, 2, 1, 6, 5, 8, 7, 3, 4},
                            {6, 7, 8, 4, 3, 1, 2, 5, 9},
                            {4, 3, 5, 2, 9, 7, 8, 1, 6},
                            {5, 8, 6, 7, 4, 3, 1, 9, 2},
                            {3, 4, 2, 1, 8, 9, 5, 6, 7},
                            {7, 1, 9, 5, 2, 6, 3, 4, 8} };

    int correct2[n][n] =  { {5, 3, 4, 6, 7, 8, 9, 1, 2},
                            {6, 7, 2, 1, 9, 5, 3, 4, 8},
                            {1, 9, 8, 3, 4, 2, 5, 6, 7},
                            {8, 5, 9, 7, 6, 1, 4, 2, 3},
                            {4, 2, 6, 8, 5, 3, 7, 9, 1},
                            {7, 1, 3, 9, 2, 4, 8, 5, 6},
                            {9, 6, 1, 5, 3, 7, 2, 8, 4},
                            {2, 8, 7, 4, 1, 9, 6, 3, 5},
                            {3, 4, 5, 2, 8, 6, 1, 7, 9} };

    int incorrect[n][n] = { {5, 3, 4, 6, 7, 8, 9, 1, 2},
                            {6, 7, 2, 1, 9, 5, 3, 4, 8},
                            {1, 9, 9, 3, 4, 2, 5, 6, 7},
                            {8, 5, 9, 7, 6, 1, 4, 2, 3},
                            {4, 2, 6, 8, 5, 3, 7, 9, 1},
                            {7, 1, 3, 9, 2, 4, 8, 5, 6},
                            {9, 6, 1, 5, 3, 7, 2, 8, 4},
                            {2, 8, 7, 4, 1, 9, 6, 3, 5},
                            {3, 4, 5, 2, 8, 6, 1, 7, 9} };
    
    cout << boolalpha << checksudoku(incorrect) << endl;
}

bool checksudoku(int matrix[n][n]) {
    if (!checkbounds(matrix))
        return false;

    for (int i = 0; i < n; i++) {
        if (!checkrow(matrix, i))
            return false;
        if (!checkcol(matrix, i))
            return false;
    }

    for (int i = 0; i < n; i += 3)
        for (int j = 0; j < n; j += 3)
            if (!check3x3(matrix, i, j))
                return false;

    return true;
}

bool checkbounds(int matrix[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][j] < 1 || matrix[i][j] > 9)
                return false;
    return true;
}

bool checkrow(int matrix[n][n], int rownum) {
    int counts[n] = {};

    for (int i = 0; i < n; i++) {
        int value = matrix[rownum][i];

        if (counts[value-1] > 0) {
            cout << "Incorrect Row: (" << rownum << ", " << i << ")" << endl;
            return false;
        }
        counts[value-1]++;
    }

    return true;
}

bool checkcol(int matrix[n][n], int colnum) {
    int counts[n] = {};

    for (int i = 0; i < n; i++) {
        int value = matrix[i][colnum];

        if (counts[value-1] > 0) {
            cout << "Incorrect Column: (" << i << ", " << colnum << ")" << endl;
            return false;
        }
        counts[value-1]++;
    }

    return true;
}

bool check3x3(int matrix[n][n], int rownum, int colnum) {
    if (rownum+3 > n || colnum+3 > n) {
        cout << "Incorrect 3x3: out of bound";
        return false;
    }

    int counts[n] = {};
    for (int i = rownum; i < rownum+3; i++) {
        for (int j = colnum; j < colnum+3; j++) {
            int value = matrix[i][j];

            if (counts[value-1] > 0) {
                cout << "Incorrect 3x3: (" << i << ", " << j << ")" << endl;
                return false;
            }
            counts[value-1]++;
        }
    }

    return true;
}