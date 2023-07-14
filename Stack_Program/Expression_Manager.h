#pragma once
#include "stack.h"
#include <unordered_map>
#include <iostream>

using namespace std;

// Gets the expression from the user with getline
string getExpression();

// Tests the expression for validity and returns a bool
bool isValidExpression(const string& expression, Stack& braceStack);

// Function to check if a character is an operator
bool isOperator(char ch);

// Function to check if a character is a left parenthesis
bool isLeftParenthesis(char ch);

// Function to check if a character is a right parenthesis
bool isRightParenthesis(char ch);

// Function to get the precedence of an operator
int getPrecedence(char ch);

// Function to convert infix expression to postfix expression and returns the postfix expression
string infixToPostfix(const string& infix, Stack& operatorStack);