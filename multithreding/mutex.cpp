#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define NUM_THREADS     5

pthread_mutex_t count_mutex;
long long count = 0;

void *PrintHello(void *i) {
	 for (int i = 0; i < 10000; i++) {
		 pthread_mutex_lock(&count_mutex);
		 count = count + 1;
		 pthread_mutex_unlock(&count_mutex);
	 }
   pthread_exit(NULL);
}

int main () {
   pthread_t threads[NUM_THREADS];
   int rc;
   int i;

	 void * status;
	 int greske = 0;
	 int probe = 0;
while (true) {
   for( i=0; i < NUM_THREADS; i++ ){
      //cout << "main() : creating thread, " << i << endl;
      rc = pthread_create(&threads[i], NULL, PrintHello, NULL);

      if (rc){
         cout << "Error:unable to create thread," << rc << endl;
         exit(-1);
      }
   }

	 for (i = 0; i < NUM_THREADS; i++) {
		 pthread_join(threads[i], &status);
	 }
	 probe++;
	 if (count != 50000) {
		 cout << "Doslo je do greske: " << count << endl;
		 if (greske++ == 5) {
			 break;
		 }
	 }
	 count = 0;
 }

	 cout << "Proba sam: " << probe << " puta" << endl;
   pthread_exit(NULL);
}
