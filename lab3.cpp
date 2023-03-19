#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;

int row;
int col;

class Operators {
    public:

        int Addition(int num1, int num2) {
            
            int output = 0;
            output = num1 + num2;
            return output;
        }

        int Subtraction(int num1, int num2) {
            int output = 0;
            output = num1 - num2;
            return output;
        }

        int Multiplication(int num1, int num2) {
            int output = 0;
            output = num1 * num2;
            return output;
        }

        int Increment(int num1) {
            int output = 0;
            output = ++num1;
            return output;
        }

        int Decrement(int num1) {
            int output = 0;
            output = --num1;
            return output;
        }

        int Exponetioal(int num1, int num2) {
            int output = 0;
            if(num2 < 0) {
                cout << "Error, negative exponent\n";
                exit(EXIT_FAILURE);
            } else {
                output = pow(num1, num2);
            }
            return output;
        }
};

int main() {
    int dimension;
    // int row;
    // int col;
    int choice;

    Operators op;

    cout << "Enter matrix dimension: \n";
    cin >> dimension;

    row = dimension;
    col = dimension;

    int matrix[row][col];
    int matrix2[row][col];
    int out[row][col];
    int transposeOut[row][col];

    cout << "Enter Operator\n";
    cout << "1: Addition\n2: Subtraction\n3: Multiplacation\n4: Increment\n5: Decrement\n6: Transpose\n7: Positive Exponential\n";
    cin >> choice;

    if (choice == 4 || choice == 5 || choice == 6) {
        cout << "Enter values of first matrix\n";
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> matrix[i][j];
            }
        }
    } else {
        cout << "Enter values of first matrix\n";
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> matrix[i][j];
            }
        }

        cout << "Enter values of second matrix\n";
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> matrix2[i][j];
            }
        }
    }


    if (choice == 1) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                out[i][j] = op.Addition(matrix[i][j], matrix2[i][j]);
            }
        }
    } else if (choice == 2) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                out[i][j] = op.Subtraction(matrix[i][j], matrix2[i][j]);
            }
        }
    } else if (choice == 3) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                out[i][j] = op.Multiplication(matrix[i][j], matrix2[i][j]);
            }
        }
    } else if (choice == 4) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                out[i][j] = op.Increment(matrix[i][j]);
            }
        }
    } else if (choice == 5) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                out[i][j] = op.Decrement(matrix[i][j]);
            }
        }
    } else if (choice == 6) {
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                transposeOut[j][i] = matrix[i][j];
            }
        }
    } else if (choice == 7) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                out[i][j] = op.Exponetioal(matrix[i][j], matrix2[i][j]);
            }
        }
    } else {
        cout << "Error, invalid Operator\n";
        exit(EXIT_SUCCESS);
    }

    cout << "\n";

    if(choice == 6) {
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                cout << transposeOut[i][j];
        }
        cout << "\n";
    } 
    } else {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cout << out[i][j] << " ";
            }
            cout << "\n";
        }     
    }
    return 0;
}