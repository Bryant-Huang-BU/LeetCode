class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return 1;
        }
        vector<int> numsRep;
        //swap(nums, 0, 2); test statement for swap
        numsRep.push_back(nums[0]);
        int max = nums[0];
        for (int i = 1; i < nums.size(); i++) { //we're given the first num by default
            if (nums[i] > max) {
                max = nums[i];
                numsRep.push_back(nums[i]);
            }
        }
        nums = numsRep;
        return numsRep.size();
    }
    /*
    void swap (vector<int>& nums, int i, int j) {
        int swp;
        swp = nums[i];
        nums[i] = nums[j];
        nums[j] = swp;
    }*/
};
//TEST FUNCTION


/*int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}*/

