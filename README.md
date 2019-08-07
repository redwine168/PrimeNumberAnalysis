# Jonathan Redwine
# PrimeNumberAnalysis

This console application examines various algorithms for determining the primality of an integer.  The application allows the user to select which algorithm they would like to use to generate an input number of primes.  The program then creates a .txt file containing the time it takes to generate n primes, where 1 < n < the number input by the user, according to the selected algorithm.  For example, if the user enters 10, the .txt file would contain
	- the time it takes to generate 1 prime
	- the time it takes to generate 2 primes
	- the time it takes to generate 3 primes
			......
	- the time it takes to generate 10 primes.

The algorithms to determine the primality of an integer N are as follows:

Brute Force Method
- iterates through integers n, such that 1 < n < N/2, to see if n is a factor of N.  If no n is a factor of N, then N is prime.

Smart Brute Force Method
- iterates through all the prime numbers already generated, seeing if each one is a factor of N.  This relies on the fact that you need only check prime numbers, as checking composite numbers if redundant.

Fermat Primality Test
- This algorithm involves choosing an integer k that is coprime to N, and calculating k^(N-1) mod N.  If this is equal to 1, then N is usually prime (there exists prime numbers that break this rule).  However, due to integers in C++ having an integer maximum size of 32 bits, this algorithm does not scale well in the current implementation.

Included in the repo is a MATLAB file for displaying the generated data, two example .txt files, and the figure created from the MATLAB code.


To compile and run the program, enter the following commands at the terminal:

g++ -0 main main.cpp
./main