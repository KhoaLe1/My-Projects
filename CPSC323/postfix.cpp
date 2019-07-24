#include <stack>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

double eval(double first, double second, char operators)
{
    switch (operators)
    {
    case '+': return first + second;
    case '-': return first - second;
    case '*': return first * second;
    case '/': return first / second;
    }
    return 0;
}

double evalPostfix(string input)
{
    stack<double> values;
    stringstream ss{input};

    while(true) {
        while (true) {
            auto pos{ ss.tellg() };
            double value;
            if (!(ss >> value)) {
                ss.clear();
                ss.seekg(pos);
                break;
            }
            values.push(value);
        }

        char op;
        if (!(ss >> skipws >> op)) break;


        double op2 = values.top();
        values.pop();
        double op1 = values.top();
        values.pop();
        values.push(eval(op1, op2, op));
    }
    return values.top();
}

void print(string inp)
{
  int i=inp.length()-1;
  char pn = inp[i];
  if(pn == '$')
  {
    size_t pos = inp.find("$");
    if( pos != string::npos)
    {
      inp.erase(pos);
    }
    double result= evalPostfix(inp);
    cout << "Final answer = " << result << pn << endl;
  }
  else
  {
    double result= evalPostfix(inp);
    cout << "Final answer = " << result << endl;
  }
}

int main()
{
    cout << "Enter the postfix expression: ";
    string input;
    getline(cin, input);
    print(input);
}
