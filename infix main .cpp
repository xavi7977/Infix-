#include<fstream>
#include"myStack.h"
#include "infixToPostfix.h"
using namespace std;
//     function main begins program execution
int main()
{
//declaring class variable
infixToPostfix InfixExp;
string infix;
//file stream object
ifstream infile;
//opening a file
infile.open("infixData.txt", ios::in);
//verifying for file existance
if (!infile)
{
  cout << "Cannot open input file. Program terminates!!!" << endl;
//  system("pause");
  return 1;
}
//reading first line
getline(infile, infix);
while (infile)
{
  //calling methods
  InfixExp.getInfix(infix);
  InfixExp.showInfix();
  InfixExp.showPostfix();
  cout << endl;
  //again reading next line
  getline(infile, infix);
}
//closing file
infile.close();
// system("pause");
return 0;
}  
