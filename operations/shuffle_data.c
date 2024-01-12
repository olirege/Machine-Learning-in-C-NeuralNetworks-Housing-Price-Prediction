#include "../include/operations.h"

// Function to split data into training and testing sets
int shuffle_data(HouseData *data, int num_points) {
    for (int i = 0; i < num_points - 1; i++) { // Fisher-Yates shuffle
        int j = i + rand() / (RAND_MAX / (num_points - i) + 1); // Random int such that i <= j < num_points
        HouseData temp = data[j];
        data[j] = data[i];
        data[i] = temp;
    }
    return 0;
}