#include <vector>
#include <algorithm>
#include <cstdint>
#include <iostream>

using namespace std;

class Array {
public:
    // 704. 二分查找
    int search(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            }
        }
        return -1;
    }

    // 27. 移除元素
    int removeElement(vector<int> &nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }

    // 977. 有序数组的平方
    vector<int> sortedSquares(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] *= nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }

    // 209. 长度最小的子数组
    int minSubArrayLen(int target, vector<int> &nums) {
        int left = 0, right = 0;
        int sum = 0;
        int m = INT32_MAX;
        while (right < nums.size()) {
            sum += nums[right++];
            while (target <= sum) {
                m = min(m, right - left);
                sum -= nums[left++];
            }
        }
        return m == INT32_MAX ? 0 : m;
    }

    // 59. 螺旋矩阵 II
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> arr(n, vector<int>(n));
        int nn = n * n;
        int mark = 0;
        int x = 0, y = 0;
        int up = 0, down = n - 1, left = -1, right = n - 1;

        for (int i = 1; i <= nn; ++i) {
            arr[x][y] = i;
            if (x == up && y == left) {
                mark++;
                down--;
            } else if (x == up && y == right) {
                mark++;
                left++;
            } else if (x == down && y == left) {
                mark++;
                right--;
            } else if (x == down && y == right) {
                mark++;
                up++;
            }
            mark %= 4;
            switch (mark) {
                case 0:
                    y++;
                    break;
                case 1:
                    x++;
                    break;
                case 2:
                    y--;
                    break;
                case 3:
                    x--;
                    break;
            }
        }
        return arr;
    }

    // 卡码网 58. 区间和（第九期模拟笔试）
    void array1() {
        int n, a, b;
        cin >> n;
        int arr[n + 1];
        cin >> arr[0];
        for (int i = 1; i < n; ++i) {
            cin >> arr[i];
            arr[i] += arr[i - 1];
        }
        while (cin >> a >> b) {
            if (a == 0) {
                cout << arr[b] << endl;
            } else {
                cout << arr[b] - arr[a - 1] << endl;
            }
        }
    }

    // 卡码网 44. 开发商购买土地（第五期模拟cc笔试）
    void array2() {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        vector<int> nn(n), mm(m);
        int min_dif = INT32_MAX;
        int sum;
        for (int i = 0; i < n; ++i) {
            sum = 0;
            for (int j = 0; j < m; ++j) {
                cin >> arr[i][j];
                sum += arr[i][j];
            }
            nn[i] = sum;
            if (i != 0) nn[i] += nn[i - 1];
        }
        for (int i = 0; i < m; ++i) {
            sum = 0;
            for (int j = 0; j < n; ++j) {
                sum += arr[j][i];
            }
            mm[i] = sum;
            if (i != 0) mm[i] += mm[i - 1];
        }
        sum = nn[n - 1];

        for (int i = 0; i < n; ++i) {
            int temp = abs(sum - nn[i] - nn[i]);
            if (temp < min_dif) {
                min_dif = temp;
            }
        }
        for (int i = 0; i < m; ++i) {
            int temp = abs(sum - mm[i] - mm[i]);
            if (temp < min_dif) {
                min_dif = temp;
            }
        }
        cout << min_dif << endl;
    }
};