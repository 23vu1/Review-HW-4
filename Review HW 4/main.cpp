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

    // Implement a simple hash table that uses quadratic probing     
    // You can use an array for the hash table
    // The array should hold integer values (the keys)

class Hash_Table{
private:
    int max_size;
    int size;
    int *table;

public:
    Hash_Table();
    ~Hash_Table();
    void insert(int key);
    void resize();
    void print();

    int nextPrime(int in);
    bool isPrime(int in);
};

Hash_Table::Hash_Table(){
    max_size = 11; // The initial size of the array will be 11
    size = 0;
    table = new int[max_size];
    for(int i = 0; i < max_size; i++){ // Default values for the array (0)
        table[i] = 0;
    }
}

Hash_Table::~Hash_Table(){
    delete [] table;
}

void Hash_Table::insert(int key){
    int index = key % max_size;
    
    if(table[index] == 0){ // If the index is empty, insert the key
        table[index] = key;
        size++;
    }
    else{
        int i = 1;
        while(table[(index + i*i) % max_size] != 0){ // Quadratic probing
            i++;
        }
        table[(index + i*i) % max_size] = key; // Insert the key at the next available index
        size++;
    }

    if( (size) >= ((0.5) * max_size) ){ // Resize when the load factor is greater than 0.5
        resize();
    }
}

void Hash_Table::resize(){
    int old_size = max_size;
    max_size = nextPrime(max_size * 2); // Double the size of the array
    int *temp = new int[max_size];

    for(int i = 0; i < max_size; i++){ // Default values for the array (0)
        temp[i] = 0;
    }
    for(int i = 0; i < old_size; i++){ // Rehash the values
        if(table[i] != 0){
            int index = table[i] % max_size;

            if(temp[index] == 0){ // If the index is empty, insert the value
                temp[index] = table[i];
            }
            else{ // If the index is not empty, find the next empty index
                int j = 1;
                while(temp[(index + j*j) % max_size] != 0){ // Quadratic probing
                    j++;
                }
                temp[(index + j*j) % max_size] = table[i]; // Insert the value at the next available index
            }
        }
    }
    delete [] table; // Delete the old array
    table = temp; // Set the new array to the old array
}

void Hash_Table::print(){
    for(int i = 0; i < max_size; i++){ // Print the values in the array
        if(table[i] == 0){ // If the value is 0, print an underscore
            cout << "_" << " "; 
        }
        else{ // If the value is not 0, print the value
            cout << table[i] << " ";
        }
    }
    cout << endl; // New line
}

int Hash_Table::nextPrime(int in)
{
    if (in <= 1){ // Base Case for n <= 1
        return 2;
    }
 
    int prime = in;
    bool found = false;
 
    while (!found) { // Loop until a prime number is found
        prime++;
        if (isPrime(prime)) 
            found = true;
    }

    return prime; // Return the prime number
}

bool Hash_Table::isPrime(int in)
{
    if (in <= 1)  return false; // 0, 1 are not prime
    if (in <= 3)  return true; // 2, 3 are prime
   
    if (in%2 == 0 || in%3 == 0){
        return false; // If n is divisible by 2 or 3, it is not prime
    }
   
    for (int i=5; i*i<=in; i=i+6){
        if (in%i == 0 || in%(i+2) == 0){
            return false; // If n is divisible by i or i+2, it is not prime
        }
    }
   
    return true; // If n has no divisors less than its square root, it is prime
}

int main() {
    
    /*
     
    The keys should be within the range of 100 - 999
     
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
     
    */

    int values = 0;
    int value = 0;

    Hash_Table hash_table;

    cout << "Enter Number of Values in Hash_Table: "; // Ask the user for the number of values to be entered
    cin >> values;

    // Case 1: 244 376 587 751 630
    // Case 2(B): 994 974 406 846 770
    // Case 2(A): 994 974 406 846 770 etc

    for(int i = 0; i < values; i++){ // Enter all the values and display the final hash table
        cout << "Enter Value: ";
        cin >> value;
        hash_table.insert(value); // Insert the value
    }

    hash_table.print(); // Print the hash table

    return 0; // End the program
}
