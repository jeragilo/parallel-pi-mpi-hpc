// C++ code to implement computation of pi
#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;
 
// Function to calculate PI
long double calcPI(long double PI, long double n, long double sign, long double iterations)
{
    // Add for (iterations) 
    for (unsigned long int i = 0; i <= iterations; i++) {
        PI = PI + (sign * (4 / ((n) * (n + 1) * (n + 2))));
        // Add and sub
        // alt sequences
        sign = sign * (-1);
        // Increment by 2 according to Nilkantha’s formula
        n += 2;
    }
 
    // Return the value of Pi
    return PI;
}
 
// main
int main(int argc, char** argv)
{
    // Initialise variables, require/accept passed-in value 
    auto start = std::chrono::steady_clock::now();  // set timer
    long double PI = 3, n = 2, sign = 1;
    const long double PI25DT = 3.141592653589793238462643383; // set test value for error
    long double cPI = 0.0;
    
    if (argc==1)
    {
      printf("You must pass a single numeric value\n");
      printf("the value should be 100M or higher\n");
      return -1;
    }

    long double iterations = std::stod(argv[1]); // set to passed-in numeric value
    cPI = calcPI(PI, n, sign, iterations);
    // Function call
    printf("PI is approx %.50Lf, Error is %.50Lf\n", cPI, fabsl(cPI - PI25DT));
    auto end = std::chrono::steady_clock::now(); // end timer
    auto diff = end - start; // compute time
    std::cout << std::chrono::duration<double, std::milli>(diff).count() << " Runtime ms" << std::endl;
    return 0;
}

