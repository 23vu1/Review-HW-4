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
    void remove(int key);
    void resize();
    bool search(int key);
    void print();
    int nextPrime(int n);
    bool isPrime(int n);
};

Hash_Table::Hash_Table(){
    max_size = 11; // The initial size of the array will be 11
    size = 0;
    table = new int[max_size];
    for(int i = 0; i < max_size; i++){
        table[i] = 0;
    }
}

Hash_Table::~Hash_Table(){
    delete [] table;
}

void Hash_Table::insert(int key){
    if( (size+1) > ((0.5) * max_size)){
        // cout << "Hash table is >= 0.5 Load, Expanding. Current: " << max_size << endl;
        // max_size = max_size * 2;
        // max_size = nextPrime(max_size);
        // cout << "NextPrime: " << max_size << endl;
        resize();
    }
    int index = key % max_size;
    int i = 0;
    while(table[index] != 0){
        index = (index + i*i) % max_size;
        i++;
    }
    table[index] = key;
    size++;
}

void Hash_Table::remove(int key){
    if(size == 0){
        cout << "Hash table is empty" << endl;
        return;
    }
    int index = key % max_size;
    int i = 0;
    while(table[index] != key){
        index = (index + i*i) % max_size;
        i++;
    }
    table[index] = 0;
    size--;
}

void Hash_Table::resize(){
    int old_size = max_size;
    max_size = max_size * 2;
    max_size = nextPrime(max_size);
    int *temp = new int[max_size];
    for(int i = 0; i < max_size; i++){
        temp[i] = 0;
    }
    for(int i = 0; i < old_size; i++){
        if(table[i] != 0){
            int index = table[i] % max_size;
            int j = 0;
            while(temp[index] != 0){
                index = (index + j*j) % max_size;
                j++;
            }
            temp[index] = table[i];
        }
    }
    delete [] table;
    table = temp;
}

void Hash_Table::print(){
    for(int i = 0; i < max_size; i++){
        if(table[i] == 0){
            cout << "_" << " ";
        }
        else{
            cout << table[i] << " ";
        }
    }
    cout << endl;
}

int Hash_Table::nextPrime(int n)
{
    // Base case
    if (n <= 1)
        return 2;
 
    int prime = n;
    bool found = false;
 
    // Loop continuously until isPrime returns
    // true for a number greater than n
    while (!found) {
        prime++;
        if (isPrime(prime))
            found = true;
    }

    return prime;
}

bool Hash_Table::isPrime(int n)
{
    // Corner cases
    if (n <= 1)  return false;
    if (n <= 3)  return true;
   
    // This is checked so that we can skip 
    // middle five numbers in below loop
    if (n%2 == 0 || n%3 == 0) return false;
   
    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;
   
    return true;
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

    for(int i = 0; i < values; i++){ // Enter all the values and display the final hash table
        cout << "Enter Value: ";
        cin >> value;
        hash_table.insert(value);
    }
    hash_table.print();

    return 0;
    
}
