#include <stdio.h>
#include <stdlib.h>

int search(int numbers[], int low, int high, int value) 
{
	if(low > high){
		return -1;//Value not found
	}


	int mid = (low + high) / 2;//Calculate the midpoint

	if(numbers[mid] == value){
		return mid;//Value found at the midpoint
	}
	else if (numbers[mid] < value) {
		//Value may be in the right half
		return search(numbers, mid + 1, high, value);
	}
	else {
		//Value may be in the left half
		return search(numbers, low, mid - 1, value);
	}
}

void printArray(int numbers[], int sz)//Calculate
{
	int i;
	printf("Number array : ");
	for (i = 0; i < sz; ++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		for (i = 0; i < countOfNums; i++)
		average = 0;
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
	return 0;
}