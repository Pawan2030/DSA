class LRUCache {
public:
    
    int n;
    list<int> dll;
    unordered_map<int , pair<list<int> :: iterator , int>> mp;

    LRUCache(int capacity) {
       n = capacity;
    }
    
    int get(int key) {

        if(mp.find(key) != mp.end()){

            auto address = mp[key].first;
            dll.erase(address);
            dll.push_front(key);
            mp[key].first = dll.begin();
            return mp[key].second;
        }
        return -1;
    }
    
    void put(int key, int value) {

        if(mp.find(key) != mp.end()){
           
           auto address = mp[key].first;
           dll.erase(address);
           dll.push_front(key);
           mp[key] = {dll.begin() , value};
        }
        else if(n >= 0){

            dll.push_front(key);
            mp[key] = {dll.begin() , value};
            //n--;
        }

        if(dll.size() > n){

            int LRU = dll.back();
            dll.pop_back();
            mp.erase(LRU);
           // n++;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */