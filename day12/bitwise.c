int singleNonDuplicate(int* nums, int numsSize){
int x=nums[0],i;
for(i=1;i<numsSize;i++)
{
x=x^nums[i];
}
return x;
}