#include "../include/operations.h"

int split_data(HouseData *data, int num_points, HouseData **training_set, int *num_training_points, HouseData **testing_set, int *num_testing_points, HouseData **validation_set, int *num_validation_points, SplitRates num_points_split) {
    // Split data into training, testing, and validation sets
    *num_training_points = num_points * num_points_split.training;
    *num_testing_points = num_points * num_points_split.testing;
    *num_validation_points = num_points * num_points_split.validation;
    *training_set = (HouseData *)malloc(*num_training_points * sizeof(HouseData));
    *testing_set = (HouseData *)malloc(*num_testing_points * sizeof(HouseData));
    *validation_set = (HouseData *)malloc(*num_validation_points * sizeof(HouseData));
    if (!(*training_set) || !(*testing_set) || !(*validation_set)) {
        perror("Error allocating memory for training, testing, and validation sets\n");
        return 1;
    }
    for (int i = 0; i < *num_training_points; i++) {
        (*training_set)[i] = data[i];
    }
    for (int i = 0; i < *num_testing_points; i++) {
        (*testing_set)[i] = data[i + *num_training_points];
    }
    for (int i = 0; i < *num_validation_points; i++) {
        (*validation_set)[i] = data[i + *num_training_points + *num_testing_points];
    }
    return 0;
}