class Solution {
public:
    bool isHappy(int n) {
        int result = 0;
        int ori_num = 0;
        while(result != 1){
            if (ori_num == 0){
                ori_num = n;}
            cout << "result: " << result << endl;
            while(ori_num > 0){
                result += pow((ori_num % 10),2);
                ori_num /= 10;
                cout << result << endl;
            }
            ori_num = result;
            if (result != 1)
                result = 0;
        }
    return true;
    }

};
