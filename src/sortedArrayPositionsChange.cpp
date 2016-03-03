/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	int i, j,a=0,b=0, count1 = 0, count2 = 0;
	if (len<2||Arr==NULL)
		return NULL;
	if (*(Arr+0) > *(Arr+1)){
		count1 = 1;
		a = 0;
	}
	if (*(Arr+len - 1) < *(Arr+len - 2)){
		b= len - 1;
		count2 = 1;
	}
	if (count1 == 0){
		for (i = 1; i < len - 1; i++){
			if (*(Arr+i) > *(Arr+i + 1)) {
				count1 = 1;
				a = i;
				break;
			}
		}
	}
	if (count2 == 0)
	{
		for (j = i + 1; j < len - 1; j++)
			if (*(Arr+j)>*(Arr+j + 1))
			{
				b = j + 1;
				count2 = 1;
				break;
			}
	}
	if (count2 == 0){
		count2 = 1;
		b = a + 1;
	}
	if (count1 == 1 && count2 == 1){
		int temp = 0;
		temp = *(Arr+a);
		*(Arr+a) = *(Arr+b);
		*(Arr+b) = temp;
	}
}