#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define NUM_THREADS     5

pthread_mutex_t mutex1;

void *PrintHello(void *threadid) {
	long tid;
	tid = (long) threadid;
	pthread_mutex_lock(&mutex1);
	cout << "Hello World! Thread ID, " << tid << endl;
 	pthread_mutex_unlock(&mutex1);
	pthread_exit(NULL);
}

int main() {
	pthread_t threads[NUM_THREADS];
        pthread_mutex_init(&mutex1, 0);
	int rc;
	int i;
	for (i = 0; i < NUM_THREADS; i++) {
		// cout << "main() : creating thread, " << i << endl;
		rc = pthread_create(&threads[i], NULL, PrintHello,(void *) i);
		if (rc) {
			cout << "Error:unable to create thread," << rc << endl;
			exit(-1);
		}
	}
	
	void *status;
        for(i = 0; i < NUM_THREADS; i++) {
                pthread_join(threads[i], &status);
                cout << "Complete thread id : " << i << endl;;
        }
	pthread_mutex_destroy(&mutex1);
	pthread_exit(NULL);
}
