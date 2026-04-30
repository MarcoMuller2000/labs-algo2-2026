#include "weather_utils.h"

int lowest_min_temp(WeatherTable table){
    int min = table[0][january][0]._min_temp;

    for (unsigned int year = 0; year < YEARS; year++) {
        for (month_t month = january; month <= december; month++) {
            for (unsigned int day = 0; day < DAYS; day++) {
                if (table[year][month][day]._min_temp < min) {
                    min = table[year][month][day]._min_temp;
                }
            }
        }
    }
    return min;
}

void yearly_max_temp(WeatherTable table, int output[YEARS]) {
    for (unsigned int year = 0; year < YEARS; year++) {
        month_t best_month = january;
        unsigned int best_rain = month_rainfall(table, year, january);

        for (month_t month = february; month <= december; month++){
            unsigned int rain = month_rainfall(table, year, month);

            if (rain > best_rain) {
                best_rain = rain;
                best_month = month;

            }
        }
        output[year] = best_month +1;
    }
}

static unsigned int month_rainfall(WeatherTable table, unsigned int year, month_t month) {
    unsigned int sum = 0;
    
    for (unsigned int day = 0; day < DAYS; day++) {
        sum = sum + table[year][month][day]._rainfall;
    }
    return sum;
}