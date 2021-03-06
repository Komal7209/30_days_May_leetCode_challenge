class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {

        //moores voting algorithm
        int idx = 0;
        int count = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == nums[idx]) //idx is candidate
                count++;
            else
                count--;
            if (count == 0)
            {              //reset candidate
                idx = i;   // we reset new index to be the current index
                count = 1; // so that ir resets to original count
            }
        }

        return nums[idx]; // the candidate is returned
    }
}