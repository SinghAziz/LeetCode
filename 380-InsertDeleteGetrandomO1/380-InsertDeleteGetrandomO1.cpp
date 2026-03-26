// Last updated: 27/03/2026, 01:37:38
class RandomizedSet {
public:
    vector<int> s;
    unordered_map<int , int> mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (mp.count(val))return false;
        else {
            s.push_back(val); 
            mp[val] = s.size()-1;
            return true;
        }
    }
    
    bool remove(int val) {
        if (mp.count(val)){
            int index = mp[val];
            int last = s.back();

            s[index] = last;
            mp[last] = index;
            mp.erase(val);
            s.pop_back();
            return true;
        }
        else return false;
    }
    
    int getRandom() {
        int index = rand() % (s.size());
        return s[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */