// 001 Two Sum.cpp : Defines the entry point for the console application.
//

/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].



UPDATE (2016/2/13):
The return format had been changed to zero-based indices. Please read the above updated description carefully.
*/

#include "stdafx.h"
#include <stdlib.h>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	vector<unsigned int> twoSum(vector<int>& nums, int target)
	{
		map<int, unsigned int> m;
		for (unsigned int i = 0; i < nums.size(); i++)
		{
			m.insert(pair<int, unsigned int>(nums[i], i));
		}

		for (unsigned int i = 0; i < nums.size(); i++)
		{
			int x = target - nums[i];
			if ((m.find(x) != m.end()) && (m[x] != i))
			{
				return (vector<unsigned int>{i, m[x]});
			}
		}
	}
};

/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* twoSum(int* nums, int numsSize, int target)
{
	int *indices = (int *)malloc(2 * sizeof(int));

	for (int i = 0; i < numsSize; i++)
	{
		int x = target - nums[i];

		for (int j = i + 1; j < numsSize; j++)
		{
			if (x == nums[j])
			{
				indices[0] = i;
				indices[1] = j;

				return indices;
			}
		}
	}

	return NULL;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int nums[4] = { 2, 7, 11, 15 };

	int * indices = twoSum(nums, 4, 9);

	free(indices);

	Solution so;

	vector<int> nums2 = { 2, 7, 11, 15 };

	vector<unsigned int> v = so.twoSum(nums2, 9);

	return 0;
}
