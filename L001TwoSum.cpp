#include <stdio.h>
#include <vector>
#include <map>
#include <iterator>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> m;
        if (nums.size() < 2) {
        	return result;
		}
		for (int i = 0; i < nums.size(); i++) {
			m[nums[i]] = i;
		}
		map<int, int>::iterator it;
		for (int i = 0; i < nums.size(); i++) {
			if ((it = m.find(target - nums[i])) != m.end()) {
				if (i == it->second) continue;
				result.push_back(i);
				result.push_back(it->second);
				return result;
			}
		}
		return result;
    }
};

int main() {
	Solution s;
	int numbers[4] = {2, 7, 11, 15};
	vector<int> nums(numbers, numbers + 4);
	vector<int> res = s.twoSum(nums, 9);
	printf("%d %d\n", res[0], res[1]);
	return 0;
}
