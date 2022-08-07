#include <iostream>
#include <cmath>
using namespace std;

/* ODE using Euler's Method Algorithm
 * 
 * Pseudocode:
 * 1) Start
 * 2) Define function, f(x, y); dy/dx = x + y
 * 3) Read values of initial condition (x0 and y0),
 *                   number of steps (n), and
 *                   calculation point (xn)
 * 4) Calculate step size, h = (xn - x0) / b
 * 5) Set i = 0
 * 6) Loop
 *    - yn += h * (x0 + i * h, y0)
 *    - y0 = yn1
 *    - i += 1
 *    While (i < n)
 * 7) display yn as result
 * 8) stop
 */

#define F(x, y) (x + y)

void euler(float x0, float y0, float xn, int n);

int main()
{
  float x0, y0, xn, h, yn, slope;
  int i, n;

  cout << "Initial Condition: " << endl;
  x0 = 0;
  y0 = 1; 
  xn = 0.5;
  n = 10;
  cout << "x0: "   << x0
       << "\ny0: " << y0
       << "\nCalculation point, xn: " << xn
       << "\nNumber of steps, n: "    << n  << endl;

  // Drawn result table
  cout << "\nx0\ty0\tslope\tyn"               << endl;
  cout << "---------------------------------" << endl;

  // Calculate the number
  euler(x0, y0, xn, n);
  return 0;
}

void euler(float x0, float y0, float xn, int n)
{
  float h, yn, slope;
  int i;
  h = (xn - x0) / n;
  for (int i = 0; i < n; ++i)
  {
    slope = F(x0, y0);
    yn = y0 + h * slope;

    cout << x0 << "\t" << y0 << "\t" << slope << "\t" << yn << endl;

    y0 = yn;
    x0 = x0 + h;
  }
  cout << "\nValue of y at x: " << xn << " is " << yn << endl;
}