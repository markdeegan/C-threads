/*
Mark Deegan Sun 22 Dec 2024 12:31:34 GMT
Threads that waste CPU cycles
*/


#include <stdio.h>	    // handle IO using printf() function
#include <stdlib.h>     // necessary for using the exit() function at the end of main()

#include <pthread.h>    // nbecessary for thread-related definitions and functions, pthread_t, pthread_create and pthread_join
#include <unistd.h>	    // access the POSIX operating system API for sleep() and getpid() functions

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void* myThreadFunction(void* vargp)
{   // define the function to be used by the thread.
    printf(" PID is %d\n", getpid());           // print the PROCESS ID
    printf("Printing message from Thread \n");  // print a message
    sleep(1);                                   // sleep for a second, to give the impression of doing some work
    return NULL;                                // exit from the myThreadFunction() function 
}   // define the function to be used by the thread. A simple function that wastes CPU cycles "forever"

int main()
{   // define the main() function that will create two threads 
    // declare two variables to keep track of the threads created
    pthread_t thread_id_1;
    pthread_t thread_id_2;

    // print a message
    printf("Before Threads creation\n");

    // create two threads
    pthread_create(&thread_id_1, NULL, myThreadFunction, NULL);
    pthread_create(&thread_id_2, NULL, myThreadFunction, NULL);

    // wait for the two threads to terminate and rejoin the main programme
    // if we don't do this, then the threads contiue separate from the main() thread and 
    // they finish, when they finish, possibly after the main() function has done what it needed to do.  
    pthread_join(thread_id_1, NULL);
    pthread_join(thread_id_2, NULL);

    // print a message
    printf("After Thread termination\n");

    // exit witgh success code 0
    exit(0);
} // end main method
