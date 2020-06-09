#ifndef MAPVECTOR_H
#define MAPVECTOR_H

#include <vector>
#include <map>
#include <string>
#include <random>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <unordered_set>


const int16_t ArrSize {100};
const int16_t SizeLimit {85};

using SensorOne = std::vector<int16_t>;
using SensorTwo = std::map<int16_t, int16_t>;
using TempSensor = std::unordered_set<int16_t>;


void remove_from_first_sens(std::vector<int16_t>& dataf_sensor);

void remove_from_second_sens(std::map<int16_t, int16_t>& datas_sensor);

void print(const std::vector<int16_t>& vec, const std::map<int16_t, int16_t>& dat_sec_sens);

template<typename T>
void save_item_first_sensor_if(SensorOne& one_sen, T&& func);

template<typename T>
void save_item_second_sensor_if(SensorTwo& two_sen, T&& func);

TempSensor reserve_val_second_sensor(const SensorTwo& two);

inline TempSensor reserve_val_first_sensor(const SensorOne& one);

void sync_first_sensor_with_second(SensorOne& one, const SensorTwo& two);

void sync_second_sensor_with_first(SensorTwo& two, const SensorOne& one);

#endif // MAPVECTOR_H
