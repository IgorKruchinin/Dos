#include <IOSTREAM.H>

template <class FTYPE>
class LST {
	FTYPE value;
	LST<FTYPE> *next;

public:
	LST (FTYPE value = 0) {
		this->value = value;
		this->next = NULL;
	}

	void operator=(FTYPE value) {
		this->value = value;
	}

	LST* append(FTYPE const &element) {
		LST<FTYPE> *ptr = this;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = new LST<FTYPE>(element);
		//ptr->next->value = element;
		return ptr->next;
	}

	void pop() {
		LST<FTYPE> *ptr = this;
		while (ptr->next->next != NULL) {
			ptr = ptr->next;
		}
		delete ptr->next;
		ptr->next = NULL;
	}

	LST* to_next() {
		return this->next;
	}

	LST* end() {
		LST<FTYPE> *ptr = this;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		return ptr;
	}

	LST* jump(int index = 0) {
		LST<FTYPE> *ptr = this;
		int counter = 0;
		while (ptr->next != NULL || counter != index) {
			ptr = ptr->next;
			++counter;
		}
		return ptr;
	}

	FTYPE& operator[](int index) {
		LST<FTYPE> *ptr = this;
		int counter = 0;
		while (ptr->next != NULL && counter != index) {
			ptr = ptr->next;
			++counter;
		}
		return ptr->value;
	}

	int len() {
		LST<FTYPE> *ptr = this;
		int counter = 0;
		while (ptr != NULL) {
			ptr = ptr->next;
			++counter;
		}
		return counter;
	}
};

int main() {
	LST<int> a(2);
	LST<int> *ptr = &a;
	a.append(5);
	//ptr = ptr->to_next();
	a.append(10);
	a.append(20);
	a.append(30);
	//ptr = ptr->to_next();
	for (int i = 0; i < a.len(); ++i) {
		cout << a[i] << ' ';
	}
	cout << '\n';
	a[2] = 72;
	for (int j = 0; j < a.len(); ++j) {
		cout << a[j] << ' ';
	}
	cout << '\n';
	a.pop();
	for (int k = 0; k < a.len(); ++k) {
		cout << a[k] << ' ';
	}
        cout << '\n';
	return 0;
}