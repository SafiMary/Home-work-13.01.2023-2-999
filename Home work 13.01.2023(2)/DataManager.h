#pragma once
#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

template <typename T1, typename T2>
class DataManager
{
public:
	DataManager() :_id(0) {}
	~DataManager() {}

	void addInfo(T2& info) {
		_id++;
		_keys.push_back(_id);
		_managermap.insert(std::make_pair(_id, info));
	}

	void printMap() {
		for (const auto& [_id, value] : _managermap) {
			std::cout << _id << " " << value << '\n';
		}
	}

	void eraseInfo(T1 _id) {
		_keys.push_back(_id);
		_managermap.erase(_id);
	}


	void changeInfo(T1 _id, T2& info) {
		if (_managermap.find(_id) != _managermap.end()) {
			_keys.push_back(_id);
			_managermap.erase(_id);
			_managermap.insert(std::make_pair(_id, info));
		}
		else {
			std::cout << "Ошибка!Модификация невозможна" << '\n';
		}
	}
	void findInfo(T1 _id) {
		_keys.push_back(_id);
		auto it = _managermap.find(_id);
		if (it != _managermap.end()) {
			std::cout << it->first << " " << it->second << "\n";
		}
		else {
			std::cout << "Ошибка, нет такого значения!" << std::endl;
		}

	}
	int mostSearchedKey() {
		std::vector<int>::iterator it1 = _keys.begin();
		std::unordered_map<int, int> keyAmount;
		for (size_t i = 0; i < _keys.size(); i++) {
			const auto& [it1, isInserted] = keyAmount.insert({ _keys[i], 1 });
			if (!isInserted) {
				auto value = it1->second;
				value++;
				keyAmount[_keys[i]] = value;
			}
		}
		std::pair<int, int> key_biggestValue = { 0,0 };
		for (std::unordered_map<int, int>::const_iterator it1 = keyAmount.begin(); it1 != keyAmount.end(); it1++) {
			if (key_biggestValue.second < it1->second) {
				key_biggestValue = std::make_pair(it1->first, it1->second);
			}
		}
		return key_biggestValue.first;
	}



private:
	std::vector<int> _keys;
	std::map<T1, T2> _managermap;
	T1 _id;
	T2 _info;
};







