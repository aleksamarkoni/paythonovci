#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv) {
	
	if (argc == 1) {
		cout << "Usage komand [[numbers]]" << endl;
		exit(1);
	}
	
	int s = 0;
	for (int i = 1; i < argc; i++) {
		int broj = atoi(argv[i]);
		s = s + broj;
	}
	
	cout << "Suma je: " << s << endl;
}