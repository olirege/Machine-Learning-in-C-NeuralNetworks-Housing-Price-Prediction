#include "../include/nn.h"
int test_neural_network(NeuralNetwork *nn, HouseData *testing_set, int num_testing_points) {
    double total_loss = 0.0;
    double input[nn->num_features];
    for (int i = 0; i < num_testing_points; i++) {
        input[0] = (double)testing_set[i].area;
        input[1] = (double)testing_set[i].bedrooms;
        input[2] = (double)testing_set[i].bathrooms;
        input[3] = (double)testing_set[i].stories;
        input[4] = (double)testing_set[i].mainroad;
        input[5] = (double)testing_set[i].guestroom;
        input[6] = (double)testing_set[i].basement;
        input[7] = (double)testing_set[i].hotwaterheating;
        input[8] = (double)testing_set[i].airconditioning;
        input[9] = (double)testing_set[i].parking;
        input[10] = (double)testing_set[i].prefarea;
        input[11] = (double)testing_set[i].furnishingstatus;
        
        forward_propagation(nn, input);

        double target = testing_set[i].price;
        double predicted = nn->output_layer_outputs[0];
        double loss = (target - predicted) * (target - predicted);
        total_loss += loss;
    }
    double mean_loss = total_loss / num_testing_points;
    _log(__func__, "Mean loss: %lf", mean_loss);
    return 0;
}