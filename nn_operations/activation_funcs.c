#include "../include/nn.h"
// Sigmoid function - output is between 0 and 1
double sigmoid(double x)
{
    return 1.0 / (1.0 + exp(-x)); // sigmoid(x) = 1 / (1 + e^-x)
}

double sigmoid_derivative(double x)
{
    // Derivative of sigmoid: sigmoid(x) * (1 - sigmoid(x))
    return x * (1.0 - x);
}
// Hyberbolic tangent function - output is between -1 and 1
double tanh(double x)
{
    return tanh(x);
}

double tanh_derivative(double x)
{
    // Derivative of tanh: 1 - (tanh(x))^2
    return 1.0 - x * x;
}
// ReLU function - output is between 0 and infinity
double relu(double x)
{
    return (x > 0) ? x : 0.0; // relu(x) = x if x > 0, 0 otherwise
}

double relu_derivative(double x)
{
    return (x > 0) ? 1.0 : 0.0; // relu'(x) = 1 if x > 0, 0 otherwise
}
