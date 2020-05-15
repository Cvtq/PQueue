#pragma once

class Worker {

private:
	size_t _freeTime = 0;
	size_t _taskTime = 0;
	size_t _id = 0;

public:

	Worker(size_t id) {
		_id = id;
	}

	void giveTask(size_t time) {
		if (_taskTime == 0) {
			cout << "�������� #" << setw(2) << _id << " ������� ������� ������������� " << time << " �� ����� �������� ������� " << _freeTime << endl;
			_taskTime = time;
			_freeTime = 0;
		}
	}

	size_t id() {
		return _id;
	}

	bool isFree() {
		return _taskTime == 0;
	}

	void tick() {
		if (_taskTime > 0) {
			_taskTime--;
		}
		else {
			_freeTime++;
		}
	}

	size_t freeTime() {
		return	_freeTime;
	}
};