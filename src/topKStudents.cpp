/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include <iostream>
#include <malloc.h>
void numswap(int *n1, int *n2);
void charswap(char *s1,char *s2);
struct student {
	char *name;
	int score;
};
struct student ** topKStudents(struct student *students, int len, int K) {
	if (K<1||students==NULL||len<=0)
	    return NULL;
	if (len < K)
		K = len;
	struct student **r = (struct student **)malloc(sizeof(struct student)*K);
	int i,j;
	for (i = 0; i < K; i++)
		r[i] = (struct student *)malloc(sizeof(struct student));
		for (i = 0; i < len - 1; i++)
		{
			for (j = 0; j < len - i - 1; j++){
				if (((students + j)->score) < ((students + j + 1)->score))
				{
					numswap(&((students + j)->score), &((students + j + 1)->score));
					charswap(((students + i)->name), ((students + i + 1)->name));
				}
			}
		}
		for (i = 0; i < K; i++){
			r[i]->score = (students + i)->score;
			r[i]->name = (students + i)->name;
		}
		return r;
}
void numswap(int *n1, int *n2){
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}
void charswap(char *s1, char *s2){
	char *temp = s1;
	s1 = s2;
	s2 = temp;
}