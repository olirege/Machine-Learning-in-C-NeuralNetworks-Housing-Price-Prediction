#include "../include/nn.h"
void update_weights(NeuralNetwork *nn) {
    // Calculate output layer errors
    double *output_layer_errors = (double *)malloc(nn->num_outputs * sizeof(double));
    for (int i = 0; i < nn->num_outputs; i++) {
        output_layer_errors[i] = (nn->target - nn->output_layer_outputs[i]) * sigmoid_derivative(nn->output_layer_outputs[i]);
    }
    // Calculate hidden layer errors
    double *hidden_layer_errors = (double *)malloc(nn->num_hidden_layers * sizeof(double));
    for (int i = 0; i < nn->num_hidden_layers; i++) {
        hidden_layer_errors[i] = 0.0;
        for (int j = 0; j < nn->num_outputs; j++) {
            hidden_layer_errors[i] += nn->weights_hidden_output[i * nn->num_outputs + j] * output_layer_errors[j];
        }
        hidden_layer_errors[i] *= sigmoid_derivative(nn->hidden_layer_outputs[i]);
    }
    // Update weights and biases
    for (int i = 0; i < nn->num_hidden_layers; i++) {
        for (int j = 0; j < nn->num_outputs; j++) {
            nn->weights_hidden_output[i * nn->num_outputs + j] += nn->learning_rate * output_layer_errors[j] * nn->hidden_layer_outputs[i];
        }
    }
    for (int i = 0; i < nn->num_outputs; i++) {
        nn->bias_output[i] += nn->learning_rate * output_layer_errors[i];
    }
    for (int i = 0; i < nn->num_features; i++) {
        for (int j = 0; j < nn->num_hidden_layers; j++) {
            nn->weights_input_hidden[i * nn->num_hidden_layers + j] += nn->learning_rate * hidden_layer_errors[j] * nn->input[i];
        }
    }
    for (int i = 0; i < nn->num_hidden_layers; i++) {
        nn->bias_hidden[i] += nn->learning_rate * hidden_layer_errors[i];
    }
    // Free memory
    free(output_layer_errors);
    free(hidden_layer_errors);
}
