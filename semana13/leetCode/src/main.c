#include <stdio.h>
#include <stdlib.h>

/* Problema > Achar o elemento majoritário, com complexidade de tempo linear e de espaço O(1)
O elemento majoritário é o elemento que aparece mais ⌊n / 2⌋vezes. Você pode supor que o elemento majoritário sempre existe na matriz.
*/

/* //Esse eu fiz primeiro, mas a complexidade dele ta muito alta pro requisito do exercicio
int majorityElement (int* nums, int numsSize) {
	int *count = (int *) calloc (4,numsSize);

	for (int i = 0; i < numsSize; i++) {
		for (int j = i+1; j < numsSize; j++){
			if (nums[i] == nums [j]){
				count[i] += 1;
			}
		}
	}

	int times = count [0], major = 0;

	for (int i = 0; i < numsSize; i++) {
		if (count[i] > times){
			times = count[i];
			major = i;
		}
	}

	printf("\nMajor Number = %d, %d times",nums[major],times+1);

	free (count);
	return nums[major];
}
*/

//E este tem uma complexidade linear em seu melhor caso
int majorityElement (int* nums, int numsSize) {
	int times = 1;
    
    if (numsSize == 1)
        return nums[0];

	for (int i = 0; i < numsSize; i++) {
		if (i>0 && nums[i] == nums[i-1]) continue;
		for (int j = i+1; j < numsSize; j++){
			if (nums[i] == nums [j])
				times++;
			if (times > numsSize/2)
				return nums[i];
		}
	}
	return 0;
}

int main(int argc, int *argv []) {
	printf ("%d , %s",argc,argv[1]);
	int nums [3] = {5,5,6};

	//printf("\n%d",majorityElement(nums,3));
}