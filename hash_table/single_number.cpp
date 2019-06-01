class Solution {
public:
    int result = 0;
    int singleNumber(vector<int>& nums) {
        for (auto it = nums.begin() ; it != nums.end() ; ++it){
            result ^= (unsigned int)(*it);
            cout << result << endl;
        }
        return result;
    }
};
