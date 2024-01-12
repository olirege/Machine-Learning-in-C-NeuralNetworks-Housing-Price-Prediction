#ifndef NN_H
#define NN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// HouseData structure to store data from csv file
typedef struct {
    int price;
    int area;
    int bedrooms;
    int bathrooms;
    int stories;
    int mainroad; // 1 for yes, 0 for no
    int guestroom; // 1 for yes, 0 for no
    int basement; // 1 for yes, 0 for no
    int hotwaterheating; // 1 for yes, 0 for no
    int airconditioning; // 1 for yes, 0 for no
    int parking;
    int prefarea; // 1 for yes, 0 for no
    int furnishingstatus; // 1 for furnished, 2 for semi-furnished, 0 for unfurnished
} HouseData;

// NeuralNetwork structure to store neural network parameters
typedef struct {
    int num_features;
    int num_hidden_layers;
    int *num_neurons_hidden_layers;
    int num_outputs;
    double learning_rate;
    double *weights_input_hidden;
    double *weights_hidden_output;
    double *bias_hidden;
    double *bias_output;
    double num_epochs;
    double num_iterations;
    double *hidden_layer_outputs;
    double *output_layer_outputs;
    double target;
    double *input;

} NeuralNetwork;

// Function pointer type for accessing features
typedef double (*FeatureAccessor)(HouseData*); 
double area_accessor(HouseData* data);
double bedrooms_accessor(HouseData* data);
double bathrooms_accessor(HouseData* data);
double stories_accessor(HouseData* data);
double parking_accessor(HouseData* data);
double price_accessor(HouseData* data);
// Reads data from csv file
int read_data(const char *filename, HouseData **data, int *num_points);

// Activation functions
double sigmoid(double x);
double sigmoid_derivative(double x);
double tanh(double x);
double tanh_derivative(double x);
double relu(double x);
double relu_derivative(double x);

// Initializes neural network
int initialize_neural_network(NeuralNetwork *nn, int num_features, int num_hidden_layers, int num_outputs, double learning_rate, double num_epochs, double num_iterations);

// Train neural network
// Helper functions for forward and backward propagation
void forward_propagation(NeuralNetwork *nn, double *input);
void backward_propagation(NeuralNetwork *nn, double *input, double target);
void update_weights(NeuralNetwork *nn);
int train_neural_network(NeuralNetwork *nn, HouseData *training_set, int num_training_points, HouseData *validation_set, int num_validation_points);
int test_neural_network(NeuralNetwork *nn, HouseData *testing_set, int num_testing_points);
#endif