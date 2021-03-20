#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std; 


struct Point 
{
	int x;
	int y;
};

//Functions

	//Calculates the distance between two Point structs
	//Pre, Function requires two Point struct
	//Post, Function will return the distance between the two struct points 
int calculateDistance (Point* a, Point* b)
{
	int distance;
	
	//Formula used: distance = (x1-x2) + (y1-y2)
	distance = ( (a->x - b->x) + ( a->y - b->y) );
			
	return distance;
}

	//print function to display the results
	//Pre, Requires two Point Structs 
	//Post, outputs to screen two Point information and distance
void printResult( Point* a, Point* b)
{
	int result;
	
	result = calculateDistance(a, b);
	
	cout<< "(" << a->x << ","<< a->y<< ")"; 
	cout<< "           "<<"(" << b->x << ","<< b->y<< ")"; 
	cout<< "           "<< result<< endl; 
	
}

	//function randomly sets x and y value for Point structs
	//Pre, Requires two Point Structs and range value  
	//Post, initializes x and y for Point structs 	
void setPoint (Point* a, Point* b, int range)
{
		a->x = (1 + (rand() % range ) ) - range; 
		a->y = (1 + (rand() % range ) ) - range;
		
		b->x = (1 + (rand() % range ) ) - range;
		b->y = (1 + (rand() % range ) ) - range;
}

	//Function call other functions to auto a test instance
	//sets value for x and y for points, finds distance, prints results 
	//Pre, Requires two Point structs, int range, and int testCase
	//Post, Display information of x and y value for points and distance
void callManhattan (Point* a, Point* b, int range, int testCase)
{	
	cout<<"Point A (x,y)"<< "   Point B (x,y)"<< "   Distance between A and B"<< endl;
	
	for (int x = 0; x <= testCase; ++x)
	{	
		setPoint (a, b, range);
		printResult(a, b);	
	}
}

int main ()
{
	//Randam number genarator set to time
	srand(time(0));
	
	//range of data to test
	int range = 10;
	
	//number of test cases
	int testCase = 2; 
	
	//initializing Structs, Point a and Point b
	Point a, b;
	
	callManhattan (&a, &b, range, testCase);	
	
		
return 0;	
}