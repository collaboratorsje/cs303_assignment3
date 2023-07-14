#include "Expression_Manager.h"
#include "stack.h"

int main() {
    // Declare the brace and operator stacks for use in the functions
    Stack braceStack, operatorStack;
    // Get the expression from the user
    string expression = getExpression();
    
    cout << "Testing the validity of the expression entered..." << endl;
    cout << (isValidExpression(expression, braceStack) ? "Valid Expression" : "Invalid Expression") << endl;

    if (isValidExpression(expression, braceStack)) {
        cout << "Outputting postfix expression..." << endl;
        cout << infixToPostfix(expression, operatorStack);
    }
}