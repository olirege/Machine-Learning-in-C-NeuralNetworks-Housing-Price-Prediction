#include "../include/nn.h"

// Helper functions for forward and backward propagation
void forward_propagation(NeuralNetwork *nn, double *input) {
    // Calculate hidden layer outputs
    double *hidden_layer_outputs = (double *)malloc(nn->num_hidden_layers * sizeof(double));
    for (int i = 0; i < nn->num_hidden_layers; i++) {
        hidden_layer_outputs[i] = 0.0;
        for (int j = 0; j < nn->num_features; j++) {
            hidden_layer_outputs[i] += nn->weights_input_hidden[j * nn->num_hidden_layers + i] * input[j];
        }
        hidden_layer_outputs[i] += nn->bias_hidden[i];
        hidden_layer_outputs[i] = relu(hidden_layer_outputs[i]);
    }
    // Calculate output layer outputs
    double *output_layer_outputs = (double *)malloc(nn->num_outputs * sizeof(double));
    for (int i = 0; i < nn->num_outputs; i++) {
        output_layer_outputs[i] = 0.0;
        for (int j = 0; j < nn->num_hidden_layers; j++) {
            output_layer_outputs[i] += nn->weights_hidden_output[j * nn->num_outputs + i] * hidden_layer_outputs[j];
        }
        output_layer_outputs[i] += nn->bias_output[i];
        output_layer_outputs[i] = relu(output_layer_outputs[i]);
    }
    // Store outputs in neural network
    nn->hidden_layer_outputs = hidden_layer_outputs;
    nn->output_layer_outputs = output_layer_outputs;
}
