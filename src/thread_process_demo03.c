/*
Mark Deegan Sat Jan 11 20:07:59 GMT 2025
Threads that waste CPU cycles
Example that illustrates concepts arounf threads.
Note the use of static, local and global variables
Examine how these variable change as the threads run */

#include <pthread.h>    // this is required for accesing threads
#include <stdio.h>      // this is required for accessing printf etc.
#include <inttypes.h>   // this is required for the format spefifying for PRIu64
#include <unistd.h>     // this is required for accessing the process ID

// Let us create a global variable to change it in threads
int global_variable;

// The function to be executed by all threads
void* myThreadFun(void* vargp)
{ // start definition of the thread function
    // declare a variable to hold the thread ID
    uint64_t m_tid;
    // retrieve and store the process ID in m_tid
    pthread_threadid_np(NULL, &m_tid);

    // store the process ID
    int myid = getpid();

    // Let us create a static variable to observe its
    // changes
    static int local_static_variable = 0;

    // we will also create a non-static local variable to
    // observe the changes in it
    int local_variable = 0;

    // Change static and global variables
    local_variable++;
    local_static_variable++;
    global_variable++;
    
    // printf("HELLO from thread runnable1 with process ID: %d,  thread ID: %ld\n", myid, m_tid);
    printf("ProcessID: %d, ThreadID:%" PRIu64 ", Local: %d, Static: %d, Global: %d\n", myid, m_tid, local_variable, local_static_variable, global_variable);

    return 0;
} // end definition of the thread function

// define the main method
int main()
{ // start definition of the main method
    // declare variable for creating and counting threads
    int i;
    // declare variable for managing thread IDs
    pthread_t tid;
    // declare a global cariable accessible to all threads
    global_variable=0;

    // Let us create three threads
    for (i = 0; i < 3; i++)
    { // start creating threads
        pthread_create(&tid, NULL, myThreadFun, NULL);
    } // end creating threads

    pthread_exit(NULL);
    return 0;
} // end definition of the main method