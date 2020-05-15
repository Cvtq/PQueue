#pragma once
#include <iostream>
#include <list>       // std::vector
#include <algorithm>    // std::shuffle 
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

using namespace std;

template <typename T>
class PQueue
{
private:
	std::list<T> _pQueue;
	size_t _size = 0;
public:

	PQueue() {

	}

	void Push(T item) {
		this->_pQueue.push_back(item);
		this->_size++;
	}

	T Pop() {
		if (this->size() > 0) {	
			T min = _pQueue.front();
			for (T i : _pQueue) {
				if (min > i)
					min = i;
			}
			auto element = min;
			this->_pQueue.erase(min_element(_pQueue.begin(), _pQueue.end()));
			this->_size--;
			return element;
		}		
	}

	T Peek() {
		T element = _pQueue.front();
		return element;
	}

	size_t size() {
		return this->_size;
	}

	bool Empty() {
		return this->_size == 0;
	}

	// Вывод массива
	void print()
	{
		for (T i : _pQueue) {
			cout << i << ' ';
		}
	}
};

