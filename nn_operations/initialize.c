#include "../include/nn.h"
#include "../include/utils.h"

int initialize_neural_network(NeuralNetwork *nn, int num_features, int num_hidden_layers, int num_outputs, double learning_rate, double num_epochs, double num_iterations) {
    // Initialize neural network parameters
    nn->num_features = num_features;
    nn->num_hidden_layers = num_hidden_layers;
    nn->num_outputs = num_outputs;
    nn->learning_rate = learning_rate;
    nn->num_epochs = num_epochs;
    nn->num_iterations = num_iterations;
    // Initialize weights and biases
    nn->weights_input_hidden = (double *)malloc(num_features * num_hidden_layers * sizeof(double));
    nn->weights_hidden_output = (double *)malloc(num_hidden_layers * num_outputs * sizeof(double));
    nn->bias_hidden = (double *)malloc(num_hidden_layers * sizeof(double));
    nn->bias_output = (double *)malloc(num_outputs * sizeof(double));
    if (!(nn->weights_input_hidden) || !(nn->weights_hidden_output) || !(nn->bias_hidden) || !(nn->bias_output)) {
        perror("Error allocating memory for weights and biases\n");
        free(nn->weights_input_hidden);
        free(nn->weights_hidden_output);
        free(nn->bias_hidden);
        free(nn->bias_output);
        return 1;
    }
    // Initialize weights and biases to random values
    for (int i = 0; i < num_features * num_hidden_layers; i++) {
        nn->weights_input_hidden[i] = (double)rand() / (double)RAND_MAX;
    }
    for (int i = 0; i < num_hidden_layers * num_outputs; i++) {
        nn->weights_hidden_output[i] = (double)rand() / (double)RAND_MAX;
    }
    for (int i = 0; i < num_hidden_layers; i++) {
        nn->bias_hidden[i] = (double)rand() / (double)RAND_MAX;
    }
    for (int i = 0; i < num_outputs; i++) {
        nn->bias_output[i] = (double)rand() / (double)RAND_MAX;
    }
    // Initialize hidden layer outputs and output layer outputs
    nn->hidden_layer_outputs = (double *)malloc(num_hidden_layers * sizeof(double));
    nn->output_layer_outputs = (double *)malloc(num_outputs * sizeof(double));
    // Initialize target
    nn->target = 0.0;
    // Initialize input
    nn->input = (double *)malloc(num_features * sizeof(double));
    // Check for errors
    if (!(nn->hidden_layer_outputs) || !(nn->output_layer_outputs) || !(nn->input)) {
        perror("Error allocating memory for hidden layer outputs, output layer outputs, and input\n");
        free(nn->weights_input_hidden);
        free(nn->weights_hidden_output);
        free(nn->bias_hidden);
        free(nn->bias_output);
        free(nn->hidden_layer_outputs);
        free(nn->output_layer_outputs);
        free(nn->input);
        return 1;
    }
    _log(__func__, "Number of features: %d", nn->num_features);
    _log(__func__, "Number of hidden layers: %d", nn->num_hidden_layers);
    _log(__func__, "Number of outputs: %d", nn->num_outputs);
    _log(__func__, "Learning rate: %lf", nn->learning_rate);
    _log(__func__, "Number of epochs: %lf", nn->num_epochs);
    _log(__func__, "Number of iterations: %lf", nn->num_iterations);
    _log(__func__, "Neural network initialized successfully");
    return 0;
}
