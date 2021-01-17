#ifndef H_myStack
#define H_myStack

// Header file
#include <iostream>
#include<cassert>
using namespace std;
// definition of the template class myStack
template <class Type>
class myStack
{
// data memebers of the class
private:
int maxStackSize;
int stackTop;
Type *list;

// data methods of the class
public:
void initializeStack();
bool isFullStack() const;
bool isEmptyStack() const;
void push(const Type&);
void pop();
Type top() const;
myStack(int = 20);
~myStack();
};
template <class Type>
void myStack<Type>::initializeStack()
{
stackTop = 0;
}
template <class Type>
bool myStack<Type>::isFullStack() const
{
return (stackTop == maxStackSize);
}
template <class Type>
bool myStack<Type>::isEmptyStack() const
{
return (stackTop == 0);
}

template <class Type>
void myStack<Type>::push(const Type& newItem)
{
if (!isFullStack())
{
  list[stackTop] = newItem;
  stackTop++;
}
else
{
  cout << "\n\tCan not add to a full stack";
}  
}   
template <class Type>
void myStack<Type>::pop()
{
if (!isEmptyStack())
  stackTop--;
else
  cout << "\n\tCan not remove from an empty stack";
}   
template <class Type>
Type myStack<Type>::top() const
{
assert(stackTop != 0);
return list[stackTop - 1];
}  
template <class Type>
myStack<Type>::myStack(int stackSize)
{
if (stackSize <= 0)
{
  cout << "Invalid size";
  stackSize = 10;
}    
else
  maxStackSize = stackSize;
stackTop = 0;
list = new Type[maxStackSize];
}   
template <class Type>
myStack<Type>::~myStack()
{
delete[] list;
}  
#endif