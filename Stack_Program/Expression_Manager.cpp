#include "Expression_Manager.h"

// Uses getline to get the expression from the user
string getExpression() {
    string expression;
    cout << "Type in the expression you want to check\n";
    getline(cin, expression);
    return expression;
}

// Tests if the expression is valid and returns a bool
bool isValidExpression(const string& expression, Stack& braceStack) {
    // Iterating through the characters of the expression
    for (size_t i = 0; i < expression.size(); i++) {
        // If it is a left parenthesis it gets added to the stack
        if (expression[i] == '{' || expression[i] == '(' || expression[i] == '[') {
            braceStack.push(expression[i]);
        }
        // If it's a right parenthesis we check the stack to see if it matches the left parenthesis in the stack
        else if (expression[i] == '}') {
            // If the stack is empty or peek doesn't match the right parenthesis then the function returns false (invalid)
            if (braceStack.empty() || braceStack.peek() != '{') {
                return false;
            }
            // pops the left parenthesis off the stack if it does match
            braceStack.pop();
        }
        // Next two else ifs are the same as the else if above but with different parenthesis types
        else if (expression[i] == ')') {
            if (braceStack.empty() || braceStack.peek() != '(') {
                return false;
            }
            braceStack.pop();
        }
        else if (expression[i] == ']') {
            if (braceStack.empty() || braceStack.peek() != '[') {
                return false;
            }
            braceStack.pop();
        }
    }

    // Check if the stack is empty after processing all characters (if it's not empty returns false so invalid)
    return braceStack.empty();
}

// These functions are for use within the infix to postfix function, which I used the shunting-yard algorithm to do
// Function to check if a character is an operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%';
}

// Function to check if a character is a left parenthesis
bool isLeftParenthesis(char ch) {
    return ch == '(' || ch == '[' || ch == '{';
}

// Function to check if a character is a right parenthesis
bool isRightParenthesis(char ch) {
    return ch == ')' || ch == ']' || ch == '}';
}

// Function to get the precedence of an operator
// The multiplication and division have greater precedence than addition and subtraction
int getPrecedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/' || ch == '%')
        return 2;
    return 0;
}

// Function to convert infix expression to postfix expression
// This function uses the previous functions to get the postfix expression
// This function was made using the shunting-yard algorithm

// Function takes in the infix expression and a stack
string infixToPostfix(const string& infix, Stack& operatorStack) {
    string postfix;
    // Using a map so we can give the operators their precedence value
    unordered_map<char, int> precedence;

    // Iterate through the characters of the expression
    size_t i = 0;
    while (i < infix.size()) {
        // Skip spaces
        if (infix[i] == ' ') {
            i++;
            continue;
        }
        /*
        If it's an operator and the stack isn't empty, isn't a left parenthesis, and the operator in the stack
         - has higher precedence than the operator at i, add the operator from the stack to the postfix expression
         - and push the operator that is at i onto the stack.
        */
        else if (isOperator(infix[i])) {
            while (!operatorStack.empty() && !isLeftParenthesis(operatorStack.peek()) &&
                   getPrecedence(operatorStack.peek()) >= getPrecedence(infix[i])) {
                postfix += operatorStack.pop();
                postfix += ' ';
            }
            operatorStack.push(infix[i]);
        }
        // If the char at i is a left parenthesis we can just push it onto the operator stack
        else if (isLeftParenthesis(infix[i])) {
            operatorStack.push(infix[i]);
        }
        /*
        If the char is a right parenthesis then we pop operators off of the stack until we encounter the left parenthesis 
        and the operators that are popped off are added to the postfix expression
        */
        else if (isRightParenthesis(infix[i])) {
            while (!operatorStack.empty() && !isLeftParenthesis(operatorStack.peek())) {
                postfix += operatorStack.pop();
                postfix += ' ';
            }
            // When we find the left parenthesis that's when we stop adding to the postfix expression
            if (!operatorStack.empty() && isLeftParenthesis(operatorStack.peek())) {
                operatorStack.pop(); // Pop the corresponding left parenthesis
            }
        }
        // In the else case the char at i is not a left or right parenthesis, an operator, or whitespace, so it must
        // be an operand (given that this function is only called when the expression was deemed valid)
        else {
            // Extract the entire operand (number or identifier)
            // We get the indexes of the start and end of the operand in case it is more than one digit long by
            // iterating until the char at i isn't a number anymore
            size_t operandStart = i;
            while (i < infix.size() && !isOperator(infix[i]) && !isLeftParenthesis(infix[i]) &&
                !isRightParenthesis(infix[i]) && infix[i] != ' ') {
                i++;
            }
            size_t operandEnd = i;

            // Append the extracted operand to the postfix expression
            // Uses a substring to put the operand that may have more than one digit, into the postfix expression
            postfix += infix.substr(operandStart, operandEnd - operandStart);
            // cout << infix.substr(operandStart, operandEnd - operandStart) << endl;
            postfix += ' '; // Add a space after an operand

            continue; // Skip incrementing i since the operand has already been processed
        }
        i++;
    }
    // If the stack isn't empty, remove any remaining parentheses from the stack by popping them 
    // Any remaining operators get popped and also added to the postfix expression (followed by a space)
    while (!operatorStack.empty()) {
        if (isLeftParenthesis(operatorStack.peek()) || isRightParenthesis(operatorStack.peek())) {
            operatorStack.pop();
        }
        else {
            postfix += operatorStack.pop();
            postfix += ' '; // adds a space after appending an operator
        }
    }

    return postfix;
}