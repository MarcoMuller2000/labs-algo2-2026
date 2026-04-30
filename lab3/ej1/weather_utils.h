#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H

#include "weather_table.h"

int lowest_min_temp(WeatherTable table);

void yearly_max_temp(WeatherTable table, int output[YEARS]);

void yearly_rainiest_month(WeatherTable table, unsigned int output[YEARS]);

#endif