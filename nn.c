#include "./include/utils.h"
#include "./include/nn.h"
#include "./include/operations.h"
int main()
{
    setbuf(stdout, NULL);
    _log(__func__, "Hello, %s!", "world");
    _log(__func__, "Beginning neural network...");

    // Read data
    _log(__func__, "Reading data...");
    const char *filename = "Housing.csv";
    HouseData *data = (HouseData *)malloc(1000 * sizeof(HouseData)); // Pointer to HouseData structure
    if (!data)
    {
        perror("Error allocating memory for data\n");
        return 1;
    }
    int num_points = 0;     // Number of data points
    if (read_data(filename, &data, &num_points) != 0)
    {
        _log(__func__, "Error reading data from %s", filename);
        return 1;
    }
    // Normalize data
    _log(__func__, "Normalizing data...");
    if (normalize_data(data, num_points) != 0)
    {
        _log(__func__, "Error normalizing data");
        return 1;
    }
    // Shuffle data
    _log(__func__, "Shuffling data...");
    if (shuffle_data(data, num_points) != 0)
    {
        _log(__func__, "Error shuffling data");
        return 1;
    }
    // Split data
    _log(__func__, "Splitting data... 85/10/5");
    HouseData *training_set = NULL;
    HouseData *testing_set = NULL;
    HouseData *validation_set = NULL;
    int num_training_points = 0;
    int num_testing_points = 0;
    int num_validation_points = 0;
    SplitRates num_points_split = {0.85, 0.10, 0.05};
    if (split_data(data, num_points, &training_set, &num_training_points, &testing_set, &num_testing_points, &validation_set, &num_validation_points, num_points_split) != 0)
    {
        _log(__func__, "Error splitting data");
        return 1;
    }
    // Free data
    _log(__func__, "Freeing data...");
    free(data);
    return 0;
}