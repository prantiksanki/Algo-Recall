// Maximum consecutive ones: 3

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int maxConsecutiveOnes(vector<int>& nums, int k) {
    int left = 0, right = 0, maxLength = 0, zeroCount = 0;

    while(right < nums.size())
    {
        if(nums[right] == 0)
        {
            zeroCount++;
        }
        if(zeroCount <= k)
        {
            maxLength = max(maxLength, right - left + 1);

        }
        else
        {
            while(zeroCount > k)
            {
                if(nums[left] == 0)
                {
                    zeroCount--;
                }
                left++;
            }
        }
        right++;
    }
    return maxLength;
}

int main()
{
    vector<int> nums = {1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1};
    int k = 2;
    cout << "Maximum consecutive ones: " << maxConsecutiveOnes(nums, k) << endl;
    return 0;

}