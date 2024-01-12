#ifndef OPERATIONS_H
#define OPERATIONS_H
#include "./nn.h"
#include <math.h>
typedef struct
{
    float training;
    float testing;
    float validation;
} SplitRates;
// Calculates the mean of a feature
double calculate_mean(HouseData *data, int num_points, FeatureAccessor accessor);
// Calculates the standard deviation of a feature
double calculate_std(HouseData *data, int num_points, FeatureAccessor accessor, double mean);
// Normalizes the data
int normalize_data(HouseData *data, int num_points);
// Shuffles the data
int shuffle_data(HouseData *data, int num_points);
// Splits the data into training and testing sets
int split_data(HouseData *data, int num_points, HouseData **training_set, int *num_training_points, HouseData **testing_set, int *num_testing_points, HouseData **validation_set, int *num_validation_points, SplitRates num_points_split);
#endif