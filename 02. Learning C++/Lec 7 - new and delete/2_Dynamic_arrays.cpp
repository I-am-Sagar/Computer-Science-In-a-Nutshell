#include <iostream>
using namespace std;

int main()
{
   int *a = new int;
   int size;
   
   cout << "Enter the size of the array you want: ";
   cin >> size;
   
   for (int i = 0; i < size; i++)
      cin >> *(a+i);
   
   for (int i = 0; i < size; i++)
      cout << "a[" << i << "] = " << *(a+i) << endl;
   
   delete [] a;
   
   return 0;
}

/* But this is not a good way of creating dynamic arrays in C++ by using just 
   a single pointer.

   This is because when we store the elements in memory blocks using a single 
   pointer, there is a possibility that already say fourth memory block is used 
   up by some data already stored previously. Now in such case we will be 
   over-riding the that value which may create further errors. 
   
   However this does not happen when memory of machine is large enough and 
   when we are writing small programs like this.
   
   But in bigger programs, like projects, we do avoid this method. Then in 
   larger programs, for dynamic arrays, we use vector template. Vectors will be
   covered in template library, but for time-being we can use this method till 
   we reach templates as our programs are not big - atleast as of now.
*/
