/*
EXERCISE 1
Matrix Multiplication
*/

#include <iostream>
using namespace std;

int main() {
    int rows1, cols1, rows2, cols2;

    cout << "Matrix Dimentions" << endl << endl;

    cout << "Matrix 1 rows: ";
    cin >> rows1;
    cout << "Matrix 1 columns: ";
    cin >> cols1;
    cout << endl;

    cout << "Matrix 2 rows: ";
    cin >> rows2;
    cout << "Matrix 2 columns: ";
    cin >> cols2;
    cout << endl;

    if (cols1 != rows2) {
        cout << "Matrix multiplication not possible for given dimensions." << endl;
        cout << "The columns of matrix 1 must be equal to rows to matrix 2." << endl;
        return 0;
    }

    int rows3 = rows1, cols3 = cols2;

    cout << "Result Matrix rows: " << rows3 << endl;
    cout << "Result Matrix columns: " << cols3 << endl << endl;

    int matrix1[rows1][cols1];
    int matrix2[rows2][cols2];
    int matrix3[rows3][cols3] = {};

    cout << "Input Matrix 1 Elements" << endl;
    for (int i = 0; i < rows1; i++)
        for (int j = 0; j < cols1; j++) {
            cout << "Enter element at row " << i+1 << " col " << j+1 << ": ";
            cin >> matrix1[i][j];
        }

    cout << endl << "Input Matrix 2 Elements" << endl;
    for (int i = 0; i < rows2; i++)
        for (int j = 0; j < cols2; j++) {
            cout << "Enter element at row " << i+1 << " col " << j+1 << ": ";
            cin >> matrix2[i][j];
        }

    for (int i = 0; i < rows3; i++)
        for (int j = 0; j < cols3; j++)
            for (int k = 0; k < cols1; k++) {
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
            }

    cout << endl;

    cout << "Matrix 1" << endl;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            cout << matrix1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Matrix 2" << endl;
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Result Matrix" << endl;
    for (int i = 0; i < rows3; i++) {
        for (int j = 0; j < cols3; j++) {
            cout << matrix3[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

}