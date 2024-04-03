#pragma once
#include <iostream>
#include <nlohmann/json.hpp>
#include "Sorts.h"
namespace Tools {
	void showMenu();
	void showCurrentWeather(nlohmann::json data);
	void showFiveDaysForecast(nlohmann::json data);
	void showFiveDaysForecastAVG(nlohmann::json data);
	void printArrSort(int*& arr, int& len);
}

