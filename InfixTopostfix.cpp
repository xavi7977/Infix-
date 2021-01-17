#include<string>
using namespace std;

// Create a class named infixToPostfix
class infixToPostfix
{
// Declare the variables
string infix;
string postfix;
public:

// Declare the methods.
void showPostfix();
bool isOperator(const char c);
int precedence(const char op1, const char op2);
void getInfix(string infixString)
{
  infix = infixString.substr(0, infixString.length() - 1);
  //cout << infix;
}
void showInfix()
{
  cout << "\nThe infix expression is : " << infix;
}
};

// The method definitations are as follows:
//a utility function to find a given character is an operator or not
bool infixToPostfix::isOperator(const char c)
{
//     check for the various operators
if ((c == '+') || (c == '-') || (c == '*') ||
  (c == '/') || (c == '^') || (c == '%'))
{
  return true;
}
  
else
{
  return false;
}  
}   

int infixToPostfix::precedence(const char op1, const char op2)
{
//     please note that only 5 operators were only
//     considered for precedence.
//     Not considered ^ for comparing the precedence
int pre1, pre2;//declare variables to compare the precedence
if ((op1 == '^') || (op2 == '^'))
{
  cout << "Exponentiation was not considered"
   << "for precedence. \n\tThe program may"
   << "result in abnormal output of Postfix exp.";
}  
if ((op1 == '+') || (op1 == '-'))
{
  //low precedence
  pre1 = 0;
}
else
{
  if ((op1 == '*') || (op1 == '/') || (op1 == '%'))
   pre1 = 1;                  //     high precedence
}
  
if ((op2 == '+') || (op2 == '-')) //low precedence
{
  pre2 = 0;
}
  
else
{
  if ((op2 == '*') || (op2 == '/') || (op2 == '%'))
  {
   pre2 = 1;
  }   
}
  
if (pre1 == pre2)
{
  //     equal precedence of op1 & op2
  return 0;
}
else
{
  if (pre1 > pre2)   //higher precedence of op1 over op2
  {
   return 1;
  }
  else
  {
   //     lower precedence of op1 over op2
   return -1;
  }
}
  
}

// Conversion of infix arithmetic exp into postfix exp
void infixToPostfix::showPostfix()
{
myStack< char > myStack;
string pfx = "";

//append a right parenthesis ')' to the end of infix
infix.append(")");

// push the left parenthesis onto the stack
myStack.push('(');
unsigned int i = 0;

do
{
  // when the current element in infix is an operator
  if (isOperator(infix[i]))
  {
   // when the top of the stack is an operator
   if (isOperator(myStack.top()))
   {    
    if (precedence(infix[i], myStack.top()) == 0)
    {     
     pfx = pfx + myStack.top();
     myStack.pop();
    }  
    else
     if (precedence(infix[i],
      myStack.top()) == 1)
     {
      myStack.push(infix[i]);
      i++;
     }
     else
     {     
      pfx = pfx + myStack.top();
      myStack.pop();
     }
   }
   else
   {
    myStack.push(infix[i]);
    i++;
   }
  }
  else
  {
   if (infix[i] == ')')
   {    
    while (myStack.top() != '(')
    {
     pfx = pfx + myStack.top();
     myStack.pop();
    }
    myStack.pop();
    i++;
   }
   else
    if (infix[i] == '(')
    {     
     myStack.push(infix[i]);
     i++;
    }   
    else
    {     
     pfx = pfx + infix[i];
     i++;
    }
  }
} while (i < infix.length());  

cout << "\nThe postfix expression is : " << pfx;
}  