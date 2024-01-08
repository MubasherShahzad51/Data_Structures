#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

int evaluatePostfix(string exp)
{
  stack<int> st;
  for (int i = 0; i < exp.length(); i++)
  {
    // this case is for if character is operand
    if (exp[i] >= '0' && exp[i] <= '9') // if its in between 0 and 9 then it is operand
    {
      st.push(exp[i] - '0'); // it will return as an integer if we remove 0 asci value from character
    }
    // this case is for if character is an operator
    else
    {
      int op2 = st.top();
      st.pop();
      int op1 = st.top();
      st.pop();
      switch (exp[i])
      {
      case '+':
        st.push(op1 + op2);
        break;
      case '-':
        st.push(op1 - op2);
        break;
      case '*':
        st.push(op1 * op2);
        break;
      case '/':
        st.push(op1 / op2);
        break;
      case '^':
        st.push(pow(op1,op2));
        break;
      }
    }
  }
  return st.top(); // final avaluated value
}

int main()
{
  // string exp = "231*+9-";
  cout << evaluatePostfix("231*+9-")<<endl;
  cout << evaluatePostfix("46+2/5*7+")<<endl;
  return 0;
}