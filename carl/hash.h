#include <vector>
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include<bits/stdc++.h>

using namespace std;

class Hash {
public:
    // 242. 有效的字母异位词
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        vector count(26, 0);
        for (int i = 0; i < s.length(); ++i) {
            count[s[i] - 'a']++;
        }
        for (int i = 0; i < s.length(); ++i) {
            count[t[i] - 'a']--;
            if (count[t[i] - 'a'] < 0) return false;
        }
        return true;
    }

    // 349. 两个数组的交集
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> result; // 存储两个数组的重合结果
        unordered_set<int> hash(nums1.begin(), nums1.end()); // 第一个数组转化为set

        for (int i = 0; i < nums2.size(); ++i) {
            if (hash.find(nums2[i]) != hash.end()) result.insert(nums2[i]); // 查找重合元素，加入result
        }

        return vector<int>(result.begin(), result.end()); // 转化为vector返回
    }

    // 202. 快乐数
    bool isHappy(int n) {
        unordered_set<int> set;
        while (n != 1) {
            int sum = 0;
            while (n != 0) {
                int temp = n % 10;
                n /= 10;
                sum += temp * temp;
            }
            if (set.find(sum) != set.end()) return false;
            set.insert(sum);
            n = sum;
        }
        return true;
    }

    // 1. 两数之和
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            auto iter = map.find(target - nums[i]);
            if (iter != map.end()) {
                // first 表示 key
                // second 表示 value
                return {iter->second, i};
            }
            map.emplace(nums[i], i);
        }
        return {};
    }

    // 454. 四数相加 II
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        unordered_map<int, int> map;
        for (int i: nums1) {
            for (int j: nums2) {
                map[i + j]++;
            }
        }
        int count = 0;
        for (int i: nums3) {
            for (int j: nums4) {
                auto iter = map.find(-i - j);
                if (iter != map.end()) {
                    count += iter->second;
                }
            }
        }
        return count;
    }

    // 383. 赎金信
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> arr(26, 0);
        for (auto i: magazine) {
            arr[i - 'a']++;
        }
        for (auto i: ransomNote) {
            arr[i - 'a']--;
        }
        for (int i: arr) {
            if (i < 0) {
                return false;
            }
        }
        return true;
    }

    // 15. 三数之和
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> arr;
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    arr.push_back({nums[i], nums[left], nums[right]});
                    // 这里要先判断大小 再对比值
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return arr;
    }

    // 18. 四数之和
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> arr;
        if (nums.size() < 4) {
            return arr;
        }
        sort(nums.begin(), nums.end());
        int length = nums.size();
        for (int i = 0; i < length - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < length - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int left = j + 1, right = length - 1;
                while (left < right) {
                    long sum = (long) nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        arr.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        left++;
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return arr;
    }

};