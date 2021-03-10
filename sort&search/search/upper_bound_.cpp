// https://www.nowcoder.com/practice/7bc4a1c7c371425d9faa9d1b511fe193?tpId=190&rp=1&ru=%2Factivity%2Foj&qru=%2Fta%2Fjob-code-high-rd%2Fquestion-ranking

/*
请实现有重复数字的有序数组的二分查找。
输出在数组中第一个大于等于查找值的位置，如果数组中不存在这样的数，则输出数组长度加一。
*/

class Solution {
public:
    /**
     * 二分查找
     * @param n int整型 数组长度
     * @param v int整型 查找值
     * @param a int整型vector 有序数组
     * @return int整型
     */
    int upper_bound_(int n, int v, vector<int>& a) {
        // write code here        
        if (a[n-1] < v) return n + 1;
        int left = 0;
        int right = n - 1;
        // 注意这里的pos变量一定要加上，不然找不到具体的下标位置. 因为mid更新后可能是(a[mid] < v)的情况,这时候更新左指针并且大于右指针，跳出循环，上一步的pos值才能表示真正的下标位置
        int mid, pos = 0;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (a[mid] >= v)
            {
                right = mid - 1;
                pos = mid;
            }
            else if (a[mid] < v)
            {
                left = mid + 1;
            }
        }
        return pos + 1;
    }
};
