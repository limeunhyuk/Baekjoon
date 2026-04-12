#include <iostream>
#include <string>
#include <stack>
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
        if ('A' <= c && c <= 'Z') cout << c;
        else if (c == ')') {
            while (st.top() != '(') {
                cout << st.top();
                st.pop();
            }
            st.pop();
        }
        else {                
            while (!st.empty()) {
                char t = st.top();
                if (c == '(' || prior(t) < prior(c)) break;
                cout << t;
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