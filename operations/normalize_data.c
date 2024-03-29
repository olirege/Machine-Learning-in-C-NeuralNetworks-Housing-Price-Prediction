#include "../include/operations.h"
#include "../include/utils.h"
int normalize_data(HouseData *data, int num_points) {
    // Calculate mean and standard deviation of each feature
    _log(__func__, "Calculating mean and standard deviation of each feature...");
    double mean_area = calculate_mean(data, num_points, area_accessor);
    double mean_bedrooms = calculate_mean(data, num_points, bedrooms_accessor);
    double mean_bathrooms = calculate_mean(data, num_points, bathrooms_accessor);
    double mean_stories = calculate_mean(data, num_points, stories_accessor);
    double mean_parking = calculate_mean(data, num_points, parking_accessor);
    double mean_price = calculate_mean(data, num_points, price_accessor);
    double stddev_area = calculate_std(data, num_points, area_accessor, mean_area);
    double stddev_bedrooms = calculate_std(data, num_points, bedrooms_accessor, mean_bedrooms);
    double stddev_bathrooms = calculate_std(data, num_points, bathrooms_accessor, mean_bathrooms);
    double stddev_stories = calculate_std(data, num_points, stories_accessor, mean_stories);
    double stddev_parking = calculate_std(data, num_points, parking_accessor, mean_parking);
    double stddev_price = calculate_std(data, num_points, price_accessor, mean_price);
    _log(__func__, "Normalizing data points...");
    for(int i = 0; i < num_points; i++) {
        data[i].area = (data[i].area - mean_area) / stddev_area;
        data[i].bedrooms = (data[i].bedrooms - mean_bedrooms) / stddev_bedrooms;
        data[i].bathrooms = (data[i].bathrooms - mean_bathrooms) / stddev_bathrooms;
        data[i].stories = (data[i].stories - mean_stories) / stddev_stories;
        data[i].parking = (data[i].parking - mean_parking) / stddev_parking;
        data[i].price = (data[i].price - mean_price) / stddev_price;
    }
    return 0;
}