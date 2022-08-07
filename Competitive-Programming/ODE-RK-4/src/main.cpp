#include <iostream>
using namespace std;

/* ODE using Runge Kutta Fourth Order / RK-4 Algorithm
 * 
 * Pseudocode:
 * 1) Start
 * 2) Define function, f(x, y); dy/dx = (y^2 - x^2) / (y^2 + x^2)
 * 3) Read values of initial condition (x0 and y0),
 *                   number of steps (n), and
 *                   calculation point (xn)
 *    - with initial condition y = 1 for x = 0, thus trying to evaluate
 *      the problem at y = 0.6 in three steps (n = 3)
 * 4) Calculate step size, h = (xn - x0) / b
 * 5) Set i = 0
 * 6) Loop
 *    - k1 = h * f(x0, y0)
 *    - k2 = h * f(x0 + h/2, y0 + k1/2)
 *    - k3 = h * f(x0 + h/2, y0 + k2/2)
 *    - k4 = h * f(x0 + h, y0 + k3)
 *    - k  = (k1 + 2*k2 + 2*k3 + k4) / 6
 *    - yn = y0 + k
 *    - i += 1
 *
 *    - x0 += h
 *    - y0 = yn
 *    While (i < n)
 * 7) display yn as result
 * 8) stop
 */

#define F(x, y) (y*y - x*x)/(y*y + x*x)

void rkfourth(float x0, float y0, float xn, int n);

int main()
{
  float x0, y0, xn;
  int n;

  cout << "Initial condition: " << endl;
  x0 = 0;
  y0 = 1;
  xn = 0.6;
  n = 3;
  cout << "x0: "   << x0
       << "\ny0: " << y0
       << "\nCalculation point xn: " << xn
       << "\nNumber of steps n: "    << n  << endl;

  // RK-4 Algorithm
  rkfourth(x0, y0, xn, n);
  return 0;
}

void rkfourth(float x0, float y0, float xn, int n)
{
  float h, k1, k2, k3, k4, k, yn;
  cout << "xo\ty0\tyn" << endl;
  cout << "------------------------" << endl;
  h = (xn - x0)/n;
  for (int i = 0; i < n; ++i)
  {
    k1 = h * (F(x0, y0));
    k2 = h * (F((x0 + h/2), (y0 + k1/2)));
    k3 = h * (F((x0 + h/2), (y0 + k2/2)));
    k4 = h * (F((x0 + h),   (y0 + k3  )));
    k  = (k1 + 2*k2 + 2*k3 + k4)/6;
    yn = y0 + k;

    cout << x0 << "\t" << y0 << "\t" << yn << endl;

    x0 += h;
    y0 = yn;
  }
  cout << "\nValue of y at x: " << xn 
       << " is " << yn << endl;
}