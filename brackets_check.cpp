#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool braces_check(const string& str)
{
    stack<char> stack;

    for (int i = 0; i < (int)str.length(); ++i) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            stack.push(str[i]);
        } 
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {

            if(stack.empty() 
                    || ((str[i] == ')') ^ (stack.top() == '('))
                    || ((str[i] == '}') ^ (stack.top() == '{'))
                    || ((str[i] == ']') ^ (stack.top() == '['))) {
                return false;
            }

            stack.pop();
        }
    }
    return stack.empty();
}

int solution() {

    string str;
    cout << "Enter the string with brakets: ";
    cin >> str;
    cout << (braces_check(str) ? "Right" : "Wrong") << endl;

    return 0;
}

int getAnswer() {
    int answer;
    cout << "Do you want continue? 1 = yes, any other input = no " << endl << "Your answer: ";
    cin >> answer;
    return answer;
}

int main()
{
    solution();
    int ans = getAnswer();
        while (true) {
            switch (ans) {
            case 1:
                solution();
                if (getAnswer() == 1) {
                    continue;
                }
                else {
                    break;
                }

            default:
                break;
            }
            return 0;
        }
}