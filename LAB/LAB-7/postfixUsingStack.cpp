#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evaluatePostfix(string exp)
{
    stack<int> s;
    for (char ch : exp)
    {
        if (isdigit(ch))
        {
            s.push(ch - '0');
        }
        else
        {
            int val1 = s.top();
            s.pop();
            int val2 = s.top();
            s.pop();
            switch (ch)
            {
            case '+':
                s.push(val2 + val1);
                break;
            case '-':
                s.push(val2 - val1);
                break;
            case '*':
                s.push(val2 * val1);
                break;
            case '/':
                s.push(val2 / val1);
                break;
            }
        }
    }
    return s.top();
}

int main()
{
    string exp = "231*+9-";
    cout << "Postfix Expression: " << exp << endl;
    cout << "Evaluated Result: " << evaluatePostfix(exp) << endl;
    return 0;
}
