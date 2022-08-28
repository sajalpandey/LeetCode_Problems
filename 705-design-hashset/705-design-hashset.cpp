class MyHashSet {
public:
    vector<list<int>> hashSet;
    int size;
    MyHashSet() {
        size = 100;
        hashSet.resize(size);
    }
    int hashFun(int k){
        return (k%size);
    }
    list<int> :: iterator search(int key){
        int bucket = hashFun(key);
        return find(hashSet[bucket].begin(),hashSet[bucket].end(),key);
    }
    void add(int key) {
        if(contains(key) == true) return;
        int bucket = hashFun(key);
        hashSet[bucket].push_back(key);
    }
    
    void remove(int key) {
        if(contains(key) == false) return;
        int bucket = hashFun(key);
        hashSet[bucket].erase(search(key));
    }
    
    bool contains(int key) {
        int bucket = hashFun(key);
        if(search(key) != hashSet[bucket].end())
            return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */