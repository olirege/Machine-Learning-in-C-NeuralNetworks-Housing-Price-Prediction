#include "../include/nn.h"

double area_accessor(HouseData* data) {
    return data->area;
}
double bedrooms_accessor(HouseData* data) {
    return data->bedrooms;
}
double bathrooms_accessor(HouseData* data) {
    return data->bathrooms;
}
double stories_accessor(HouseData* data) {
    return data->stories;
}
double parking_accessor(HouseData* data) {
    return data->parking;
}
double price_accessor(HouseData* data) {
    return data->price;
}