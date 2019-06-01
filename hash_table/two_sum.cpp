class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        unordered_map<int, int> duplicate;
        vector<int> result;
        int index = 0;
        int remain = 0;
        //Insert nums elements into hashmap
        for (auto it = nums.begin() ; it != nums.end() ; ++it){
            if (hashmap.count(*it) > 0){
                duplicate.insert(make_pair(*it,index));
            }
            else{
                hashmap.insert(make_pair(*it,index));
            }
            index++;
        }
        index = 0;
        for (auto it = nums.begin() ; it != nums.end() ; ++it){
            remain = target - nums.at(index);
            cout << "Remain: " << remain << endl;
            auto it_hashmap = hashmap.find(remain);
            if (it_hashmap == hashmap.end() || (it_hashmap->second == index && duplicate.find(remain) == duplicate.end())){
                cout << "No value found!" << endl;
                index++;
            }
            //Value found in hashmap
            else{
                //No duplicate found
                auto it = hashmap.find(remain);
                result.push_back(index);
                if (duplicate.find(remain) == duplicate.end()){
                    result.push_back(it->second);
                    break;               
                }
                //Duplicate found
                else{
                    result.push_back((duplicate.find(remain))->second);
                    break;     
                }
            }
        }
        return result;
    }
};
