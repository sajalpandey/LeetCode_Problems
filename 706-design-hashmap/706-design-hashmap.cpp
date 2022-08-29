class MyHashMap {
public:
    vector<list<pair<int,int>>> map;
    int size;
    MyHashMap() {
        size = 100;
        map.resize(size);
    }
    int hashFun(int key){
        return key%size;
    }
    list<pair<int,int>> :: iterator search(int key){
        int bucket = hashFun(key);
        list<pair<int,int>> :: iterator it = map[bucket].begin();
        while(it!=map[bucket].end()){
            if(it->first == key)
                return it;
            it++;
        }
        return it;
    }
    void put(int key, int value) {
        int bucket = hashFun(key);
        //if present then we need to update so 
        //removing first and then adding
        remove(key);
        map[bucket].push_back({key,value});
    }
    
    int get(int key) {
        int bucket = hashFun(key);
        list<pair<int,int>> :: iterator it;
        it = search(key);
        if(it==map[bucket].end()) return -1;
        else
        return it->second;
    }
    
    void remove(int key) {
        int bucket = hashFun(key);
        list<pair<int,int>> :: iterator it;
        it = search(key);
        if(it==map[bucket].end()) return;
        map[bucket].erase(it);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */