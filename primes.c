#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include <time.h>

int main(void)
{
	float top;
	clock_t t;
	int max, num, topInt;
	printf("Please enter highest number to which to search:  ");
	scanf("%f", &top);
	topInt = top;
	printf("You entered %0.0f.\n", top);
	max = ceil(sqrt(top));
	
	printf("This will run through %d, the floor of the square root of %0.0f.\n", max, top);
	int *nums = malloc(topInt * sizeof(int)); /*Prevents the dreded SEGMENTATION FAULT*/
	t = clock();
	for(num = 0; num <= topInt + 1; num ++)
	{  /* build the array of numbers*/
		nums[num] = num;
	}
	nums[1] = 0; /*eliminate 1 and 2*/
	nums[2] = 0;
	int chk;
	for(int zed = 2; zed <= max; zed ++)
	{
		chk = zed;
		do
		{
		   if(nums[chk] % zed == 0 && nums[chk] != zed) /*set composit numbers to zero*/
		      nums[chk] = 0;
		   chk++;
		}while(chk <= top);
	}
	t = clock() - t;
	for(int x = 0; x <= top; x++)
	{
		if(nums[x] != 0)
			printf("%d is prime\n", nums[x]);
	}
	free(nums); /*Free up that memory space*/
	double timeTaken = ((double)t) / CLOCKS_PER_SEC;
	printf("That took %0.2f seconds\n", timeTaken); 
}
