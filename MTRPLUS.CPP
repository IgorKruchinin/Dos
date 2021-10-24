#include <IOSTREAM.H>
#include <TIME.H>
#include <STDLIB.H>

int main(int argc, char const * argv[]) {
	if (argc == 3) {
		double amount = 0;
		for (int i = 0; i < atoi(argv[1]); i++) {
			srand(time(NULL));
			int a = rand();
			srand(clock());
			int b = rand();
			int c = 0;
			cout << a << " + " << b << " = " << "?\n";
			long long t = time(NULL);
			cin >> c;
			if (c == a + b && time(NULL) <= t + atoi(argv[2])) {
				cout << "You are right!\n";
				++amount;
			} else if (time(NULL) > t + atoi(argv[2])) {
				cout << "Timed out!\n";
			} else {
				cout <<  "Wrong answer!\n";
			}
		}
		cout << "True answers: " << amount / atoi(argv[1]) * 100 << "%";
	} else {
		cout << "Usage: MTRPLUS {number of examples per addition} {timeout}";
	}
	return 0;
}