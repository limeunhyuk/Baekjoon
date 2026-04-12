#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <algorithm>
using namespace std;

int prior(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    else return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    stack<char> st;
    for (char c : s) {
        if (isupper(c)) cout << c;
        else if (c == ')') {
            while (st.top() != '(') {
                cout << st.top();
                st.pop();
            }
            st.pop();
        }
        else {                
            while (!st.empty() && c!= '(' && prior(st.top()) >= prior(c)) {
                cout << st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }

    return 0;
}