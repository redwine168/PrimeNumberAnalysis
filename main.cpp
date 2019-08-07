// Jonathan Redwine
// Prime Number Analysis
// Copyright 2019

//#include "pch.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <time.h>
#include <fstream>
using namespace std;




bool checkPrime(int *primes, int primesFound, int currNumber) {
    for (int i = 0; i < primesFound; i++) {
        if (currNumber % *(primes+i) == 0) {
            return false;
        }
    }
    return true;
}


// Smart brute force method for finding primes
// Accepts parameter for number of primes to find, returns pointer to array storing the found primes
int* generatePrimesSmartBruteForce(int numPrimes) {
    int *arr = new int[numPrimes];
    int primesFound = 0;
    int currNumber = 2; // start at 2
    while (primesFound < numPrimes) {
        if (checkPrime(arr, primesFound, currNumber)) {
            *(arr+primesFound) = currNumber;
            primesFound += 1;
        }
        currNumber += 1;
    }
    return arr;
}



// Brute Force method for finding primes
// Accepts parameter for number of primes to find, returns pointer to array storing the found primes
int* generatePrimesBruteForce(int numPrimes) {
    int* arr = new int[numPrimes];
    int primesFound = 0;
    int currNumber = 2; // start at 2
    while (primesFound < numPrimes) { // go until we've found the number of primes specified
        int i = 2;
        while (currNumber % i != 0) { // go until we find a number greater than 1 that divides into currNumber
            i++;
        }
        if (i == currNumber) { // if this number is currNumber, it is prime
            *(arr + primesFound) = currNumber;
            primesFound += 1; // add it, count it
        }
        currNumber += 1;
    }
    return arr;
}


// Fermat Primality Method for finding primes
// // Accepts parameter for number of primes to find, returns pointer to array storing the found primes
int* generatePrimesFermat(int numPrimes) {
    int* arr = new int[numPrimes];
    int primesFound = 1;
    int currNumber = 3; // for simplicity, for this method we will just put 2 into the array and begin with 3
    *arr = 2;
    int x;
    while (primesFound < numPrimes) {
        x = (int)(pow(2, currNumber - 1)) % (currNumber);
        if (x == 1) {
            *(arr + primesFound) = currNumber;
            primesFound += 1;
        }
        currNumber += 2; // we will iterate by 2 since we only want to look at odd numbers
    }
    return arr;
}






int main(int argc, const char * argv[]) {
    std::cout << std::fixed;
    std::cout << std::setprecision(3);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);
    cout << "Welcome to the Prime Number Center.  How many prime numbers should be generated?" << endl;
    char selection = ' ';
    int max;
    while (!cin.eof() && selection != 'e' && selection != 'E') {
        // Present user with menu to select algorithm to test
        cout << "Which method would you like to test?" << endl;
        cout << "- Brute Force (B)" << endl;
        cout << "- Smart Brute Force (S)" << endl;
        cout << "- Fermat Primality Test (F)" << endl;
        cout << "- Exit (E)" << endl;
        cout << "Enter your operation: ";
        cin >> selection;
        if (!cin.eof() && selection != 'e' && selection != 'E') {
            switch (selection) {
                    // if Brute Force selected
                case 'b': case 'B': {
                    cout << "Enter the max number of primes to find (greater than or equal to 1)" << endl;
                    cin >> max;
                    if (!cin.eof() && cin.good()) {
                        if (max > 0) {
                            ofstream file;
                            file.open("bruteForce.txt");
                            clock_t start;
                            double duration;
                            for (int i = 1; i <= max; i++) {
                                start = clock();
                                generatePrimesBruteForce(i);
                                duration = (clock() - start) / (double)CLOCKS_PER_SEC;
                                file << i << "," << duration << "\n";
                            }
                        }
                    }
                    break;
                }
                    // If Smart Brute Force selected
                case 's': case 'S': {
                    cout << "Enter the max number of primes to find (greater than or equal to 1)" << endl;
                    cin >> max;
                    if (!cin.eof() && cin.good()) {
                        if (max > 0) {
                            ofstream file;
                            file.open("smartBruteForce.txt");
                            clock_t start;
                            double duration;
                            for (int i = 1; i <= max; i++) {
                                start = clock();
                                generatePrimesSmartBruteForce(i);
                                duration = (clock() - start) / (double)CLOCKS_PER_SEC;
                                file << i << "," << duration << "\n";
                            }
                        }
                    }
                    break;
                }
                    // If Fermat selected
                case 'f': case 'F': {
                    cout << "Enter the max number of primes to find (greater than or equal to 1)" << endl;
                    cin >> max;
                    if (!cin.eof() && cin.good()) {
                        if (max > 0) {
                            ofstream file;
                            file.open("fermatMethod.txt");
                            clock_t start;
                            double duration;
                            for (int i = 1; i <= max; i++) {
                                start = clock();
                                generatePrimesFermat(i);
                                duration = (clock() - start) / (double)CLOCKS_PER_SEC;
                                file << i << "," << duration << "\n";
                            }
                        }
                    }
                    break;
                }
                    // If exit selected
                case 'e': case 'E': {
                    break;
                }
                    // If invalid input
                default:
                { cout << "Invalid operation. Try again!" << endl;
                    cout << "Operations are " << endl;
                    cout << "- Brute Force (B)" << endl;
                    cout << "- Custom Method (C)" << endl;
                    cout << "- Fermat Primality Test (F)" << endl;
                    cout << "- Exit (E)" << endl;
                    cin.clear();  // clear cin bits and empty input buffer
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
            }
        }
    }
}
