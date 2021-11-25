//
//  main.cpp
//  Review HW 4
//
//  Created by Scott Vu on 11/19/21.
//

#include <iostream>
#include <array>
#include <iomanip>

using namespace std;

int main() {
    
    /*
     
    Implement a simple hash table that uses quadratic probing
     
    You can use an array for the hash table
    The array should hold integer values (the keys)
     
    The keys should be within the range of 100 - 999
    The initial size of the array will be 11
     
    Develop a hashing function that uses quadratic probing
    The original hash function should just use the modulus operator to find the position
    key mod size
     
    If there is a collision, use quadratic probing to find the next open spot
     
    The hash table has a load factor of .5
    This should be stored as a constant variable
     
    If the load for the hash table meets or exceeds this value, increase the size of the array and rehash everything.
    The new size is the smallest prime number greater than double the old size.
    For example, if the size were 20, double the size to 40 and then find the next prime number (41)
     
    Create a print function to display the hash table
    Use this to verify that the keys were inserted in the proper place.
    When printing the hash table, print a space between values and print an underscore if the element has no value
    Create a main function to test the hash table
     
    Ask the user for the number of values to be entered
    Enter all the values and display the final hash table
     
     */
    
    array<int,11> table;
    table.fill(0);
    
    cout << table. << endl;
    
    return 0;
    
}
