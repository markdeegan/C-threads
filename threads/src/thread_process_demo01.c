/*
Mark Deegan Sun 22 Dec 2024 12:31:34 GMT
Threads that waste CPU cycles
*/


#include <iostream>	// handle IO using std::cout
#include <thread>	// handle threads 
#include <chrono>	// handle sleep
#include <unistd.h>	// access the POSIX operating system API

bool keep_running = true;


// a simple function that wastes CPU cycles "forever"
void cpu_waster()
{ // start the cpu_waster function
	// print out the Process ID for this function
		std::cout << "\t\tCPU Waster Process ID: " << getpid() << "\n";
	// print out the Thread ID for this function
		std::cout << "\t\tCPU Waster Thread ID " << std::this_thread::get_id() << "\n";
	// do whatever work the function needs to do
	// in this case, nothing other than loop forever
	// or, until keep_running is false;

	while(keep_running) continue;
} // end the cpu_waster function


// a simple progranmme to start two threads and to
// wait a while (5 seconds) to let them do whatever they need to do
int main() 
{ // start main method
	int seconds_count = 5; // variable to time-out 

	// print some thread values
	std::cout << "Thread hardware_concurrency is: " << std::thread::hardware_concurrency() << "\n";
 
	// print the counter value
	std::cout << "Counter is: " << seconds_count << "\n";

	// print out the Process ID for the main programme
	std::cout << "\tMain Process ID: " << getpid() << "\n";
	// print out the Thread ID for the main method
	std::cout << "\tMain Thread ID: " << std::this_thread::get_id() << "\n";
    
	// tell user we are creating some threads
	std::cout << "Creating two threads, each using the cpu_waster code \n";

	// start a thread (thread1) using the cpu_waster function as its code
	std::thread thread1(cpu_waster);
	// start another thread (thread2) using the cpu_waster function as its code
	std::thread thread2(cpu_waster); 

	while(seconds_count >0) 
	{ // keep the main thread alive as long as the seconds counter is non-zero
		// sleep (the main thread) for a second
		std::this_thread::sleep_for(std::chrono::seconds(1));
		// decrement the time_out value (5,4,3,2,1,0)
		seconds_count--;
		std::cout << "Counter is: " << seconds_count << "\n";
	} // end the while loop once the seconds_count == 0
	// before exiting the main programme, I should do something to terminate and 
	// to tidy up the cpu_waster threads

	// set the keep_running variable to false
	// this tells the cpu waster threads they can stop now
	keep_running = false;

	thread1.join();
	thread2.join();
	// TerminateThread(thread1.native_handle(), 1);
    // thread1.detach(); // After TerminateThread
} // end main method
