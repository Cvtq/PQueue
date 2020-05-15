#include <iostream>
#include <iomanip>      // std::setw
#include "PQueue.h"
#include "task.h"
#include "worker.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	{	
		PQueue<size_t> q;

		size_t tasks[10] = { 10, 20, 31, 4, 100, 55, 0, 2, 1, 16 };

		cout << "Задачи: " << endl;
		for (size_t i : tasks) {
			cout << i << " ";
			q.Push(i);
		}

		cout << endl;

		cout << "Приоритет очереди: " << endl;
		for (size_t i : tasks)
			cout << q.Pop() << " ";
		cout << endl;
	};

	{
		cout << endl;
		PQueue<Task> q;
		const size_t n = 6;

		// Генерация заданий
		cout << "Задания: " << endl;
		srand(std::chrono::system_clock::now().time_since_epoch().count());
		for (size_t i = 0; i < n; i++) {
			Task t = Task(i, rand() % 100, rand() % 10);
			q.Push(t);
			cout << "Задание #" << t.id() << " c приоритетом " << t.priority() << " займет " << t.time() << endl;
		}
		cout << endl;

		cout << "Выполнение заданий: " << endl;
		for (size_t i = 0; i < n; i++) {
			auto item = q.Pop();
			cout << "Задание #" << item.id() << " c приоритетом " << item.priority() << " заняло " << item.time() << endl;
		}
		cout << endl;

	};

	{
		PQueue<Task> q;
		const size_t n = 15;
		const size_t operators = 4;

		// Генерация заданий
		cout << "Задания: " << endl;
		srand(std::chrono::system_clock::now().time_since_epoch().count());
		for (size_t i = 0; i < n; i++) {
			Task t = Task(i, (rand() % 100) + 1, rand() % 10);
			q.Push(t);
			cout << "Задание #" << setw(2) << t.id() << " c приоритетом " << t.priority() << " займет " << setw(2) << t.time() << endl;
		}
		cout << endl;

		cout << "Операторов: " << operators << endl;
		vector<Worker> v;
		for (size_t i = 0; i < operators; i++) {
			v.push_back(Worker(i));
		}

		// Моделирование
		bool modeling = true;
		while (modeling) {

			for (size_t i = 0; i < v.size(); i++) {
				if (v[i].isFree() && !q.Empty()) {
					// Даем работу
					v[i].giveTask(q.Pop().time());
				}
				v[i].tick();
			}

			// Все ли задания сделаны
			if (q.Empty()) {
				size_t amountOfFree = 0;
				for (size_t i = 0; i < v.size(); i++) {
					if (v[i].isFree()) {
						amountOfFree++;
					}
					else {
						break;
					}
				}

				if (amountOfFree == v.size()) {
					modeling = false;
				}
			}
		}

		cout << endl;
		cout << "Вся работа закончена! " << endl;
		for (size_t i = 0; i < v.size(); i++) {
			cout << "Работник #" << setw(2) << v[i].id() << " отдыхает уже " << setw(3) << v[i].freeTime() << endl;
		}

	};
}
