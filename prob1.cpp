/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Note: This could be done in single pass as well. See editorial.

*/


#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>

using std::vector;
using std::map;

vector<int> twoSum(vector<int>& nums, int target)
{
	map<int,int> numMap;
	int count = 0;

	for(auto n : nums) {
		numMap.insert(std::pair<int,int>(n, count));
		count++;
	}

	count=0;
	vector<int> result;
	for(auto n : nums) {
		int sec = target - n;
		if(numMap.find(sec) != numMap.end()) {
			if(numMap[sec] != count) {
				result.push_back(count);
				result.push_back(numMap[sec]);
				return result;
			}	
		}
		count++;	
	}
	return result;
}

int main()
{
vector<int> nums;

nums.push_back(2);	
nums.push_back(7);
nums.push_back(11);
nums.push_back(15);

twoSum(nums, 9);

return 0;
}
