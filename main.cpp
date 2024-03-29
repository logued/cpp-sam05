// Pointers_and_Arrays       sam05        February 2023
/*
   Using Pointers to access arrays.
   Pointer Arithmetic - incrementing pointers and using them to access array elements.

   NB:  "The name of an array is a constant pointer to the first element of an array."
*/

#include <iostream>
using namespace std;

int main()
{
    int x[4] = { 10,20,30,40 };  // static array with 4 elements

    int* p;    // declare p as a 'pointer to an int'
    // a pointer is variable that can store the address of an object

    p = x;   // Remember that the name of the array is a constant pointer to
    // the beginning of the array. So, x gives back the address of the
    // first element of the array.  ( Note that we do not use &x )
    // The address of the first element in the array ( i.e. x) is
    // assigned into the pointer 'p' .  So, p now also points at the first
    // element of the array x.

    cout << "Value stored in pointer p = " << p << endl;

    cout << "Value at *p = " << *p << endl; // dereference the pointer p giving
                                            // the first element in the array.

    p++;  // Increment the pointer p.
    // This means increment the value of the pointer
    // so that it points at the next element in the array x[].
    // When we increment a pointer it is incremented by the length of
    // the type of the object it points to.  Here, p is a pointer to int,
    // so, the value 4 (assuming a 4-byte int) is actually added to
    // the address stored in the pointer. (The size of an int is 4 bytes).
    // Incrementing a pointer always moves the pointer forward to
    // the next element in an array.

    cout << "Value stored in pointer p should be greater (by 4) than it was, p = " << p << endl;

    cout << "Value at *p = " << *p << endl; // should print second element from array x[]

    p = p + 2;  // this will move the pointer on by two elements, leaving it pointing
                // at the last element the array. (adds 2 x sizeof(int) to p )

    *p = 99;   // Assigns the value 99 to where p is pointing, i.e. at the last
                // element of the array. The pointer is de-referenced to access that location.

    // At this point, the pointer p is pointing to the last element in the array.
    // If we want to print out the array elements using the pointer we must (re)set the
    // pointer to point to the beginning of the array, as follows:

    p = x;  // p is reset to point at the start of array
            // remember - the name of the array x, is the address of the start of the array

    for (int i = 0; i < 4; i++)
    {
        cout << *p << ", ";  // de-reference the pointer to access what the pointer is pointing at.
        p++;                 // (increment) move the pointer on to the next element.
    }

    // The danger with pointers :
    // After the above for loop finishes, the pointer p has been incremented
    // to a position just beyond the last element in the array.
    // This memory space does not belong to the array, so we are pointing at memory
    // that is beyond the bounds of the array.
    // In Java, an Exception will be thrown to prevent this, but in C++
    // no warning is given, and you can accidentally access/change that memory by mistake.

    cout << "\nDanger ! Programmer error ! - pointer accessing beyond end of array. *p = ";
    cout << *p << endl;

    // Even worse danger !!!
    // Explain happens when you execute this (assuming the for loop above was executed)
    // and the pointer p points beyond the end of the array.
    *p = 666;
    cout << *p << endl;
    // Above, we have written a value to a memory location that is outside the array.
    // So, we have written a value to some arbitrary location, possibly overwriting
    // and corrupting the contents of some other variable. This is a bad bug.


    //TODO Q.1
    //    Declare and initialize an array d[] of 5 double values.
    //    Declare a pointer "pd" and assign it to point at the beginning of the array.
    //    Write a for loop that will use the pointer to double (multiply by two) the value of
    //    each array element.  Write a second for loop that uses a pointer to iterate
    //    over the elements and dereference the pointer to display each element.
    //    add solution here...


    //TODO Q.2
    //    Continuing from above....
    //    Reset the pointer "pd" to point at the start of the array.
    //    Set the pointer "pd" to point at the last element in the array d[]
    //    Display the address of the last element.
    //    Be careful that it is set to point at the last element, and not beyond
    //    the last element.
    //    Use a for loop, and the pointer, to print the array elements in reverse order.
    //    Hint, decrement the pointer.

    //system("PAUSE");  //  comment out if necessary
    return 0;
}
