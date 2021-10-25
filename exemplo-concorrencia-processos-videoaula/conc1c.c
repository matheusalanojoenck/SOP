/* Exercicio 6 da lista de pthreads */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <sys/types.h>
#include <pthread.h>

#define MAX 2000

long n;
int turn = 1;

void *f1(void *argp)
{
    long i;    /* R(t1) = W(t1) = { n } */
    for (i = 0; i < MAX; i++) {
         while (turn != 1)
	      ;
	 n++;  /* r1 <- n ; add r1, 1 ; n <- r1 */
	 turn = 2;
    }
    pthread_exit(NULL);
}

void *f2(void *argp)
{
    long i;    /* R(t2) = W(t2) = { n } */
    for (i = 0; i < MAX; i++) {
         while (turn != 2)
	      ;
	 n--;
	 turn = 1;
    }
    pthread_exit(NULL);
}

int main(void)
{
    pthread_t t1, t2;
    int rc;

    n = 0;
    rc = pthread_create(&t1, NULL, f1, NULL);   assert(rc == 0);
    rc = pthread_create(&t2, NULL, f2, NULL);   assert(rc == 0);
    rc = pthread_join(t1, NULL);   assert(rc == 0);
    rc = pthread_join(t2, NULL);   assert(rc == 0);
    printf("%ld\n", n);
    return 0;
}
