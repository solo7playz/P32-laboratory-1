#include "Tools.h"
#include "Sorts.h"
#include "WebApp.h"
#include <map>
using namespace Tools;
const std::string API = "e7c0bce5516c376f0d980ddc956bb225";
//std::map<std::string, unsigned> safe;
int main() {
	setlocale(LC_ALL, "RUS");
	using json = nlohmann::json;
	std::string city;
	std::cout << "Введите город: ";
	std::cin >> city;
	showMenu();
	int tmp; std::cin >> tmp;
	int choice = tmp;
	if (tmp > 1) {
		tmp = 1;
	}
	int q = 0;
	int* arr = new int[q];
	while (tmp) {
		WebApp app("http://api.openweathermap.org", API, city);
		json data;
		//safe[city] = data["main"]["temp"];
		switch (choice) {
		case 0:
			std::cout << "Программа завершила свою работу!" << std::endl;
			tmp = 0;
			break;
		case 1:
			data = app.getCurrentWeather();
			showCurrentWeather(data);
			arr[q] = (int)(data["main"]["temp"]) - 273;
			showMenu();
			std::cin >> choice;
			q++;
			break;
		case 2:
			data = app.getFiveDaysForecast();
			showFiveDaysForecast(data);
			showMenu();
			std::cin >> choice;
			break;
		case 3:
			std::cout << "Введите город: ";
			std::cin >> city;
			app.setCityName(city);
			showMenu();
			std::cin >> choice;
			break;
		case 4:
			data = app.getFiveDaysForecastAVG();
			showFiveDaysForecastAVG(data);
			showMenu();
			std::cin >> choice;
			break;
		}
		int* arr = new int[q];
	}
	Sorts::showMenuSort();
	int choiceSort; std::cin >> choiceSort;
	switch (choiceSort) {
	case 0:
		std::cout << "Программа завершила работу." << std::endl;
		break;
	case 1:
		Sorts::bubleSort(arr, q);
		Tools::printArrSort(arr, q);
		break;
	case 2:
		Sorts::choicesSort(arr, q);
		Tools::printArrSort(arr, q);
		break;
	case 3:
		Sorts::pasteSort(arr, q);
		Tools::printArrSort(arr, q);
		break;
	case 4:
		Sorts::countingSort(arr, q);
		Tools::printArrSort(arr, q);
		break;
	}

	return 0;
}