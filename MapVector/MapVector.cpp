#include "MapVector.h"
#include <iostream>


void remove_from_first_sens(std::vector<int16_t>& dataf_sensor)
{
   // generating random numbers from 1-9
   std::random_device rd;
   std::mt19937_64 gen_number{rd()};
   std::uniform_int_distribution<int16_t> dis(1, 9);

   int16_t gen_value = dis(gen_number);

   //deleting random values from the array
   dataf_sensor.erase(std::remove(begin(dataf_sensor),
                      end(dataf_sensor), gen_value), end(dataf_sensor));

   //get the exact size of the vector after deleting it
   int16_t vec_size =  static_cast<int16_t>(dataf_sensor.size());

   if(vec_size < SizeLimit){

      //if more elements are deleted, we load the vector up to the limit
      for(int16_t i = vec_size; i != SizeLimit; ++i){

           dataf_sensor.push_back(gen_value);
      }
   }

}

void remove_from_second_sens(std::map<int16_t,int16_t>& datas_sensor)
{
    std::random_device rd;
    std::mt19937_64 gen_number(rd());
    std::uniform_int_distribution<int16_t> dis(1, 9);

    int16_t gen_value = dis(gen_number);

    //no more than 15 items will be deleted
    for(int16_t i{0}; i != 15; ++i){

       //find random elements from 1-9
       std::map<int16_t, int16_t>::iterator it = datas_sensor.find(++gen_value);

       if(it != datas_sensor.end()){

          datas_sensor.erase(it);

       }
       else{
        std::cout << "That key not found " << std::endl;
       }

   }
}

//the function copies the necessary elements from firstSensor
template<typename T>
void save_item_first_sensor_if(SensorOne& one_sen, T&& func)
{
   SensorOne temp;

   //we only copy the unequal elements that we get from the function
   std::copy_if(one_sen.begin(), one_sen.end(), back_inserter(temp), func );

   temp.swap(one_sen);
}

//the function copies the necessary elements from secondSensor
template<typename T>
void save_item_second_sensor_if(SensorTwo& two, T&& func)
{
  SensorTwo temp;

  std::copy_if(two.begin(), two.end(), inserter(temp, temp.end()) , func);

  temp.swap(two);
}

//reserves space for the first sensor
TempSensor reserve_val_first_sensor(const SensorOne& one)
{
    return TempSensor(one.begin(), one.end(), one.size());
}

//reserve space for the second sensor
TempSensor reserve_val_second_sensor(const SensorTwo& two)
{
    TempSensor temp(two.size());

    for(const auto& a: two){

        temp.insert(a.second);

        return temp;
    }
}

void sync_first_sensor_with_second(SensorOne& one, const SensorTwo& two)
{
    //reserving memory for a temporary array
    TempSensor temp = reserve_val_second_sensor(two);

    //check equality using the predicate function
    save_item_first_sensor_if(one, [temp](int16_t i){return temp.find(i) != temp.end();});
}

void sync_second_sensor_with_first(SensorTwo& two, const SensorOne& one)
{
    TempSensor temp = reserve_val_first_sensor(one);

    save_item_second_sensor_if(two, [&temp](const auto& a){return temp.find(a.second) != temp.end();});
}

void print(const std::vector<int16_t>& vec, const std::map<int16_t, int16_t>& dat_sec_sens)
{
    //output the contents of the first sensor to the screen using an iterator
    std::copy(begin(vec), end(vec), std::ostream_iterator<int16_t>{std::cout, " \n"});


    std::cout << "*******************************************************" << std::endl;

    //display the contents of the second sensor on the screen
    // using a loop based on the range
    for(auto print_data: dat_sec_sens){

        std::cout << print_data.first << ": " << print_data.second << std::endl;
    }
}

