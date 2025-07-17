// Maximum consecutive ones: 3

#include <iostream>
#include <vector>
using namespace std;


// BRUTE FORCE APPROACH -> TC = O(N^2) SC = O(1)
int maxConsecutiveOnesBruteForce(vector<int>& nums, int k) {
    int maxLength = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        int count = 0, zeroCount = 0;
        for(int j = i; j < nums.size(); j++)
        {
            if(nums[j] == 1)
            {
                count++;
            }
            else
            {
                zeroCount++;
            }
            if(zeroCount <= k)
            {
                maxLength = max(maxLength, count);
            }
            else
            {
                break;
            }
        }
    }
    return maxLength;
}


// BETTER APPROACH   -> TC = O(2N) SC = O(1)
int maxConsecutiveOnesBetter(vector<int>& nums, int k) {
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


// OPTIMAL APPROACH -> TC = O(N) SC = O(1)

int maxConsecutiveOnesOptimal(vector<int>& nums, int k) {
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
            if(zeroCount > k)    // HERE IS THE OPTIMIZATION
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
            else
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
    cout << "Maximum consecutive ones: " << maxConsecutiveOnesBetter(nums, k) << endl;
    cout << "Maximum consecutive ones (Brute Force): " << maxConsecutiveOnesBruteForce(nums, k) << endl;
    cout << "Maximum consecutive ones (Optimal): " << maxConsecutiveOnesOptimal(nums, k) << endl;
    return 0;

}