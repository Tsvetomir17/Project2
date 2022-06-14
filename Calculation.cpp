#include "Calculation.h"

int precedence(const char operation)
{
    if(operation == '^')
    {
        return 3;
    }
    else if(operation == '*' || operation == '/')
    {
        return 2;
    }
    else if(operation == '-' || operation == '+')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

double doOperation(double a, double b, char operation)
{
    if(operation == '+') return a + b;
    else if(operation == '-') return a - b;
    else if(operation == '*') return a * b;
    else if(operation == '/') return a / b;
    else if(operation == '^') return pow(a,b);
}

std::string calculation(const std::string str)
{
    std::stack<double> numbers;
    std::stack<char> operations;
    bool wasItOperation = true, changeNumOperation = false;
    char whitespace = ' ';
    char dot = '.';

    for(std::size_t i = 0; i < str.size(); i++)
    {
        if(str[i] == whitespace) continue;

        else if(str[i] >= '0' && str[i] <= '9')
        {
            wasItOperation = false;
            std::string result;

            if(changeNumOperation) result.push_back('-');
            changeNumOperation = false;

            while((i < str.size() && str[i] >= '0' && str[i] <= '9') || (str[i] == dot))
            {
                result.push_back(str[i++]);
            }

            i--;
            numbers.push(std::stod(result));
        }

        else if(str[i] == '(')
        {
            wasItOperation = false;
            operations.push('(');
        }

        else if(str[i] == ')')
        {
            wasItOperation = false;
            while(!operations.empty() && operations.top() != '(')
            {
                double num1, num2;
                char operation;

                num1 = numbers.top();
                numbers.pop();
                num2 = numbers.top();
                numbers.pop();

                operation = operations.top();
                operations.pop();

                numbers.push(doOperation(num2, num1, operation));
            }

            if(!operations.empty()) operations.pop();
        }

        else
        {
            if(wasItOperation)
            {
                if(str[i] != '+' && str[i] != '-')
                {
                    return "ERROR";
                }
                if(str[i] == '-')
                {
                    changeNumOperation = true;
                }
                continue;
            }

            wasItOperation = true;
            while(!operations.empty() && precedence(operations.top()) >= precedence(str[i]))
            {
                double num1, num2;
                char operation;

                num1 = numbers.top();
                numbers.pop();
                num2 = numbers.top();
                numbers.pop();

                operation = operations.top();
                operations.pop();

                numbers.push(doOperation(num2, num1, operation));
            }

            operations.push(str[i]);
        }
    }

    while(!operations.empty())
    {
        double num1, num2;
        char operation;

        num1 = numbers.top();
        numbers.pop();
        num2 = numbers.top();
        numbers.pop();

        operation = operations.top();
        operations.pop();

        numbers.push(doOperation(num2, num1, operation));
    }

    std::string result = std::to_string(numbers.top());
    if(result.compare("inf") == 0) return "ERROR";
    return result;
}