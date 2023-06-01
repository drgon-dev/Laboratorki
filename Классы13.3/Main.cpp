#include <iostream>
#include <list>
#include <queue>
#include <numeric>
#include <algorithm>
#include <map>
#include "Pair.h"

using namespace std;

void ex_3()
{
	map <int, int> myMap = { {1, 2}, {2, 4}, {3, 6} };
	cout << "Добавляем среднее ариф среди значений в конец:\n";
	int sum = 0;
	for (auto& p : myMap) {
		sum += p.second;
	}
	int avg = sum / myMap.size();
	myMap[0] = avg;
	for (auto& p : myMap) {
		cout << p.first << ": " << p.second << endl;
	}

	cout << "Удаляем ключ 2:\n";
	myMap.erase(2);
	cout << "Добавляем макс и мин значения к значениям ключей:\n";
	auto maxIt = std::max_element(myMap.begin(), myMap.end(),
		[](const auto& p1, const auto& p2) { return p1.second < p2.second; });
	auto minIt = std::min_element(myMap.begin(), myMap.end(),
		[](const auto& p1, const auto& p2) { return p1.second < p2.second; });
	int maxVal = maxIt->second;
	int minVal = minIt->second;

	for (auto& p : myMap) {
		p.second += maxVal + minVal;
		cout << p.first << " : " << p.second << endl;
	}
}

int main(){
	ex_3();
	return 0;
}