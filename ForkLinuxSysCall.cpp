// fork() is used to create a new child process.

#include <iostream>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

int main()  //Parent process
{
    // create a variable to hold the process ID
    pid_t pid;

    // Create a child process, thus making 2 processes run at the same time.
    // Store the Process ID in 'pid'
    pid = fork();   //Child process

    // Check if 'pid' is 0. If yes, then it's the parent process. Else, it is the child process.
    if (pid == 0)
        cout << "Output from the child process." << endl;
    else
        cout << "Output from the parent process." << endl;

    return 0;
}
