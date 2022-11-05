/*
 * Write a program (using fork())
 * where parent and child execute: 
 *  (a) same program, same code
 *  (b) same program, different code
 *  (c) before terminating, the parent waits for the child
 *      to finish its task.
 */

#include<bits/stdc++.h>
using namespace std;

void parentWaitForChild()
{
  pid_t pidFork;
  pidFork = fork();
  if(pidFork < 0)
    cout << "\nError in fork...";
  else if(pidFork == 0)
    cout << "\nChild executed\nProcess ID : " <<  getpid() << "\nParent Process ID : " << getppid() << endl;
  else
  {
    wait(NULL);
    cout << "\nParent executed\nProcess ID : " << getpid() << "\nParent Process ID : " << getppid() << endl;
  }
  return;
}

int main()
{
  parentWaitForChild();
}