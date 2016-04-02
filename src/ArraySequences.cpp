/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int * find_sequences(int *arr, int len)
{
	//Return final array which has 6indexes [AP1_S,AP1_E,AP2_S,AP2_E,GP1_S,GP2_E]
	if ((arr == NULL) || (len <= 0))
		return NULL;
	int i = 0, j, k, l = 0, *res, flag1 = 0, flag2 = 0, flag4 = 0, flag5 = 0, temp, count = 0, count2 = 0;
	float sum;
	res = (int *)malloc((len + 2)*sizeof(int));
	while (i < len - 2)
	{
		while (1)
		{
			j = i + 1;
			k = j + 1;
			if (k > len)
				break;
			sum = (arr[i] + arr[k]) / 2.0;
			if (arr[j] == sum)
			{
				flag1 = 1;
				count++;
			}
			else
				break;
			if (count == 1)
				temp = i;
			i++;
		}
		if (flag1 == 1)
		{
			res[l] = temp;
			l++;
			res[l] = k - 1;
			l++;
			i = k - 2;
		}
		count = 0;
		while (1)
		{
			j = i + 1;
			k = j + 1;
			if (k > len)
				break;
			if ((arr[j] * arr[j]) == (arr[i] * arr[k]))
			{
				flag2 = 1;
				count++;
			}
			else
				break;
			if (count == 1)
				temp = i;
			i++;
		}
		if (flag2 == 1)
		{
			res[4] = temp;
			res[5] = k - 1;
			i = k - 2;
		}
		if ((flag1 != 1) && (flag2 != 1))
			i++;
		count = 0;
		flag2 = 0;
		flag1 = 0;
		count2++;
	}
	res[6] = '\0';
	return res;
}