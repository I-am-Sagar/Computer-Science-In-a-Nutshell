/*  Placement new allows us to specify the location to be used. 
    A programmer might use this feature to set up his own 
    memory-management procedures.
*/

#include <iostream>
//#include <new> Refer: Tip 1        
using namespace std;

const int BUF = 512;
const int N = 5;
//memory chunk of 512 bytes
char buffer [512]; 


int main()
{
    double *pd1, *pd2, *pd3, *pd4;
    int i;
    
    cout << "Calling new and placement new: \n";
    //uses heap
    pd1 = new double[N];  
    //uses buffer array 
    pd2 = new (buffer) double[N];  
    
    for (i = 0; i < N; i++)
        pd2[i] = pd1[i] = 1000 + 20.0*i;
    
    //if I dont void* the buffer, program will print string
    cout << "Memory addresses:\n" << "\theap: " << pd1
         << "\tstatic: " << (void*)buffer << endl;
    cout << "Memory contents:\n";
    for (i = 0; i < N; i++)
    {
        cout << pd1[i] << " at " << &pd1[i] << " & "
             << pd2[i] << " at " << &pd2[i] << endl;
    }
    
    
    cout << "Calling new and placement new second time: \n";
    //finds new address
    pd3 = new double[N];
    //overwrites old data
    pd4 = new (buffer) double[N];
    
    for (i = 0; i < N; i++)
        pd4[i] = pd3[i] = 1000 + 40.0*i;
    
    cout << "Memory addresses:\n" << "\theap: " << pd1
         << "\tstatic: " << (void*)buffer << endl;
    cout << "Memory contents:\n";
    for (i = 0; i < N; i++)
    {
        cout << pd3[i] << " at " << &pd3[i] << " & "
             << pd4[i] << " at " << &pd4[i] << endl;
    }
    
    
    cout << "Calling new and placement new third time: \n";
    delete [] pd1;        // Refer Tip 2 + 3      
    pd1 = new double[N];   
    pd2 = new (buffer + N*sizeof(double)) double[N];  // Refer Tip 4    
    
    for (i = 0; i < N; i++)
        pd2[i] = pd1[i] = 1000 + 60.0*i;
    
    cout << "Memory addresses:\n" << "\theap: " << pd1
         << "\tstatic: " << (void*)buffer << endl;
    cout << "Memory contents:\n";
    for (i = 0; i < N; i++)
    {
        cout << pd1[i] << " at " << &pd1[i] << " & "
             << pd2[i] << " at " << &pd2[i] << endl;
    }
    
    delete [] pd1;
    delete [] pd3; 
    return 0;
}
/*
    Tips:
    1) Sometimes you need to include #include <new> for prototype of placement 
       new, if placement new is not working i.e. when compiler isn't able to 
       understand the syntax of placement new.
       
    2) Whenever we reuse the pointer which was pointing to a dynamically 
       allocated memory chunk, its our responsiblity to first delete the memory 
       chunk and then reuse it. If not done so, the compiler wont give u an 
       error, but it will find another chunk of memory keeping the previous 
       memory chunk as it is. Now it was only the pointer through which you 
       could actually access that chunk, once that pointer is pointing to 
       another memory chunk, you have no way to release that memory. And with 
       such practices you will run out of space immediately.
       
    3) There is no need to and you should not delete pointer made point using 
       placement new. Or else your code will compile but it will give you 
       run-time error (because syntactically you are right but dynamically 
       while execution, you get a core dumped error).
       
       Core dumped/Segmentation Fault is the error when system tries to 
       access the memory which it shouldn't or doesn't exist anymore.

       The difference between these two terms is "Segmentation fault is the 
       invalid memory access which causes the application to stop immediately. 
       Now a Core dump file is usually written by compiler and the file is 
       located at:
       /proc/sys/kernel/core_pattern    all core files here
       /usr/lib/systemd/systemd-coredump  all core dumped files here
       
       These files are generally useful by top programmers which use these files 
       as a post-mortem snapshot of the program's state at the time of the crash, 
       especially if the fault is hard to reliably reproduce.
       
    4) If the value of N is such that, the address inside loop exceeds buffer, 
       eg. N is 62, the loop runs 5 times, allocating 5 spaces after 62, where 
       in case only 2 spaces are possible (512/sizeof(double) gives 64). In such 
       overflow cases, there wont be any compiler error and even program will 
       execute successfully, but when the pointer is automatically deleted, 
       it frees only the buffer memory i.e. the overflow memory cannot be freed. 
       If we try to use delete manually we should again remember, delete cannot
       be used on placement new pointer allocators. So the programmer should 
       keep this in mind while using buffer.  
*/
