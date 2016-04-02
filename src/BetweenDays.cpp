/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};
int between_days(struct node *date1head, struct node *date2head)
{
	if ((date1head == NULL) || (date2head == NULL))
		return NULL;
	int i = 0,dd=0,mm=0,yy=0,count=0,dd1,mm1,yy1,dd1,mm1,yy1;
	long int n1, n2;
	struct node *t,*t1;
	t = date1head;
	t1 = date2head;
	while ((t != NULL) && (count<2))
	{
		dd = (dd * 10) + t->data;
		count++;
	}
	while ((t != NULL) && (count<4))
	{
		mm = (mm * 10) + t->data;
		count++;
	}
	while (t != NULL)
		yy = (yy * 10) + t->data;
	count = 0;
	while ((t1 != NULL) && (count<2))
	{
		dd1 = (dd1 * 10) + t->data;
		count++;
	}
	while ((t1 != NULL) && (count<4))
	{
		mm1 = (mm1 * 10) + t->data;
		count++;
	}
	while (t1 != NULL)
		yy1 = (yy1 * 10) + t->data;
	//form 2 numbers and reverse the 2 numbers and subtract n1 and n2
	return -1;
}