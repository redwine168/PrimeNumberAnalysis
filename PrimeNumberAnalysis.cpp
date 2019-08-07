// Jonathan Redwine
// CS 566 - Analysis of Algorithms
// Final Project
// Copyright 2019

//#include "pch.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <time.h>
#include <fstream>
using namespace std;




// Class for managing the array of integers for the custom method
// The Method includes removing all multiples of an integer x
// when we determine that N is not divided by x
class IntManager {
private:
	int* arr;
	int nMax;
	int nElem;
	void removeMultiples(int x);
public:
	IntManager() { nMax = 0; arr = NULL; }
	IntManager(int s);
	~IntManager();
	void showContents();
	bool isPrime();
};


// Constructor method
IntManager::IntManager(int n) {
	nMax = n;
	nElem = (int)(nMax / 2);
	arr = new int[nElem];
	for (int i = nElem - 1; i >= 0; i--) {
		*(arr + i) = i + 1;
	}
}


// Destructor method
IntManager::~IntManager() {
	delete[] arr;
}


// Prints the contents of the IntManager
void IntManager::showContents() {
	for (int i = 0; i < nElem; i++) {
		cout << *(arr + i) << endl;
	}
}


// Removes the multiples of x from the IntManager
void IntManager::removeMultiples(int x) {
	int numMultiples = ((int)nElem / (x + 1));
	for (int i = 0; i < numMultiples; i++) {
		*(arr + x + (i*(x + 1))) = -1;
	}
}


bool IntManager::isPrime() {
	for (int i = 1; i < nElem - 1; i++) {
		if (*(arr + i) != -1) {
			if (nMax % *(arr + i) == 0) {
				return false;
			}
			else {
				removeMultiples(i);
			}
		}
	}
	return true;
}


// Custom method for finding primes
// Accepts parameter for number of primes to find, returns pointer to array storing the found primes
int* generatePrimesCustomMethod(int numPrimes) {
	int *arr = new int[numPrimes];
	int primesFound = 0;
	int currNumber = 2; // start at 2
	while (primesFound < numPrimes) {
		IntManager manager = IntManager(currNumber);
		if (manager.isPrime()) {
			*(arr + primesFound) = currNumber;
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
	uint64_t x;
	while (primesFound < numPrimes) {
		x = (uint64_t)(pow(2, currNumber - 1)) % (currNumber);
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
		cout << "- Custom Method (C)" << endl;
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
			case 'c': case 'C': {
				cout << "Enter the max number of primes to find (greater than or equal to 1)" << endl;
				cin >> max;
				if (!cin.eof() && cin.good()) {
					if (max > 0) {
						ofstream file;
						file.open("customMethod.txt");
						clock_t start;
						double duration;
						for (int i = 1; i <= max; i++) {
							start = clock();
							generatePrimesCustomMethod(i);
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