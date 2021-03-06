/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	if(len<0||Arr==NULL)
		return NULL;
	else
	{
		Arr = (int *)realloc(Arr,(len + 1)*sizeof(int));
		int i, j;
		len = len + 1;
		if (num <=Arr[0])
		{
			for (i = 0; i < len-1; i++)
				*(Arr+i + 1) =*(Arr+i);
			j = 0;
			Arr[j] = num;
			return Arr;
		}
		else if (num>= Arr[len - 2])
		{
			Arr[len - 1] = num;
			return Arr;
		}
		else
		{  
			for (i = 1; i < len - 1; i++)
				if (num>=Arr[i - 1] && num < Arr[i])
					break;
			j = i;
			for (i; i < len; i++)
				Arr[i + 1] = Arr[i];
			Arr[j] = num;
			return Arr;
		}
	}
}