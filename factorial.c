#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>



int main()
{	
	int n; //This is the integer that we need to calculate its factorial 
	scanf("%d",&n); //Ask the user
	int arr[1000] = {0}; //Initialize the array to hold 0
	
	arr[0] = 1; //This is the last digit
	int len = 1; //This is start of counting the number of integers
	
	//This is a nested loop. The trick is to use simple multiplication, really multiply one by one and store it in the array 
	for (int i = 2; i <= n; i++) 
	{
		int carry = 0; //The carry over value
		for (int j = 0; j < len; j++) 
		{
			int mul = i * arr[j] + carry; //The product of the 2 integers
			int dig = mul % 10; //This is the first integer, always in the ones place
			arr[j] = dig; //update array by inserting the integer
			carry = mul / 10; //This is the second integer, tens, hundreds or thousands place
		}
		
		//This is to take the remain carry to a higher order digit
		while (carry) 
		{
		   len++; //Increment counter
		   int dig = carry % 10; //This is to break up the integer from the product (e.g dig > 10)
		   arr[len - 1] = dig; //Insert value into array 
		   carry /= 10; //To place the first digit of the product
	}
	
	//Starts the with last value of the array and decrements to the first value of the array
	for (int i = len - 1; i >= 0; i--) 
	{
		printf("%d", arr[i]);
	}

	return 0;
}

