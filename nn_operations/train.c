#include "../include/nn.h"
#include "../include/utils.h"
int train_neural_network(NeuralNetwork *nn, HouseData *training_set, int num_training_points, HouseData *validation_set, int num_validation_points) {
    for (int i = 0; i < nn->num_epochs; i++) {
        double total_loss = 0.0;
        for (int j = 0; j < nn->num_iterations; j++) {
            double input[nn->num_features];
            for (int k = 0; k < num_training_points; k++) {
                // Input to neural network
                input[0] = (double)training_set[k].area;
                input[1] = (double)training_set[k].bedrooms;
                input[2] = (double)training_set[k].bathrooms;
                input[3] = (double)training_set[k].stories;
                input[4] = (double)training_set[k].mainroad;
                input[5] = (double)training_set[k].guestroom;
                input[6] = (double)training_set[k].basement;
                input[7] = (double)training_set[k].hotwaterheating;
                input[8] = (double)training_set[k].airconditioning;
                input[9] = (double)training_set[k].parking;
                input[10] = (double)training_set[k].prefarea;
                input[11] = (double)training_set[k].furnishingstatus;
                
                // Forward propagation
                forward_propagation(nn, input);
                // Calculate loss
                double target = training_set[k].price;
                double predicted = nn->output_layer_outputs[0];
                double loss = (target - predicted) * (target - predicted);
                total_loss += loss;
                // Backward propagation
                backward_propagation(nn, input, target);
                // Update weights and biases
                update_weights(nn);
            }
        }
        // Calculate validation loss
        double validation_loss = 0.0;
        double input[nn->num_features];
        for (int j = 0; j < num_validation_points; j++) {
            input[0] = (double)validation_set[j].area;
            input[1] = (double)validation_set[j].bedrooms;
            input[2] = (double)validation_set[j].bathrooms;
            input[3] = (double)validation_set[j].stories;
            input[4] = (double)validation_set[j].mainroad;
            input[5] = (double)validation_set[j].guestroom;
            input[6] = (double)validation_set[j].basement;
            input[7] = (double)validation_set[j].hotwaterheating;
            input[8] = (double)validation_set[j].airconditioning;
            input[9] = (double)validation_set[j].parking;
            input[10] = (double)validation_set[j].prefarea;
            input[11] = (double)validation_set[j].furnishingstatus;
            
            forward_propagation(nn, input);

            double target = validation_set[j].price;
            double predicted = nn->output_layer_outputs[0];
            double loss = (target - predicted) * (target - predicted);
            validation_loss += loss;
        }
        // Print epoch and loss
        _log(__func__,"Epoch %d: loss = %lf, validation loss = %lf", i + 1, total_loss / (nn->num_iterations * num_training_points), validation_loss / num_validation_points);
    }
    return 0;
}
