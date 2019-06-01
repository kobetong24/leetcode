class Solution {
    
public:
    vector<int> result;
    typedef struct{
        int val;
        bool flag = false;
    } element_struct;
    element_struct hashmap[MAX_EL];
    
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        for (int i = 0 ; i < MAX_EL ; i++){
            hashmap[i].val = -1;
        }
        
        for (auto it = nums1.begin() ; it != nums1.end() ; ++it){
            hashmap[*it % MAX_EL].val = *it;
        }
        for (auto it = nums2.begin() ; it != nums2.end() ; ++it){
            if (*it == hashmap[*it % MAX_EL].val && hashmap[*it % MAX_EL].flag == false){
                hashmap[*it % MAX_EL].flag = true;
                cout << *it << endl;
                result.push_back((int)(*it));
            }
        }
        return result;
    }
};
