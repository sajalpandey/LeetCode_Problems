class LRUCache {
public:
    unordered_map<int, int> elements;
    unordered_map<int, list<int>:: iterator> address;
    list<int> doublyList;
    int capacity, size;
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
    }
    int get(int key) {
        //Case when element doesn't exists
        if(elements.find(key)==elements.end()) return -1;
        
        //Case when ele is present so we delete and insert this element to front
        list<int>:: iterator it = address[key];
        doublyList.erase(it);
        address.erase(key);
        //insertion at front
        doublyList.push_front(key);
        address[key] = doublyList.begin();
        //return corresponding value
        return elements[key];
    }
    
    void put(int key, int value) {
        //if the key is present in map then update
        if(elements.find(key)!=elements.end()){
            elements[key] = value;
            doublyList.erase(address[key]);
            address.erase(key);
            size--;
        }
        //when cache size if equal to capacity then remove the LRU element
        if(size == capacity){
            int key = doublyList.back();
            doublyList.pop_back();
            address.erase(key);
            elements.erase(key);
            size--;
        }
        //insertion
        size++;
        doublyList.push_front(key);
        address[key] = doublyList.begin();
        elements[key] = value;
    }
};
/*
Solution
Need a doubly linked list to add/remove element in O(1)
Need a map to store key --> address to it can be removed easily
Need a map to store key --> value pair so it can be checked if present or not
*/
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */