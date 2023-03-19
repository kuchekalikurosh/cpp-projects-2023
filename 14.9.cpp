#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int Evaluate(vector<string>& A)
{
    stack<int> S;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] != "+" && A[i] != "-" && A[i] != "/"
            && A[i] != "*") {
            S.push(stoi(A[i]));
            continue;
        }
        else {
            int b = S.top();
            S.pop();
            int a = S.top();
            S.pop();
            if (A[i] == "+")
                S.push(a + b);
            else if (A[i] == "-")
                S.push(a - b);
            else if (A[i] == "*")
                S.push(a * b);
            else
                S.push(a / b);
        }
    }
    return S.top();
}
 
int main()
{
    vector<string> A = {"3", "10", "5", "+", "*"};
 
    int res = Evaluate(A);

    cout << "Reverse Polish Notation: (";
    for(int i = 0; i < A.size(); i++) {
        cout << A[i] << ", ";
    }
    cout << ")";
    
    cout << "\n" << res << endl;
}