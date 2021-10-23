#include <IOSTREAM.H>
#include <TIME.H>
#include <STDLIB.H>

int main(int argc, char const * argv[]) {
	if (argc == 3) {
		int amount = 0;
		for (int i = 0; i < atoi(argv[1]); i++) {
			srand(time(NULL));
			int a = rand();
			srand(clock());
			int b = rand();
			int c = 0;
			cout << a << " + " << b << " = " << "?\n";
			long long t = time(NULL);
			cin >> c;
			if (c == a + b && t <= time(NULL) + atoi(argv[2])) {
				cout << "You are right!\n";
				++amount;
			} else if (t > time(NULL) + atoi(argv[2])) {
				cout << "Timed out!";
			} else {
				cout <<  "Wrong answer!\n";
			}
		}
		cout << "True answers: " << amount / atoi(argv[1]) * 100 << "%";
	}
	return 0;
}