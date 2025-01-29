class LRUCache {
public:
    
    int n;
    list<int> dll;
    unordered_map<int,pair<list<int> :: iterator , int >> mp;  // key -> ADD , Val

    LRUCache(int capacity) {
       n = capacity;
    }
    
    int get(int key) {
        
        //present so return val of that input key
        if(mp.find(key) != mp.end()){

            auto it = mp[key].first;
            int val = mp[key].second;
            dll.erase(it);
            dll.push_front(key);
            mp[key] = {dll.begin() , val};
            return mp[key].second;
        }

        //not present
        return -1;
    }
    
    void put(int key, int value) {

        //alredy presnt with this key - val so make it most freq used and update in map
        if(mp.find(key) != mp.end()){

            auto it = mp[key].first;
            dll.erase(it);
            dll.push_front(key);
            mp[key] = {dll.begin() , value};
        }
        else if(mp.size() == n){ // remove least and add new
            
            auto it = dll.back();
            dll.pop_back();
            mp.erase(it);

            dll.push_front(key);
            mp[key] = {dll.begin() , value};
        }
        else{
            dll.push_front(key);
            mp[key] = {dll.begin() , value};
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */