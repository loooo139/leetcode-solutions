/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 */
class NumArray_BIT
{
public:
    NumArray(vector<int> &nums)
    {
        data.resize(nums.size());
        bit.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++)
            update(i, nums[i]);
    }

    void update(int i, int val)
    {
        int diff = val - data[i];
        for (int j = i + 1; j < bit.size(); j += (j & -j))
        {
            bit[j] += diff;
        }
        data[i] = val;
    }

    int sumRange(int i, int j)
    {
        return getSum(j + 1) - getSum(i);
    }
    /**
     * @brief  
     * @note   
     * @param  i: 
     * @retval
     * @return 返回前i-1个数字的和，并不是i个数字 
     */
    int getSum(int i)
    {
        int res = 0;
        for (int j = i; j > 0; j -= (j & -j))
            res += bit[j];
        return res;
    }

private:
    vector<int> data, bit;
};
class NumArray
{
private:
	vector<int>data;
public:
	NumArray(vector<int>&nums) {
		data.resize(nums.size() * 2);
		int n = nums.size();
		for (int i = 0; i<nums.size(); i++)
			update(i, nums[i]);


	};
	void update(int i, int val) {
		int n = data.size() / 2;
		int diff = -data[i + n] + val;
		for ( i = i + n; i>0; i /= 2)
			data[i] += diff;
	};
	int sumRange(int i, int j) {
		int n = data.size() / 2, res = 0;
		for ( i+=n,j+=n; i <= j; i /= 2, j /= 2) {
			if ((i & 1)==1)res += data[i++];
			if (j%2==0)res += data[j--];
		}
		return res;
	}
};



/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
