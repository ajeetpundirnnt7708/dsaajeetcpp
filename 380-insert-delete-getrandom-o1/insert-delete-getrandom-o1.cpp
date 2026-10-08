class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> valToIndex;

public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (valToIndex.count(val)) {
            return false;
        }
        nums.push_back(val);
        valToIndex[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (!valToIndex.count(val)) {
            return false;
        }
        int lastVal = nums.back();
        int idxToReplace = valToIndex[val];
        
        nums[idxToReplace] = lastVal;
        valToIndex[lastVal] = idxToReplace;
        
        nums.pop_back();
        valToIndex.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};