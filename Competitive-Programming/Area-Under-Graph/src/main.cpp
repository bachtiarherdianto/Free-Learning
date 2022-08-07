/* Monte Carlo for Finding Out Area Under Graph
 * 
 * Demo program for integrating a function using Monte Carlo method
 * function is f(x) = cos(x)                                       */
#include <iostream>
#include <cmath>


int count;
float total, area;

float funct(float x) {return exp(cos(x));}

class Solution
{
	int MAX_ITER = 1000000;
public:
	void solved(float (*funct)(float), 
		        float xmin, 
		        float xmax, 
		        float ymin, 
		        float ymax)
	{
		for (int i = 0; i < MAX_ITER; ++i)
		{
			float u1 = (float)rand()/(float)RAND_MAX;
			float u2 = (float)rand()/(float)RAND_MAX;

			float xcoord = ((xmax - xmin)*u1) + xmin;
			float ycoord = ((ymax - ymin)*u2) + ymin;

			float val = funct(xcoord);

			total++;

			if (val > ycoord) {area++;}
		}
		
		float density = area/total;
		std::cout << (xmax - xmin)*(ymax - ymin)*density << std::endl;
	}
};

int main()
{
	Solution MonteCarlo;

	MonteCarlo.solved(funct, -2, 2, 0, 4);
	return 0;
}