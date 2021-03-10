// https://www.nowcoder.com/practice/e016ad9b7f0b45048c58a9f27ba618bf?tpId=190&rp=1&ru=%2Factivity%2Foj&qru=%2Fta%2Fjob-code-high-rd%2Fquestion-ranking
/*
* search kth number
[1,3,5,2,2],5,3
返回：2
*/

// 此处排成一个从大到小的数组，而非从小到大。每次找下标pos，与k-1值比较。比k-1大更新右值，否则更新左值。
class Finder {
public:
    int findKth(vector<int> nums, int n, int k) {
        // write code here
        int left = 0, right = nums.size() - 1;
        
        while (true)
        {
            int pos = portition(nums, left, right);
            if (pos == k - 1) return nums[pos];
            if (pos > k - 1) right = pos - 1;
            else left = pos + 1;
        }
    }

    // divide partition, pass nums by reference
    int portition(vector<int>& nums, int left, int right)
    {
        int pivot = nums[left], l = left + 1, r = right;
        while(l <= r)
        {
            if (pivot > nums[l] && pivot < nums[r])
            {
                swap(nums[l++], nums[r--]);
            }
            if (pivot <= nums[l]) l++;
            if (pivot >= nums[r]) r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }
};

// version 2, full sort by quickSort, return nums[n - k].
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int l = 0, r = nums.size() - 1;
        quickSort(nums, l, r);
        
        return nums[nums.size() - k];
    }
            
    void quickSort(vector<int>& nums, int l, int r)
    {
        if (l >= r) return;
        
        int mid = paitition(nums, l, r);
        quickSort(nums, l, mid - 1);
        quickSort(nums, mid + 1, r);
    }
    
    int paitition(vector<int>& nums, int l, int r)
    {
        int tmp = nums[l];
        
        while (l < r)
        {
            while (l < r && tmp <= nums[r]) --r;
            if (l < r && tmp > nums[r]) swap(nums[l++], nums[r]);
            
            while (l < r && tmp >= nums[l]) ++l;
            if (l < r && tmp < nums[l]) swap(nums[l], nums[r--]); 
        }
        
        nums[l] = tmp;
        return l; // find pivot index
    }
};









