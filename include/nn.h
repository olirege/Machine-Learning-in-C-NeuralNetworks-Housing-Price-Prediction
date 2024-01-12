#ifndef NN_H
#define NN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Function pointer type for accessing features
typedef double (*FeatureAccessor)(HouseData*); 
double area_accessor(HouseData* data);
double bedrooms_accessor(HouseData* data);
double bathrooms_accessor(HouseData* data);
double stories_accessor(HouseData* data);

// Reads data from csv file
int read_data(const char *filename, HouseData **data, int *num_points);
#endif