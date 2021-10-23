#include <STDIO.H>
#include <STDLIB.H>
#include <TIME.H>
#include <DOS.H>

void true_signal() {
	printf("\a");
}
void false_signal() {
	printf("\a");
	delay(25);
	printf("\a");
}

int main(int argc, char const * argv[]) {
	if (argc == 4) {
		void (*signal[2])(void);
		signal[0] = true_signal;
		signal[1] = false_signal;
		for (int i = 0; i <= atoi(argv[1]); i++) {
			srand(time(NULL));
			int sec = rand() % atoi(argv[3]) + atoi(argv[2]);
			delay(sec * 1000);
			signal[rand() % 2]();
		}
       } else {
	       printf("Usage: randbeep {number of signals} {minimum time between signals} {maximum time between signals}");
       }
       return 0;
}