#include <iostream>
#include "MapVector.h"

int main()
{
    //data from sensors
    std::vector<int16_t> data_first_sensor;
    std::map<int16_t, int16_t> data_second_sensor;

    //generating random numbers from 1-9
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<int16_t> dist(0, 9);

    // fill in the sensors with random values from 1-9
    for(int16_t i {0}; i != ArrSize; ++i){

        data_first_sensor.push_back(dist(gen));

        data_second_sensor.insert({i, dist(gen)});

    }

    remove_from_first_sens(data_first_sensor);
    remove_from_second_sens(data_second_sensor);


    //we don't know what size the arrays will be after deleting random numbers,
    // so we create two functions to handle these arrays and call them by checking the size
    // using the branching operator

    if(data_first_sensor.size() < data_second_sensor.size()){

        //first delete from a larger array
        sync_second_sensor_with_first(data_second_sensor, data_first_sensor);
        sync_first_sensor_with_second(data_first_sensor, data_second_sensor);
    }
    else{

        sync_first_sensor_with_second(data_first_sensor, data_second_sensor);
        sync_second_sensor_with_first(data_second_sensor, data_first_sensor);
    }

    print(data_first_sensor, data_second_sensor);


    return 0;
}















