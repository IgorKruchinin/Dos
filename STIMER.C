#include <STDIO.H>
#include <DOS.H>
#include <STDLIB.H>

int main(int argc, const char *argv[]) {
	if (argc == 3) {
		printf("You have %d seconds to get ready, then the program will give a signal and the countdown will begin\n", atoi(argv[1]));
		delay(atoi(argv[1]) * 1000);
		printf("\a");
		delay(atoi(argv[2]) * 1000);
		printf("\a");
		delay(10);
		printf("\a");
	} else {
		printf("Usage: STIMER {number of seconds to get ready} {seconds to countdown after getting ready}");
	}
	return 0;
}