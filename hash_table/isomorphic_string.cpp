class Solution {
public:
    unordered_map<char,char> hashmap1;
    unordered_map<char,char> hashmap2;
    int index = 0;
    
    bool checkDuplicate(string* s, string* t,unordered_map<char,char>* hashmap){
        int index = 0;
        for (char& c : *s){
            //check duplicate
            if (hashmap->find(c) != hashmap->end()){
                //duplicate found
                auto it = hashmap->find(c);
                if (it->second != t->at(index)){
                    return false;
                }
            }
            else{
                //insert into hashmap
                hashmap->insert(make_pair(c,t->at(index)));
            }
            index++;
        }
        return true;
        
    }
    bool isIsomorphic(string s, string t) {
        if (!checkDuplicate(&s,&t,&hashmap1)){return false;}
        if (!checkDuplicate(&t,&s,&hashmap2)){return false;}
        return true;
    }
    
};
