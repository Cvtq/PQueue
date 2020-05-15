#pragma once
class Task {
private:
	size_t _time = 0;
	size_t _id = 0;
	size_t _priority = 0;

public:

	Task() {

	}

	Task(size_t id, size_t time, size_t priority) {
		_time = time;
		_id = id;
		_priority = priority;
	}

	void setTime(size_t time) {
		_time = time;
	}

	void setId(size_t id) {
		_id = id;
	}

	void setPrioiry(size_t priority) {
		_priority = priority;
	}

	size_t id() {
		return _id;
	}

	size_t time() {
		return _time;
	}

	size_t priority() {
		return _priority;
	}

	bool operator < (Task right) {
		if (this->priority() < right.priority()) {
			return true;
		}
		return false;
	}

	bool operator > (Task right) {
		if (this->priority() > right.priority()) {
			return true;
		}
		return false;
	}
};