class LRUCache {
public:
    
    list<int> dll;
    unordered_map<int,pair<list<int>:: iterator , int >> mp ; //key -> Add,Val
    int n;

    LRUCache(int capacity) {
       n =  capacity;
    }
    
    int get(int key) {
        
        //exit
        if(mp.find(key) != mp.end()){
           
           auto add = mp[key].first;
           dll.erase(add);
           dll.push_front(key);
           mp[key].first = dll.begin();
           return mp[key].second; //value corrospoding the key i am returning
        }

        //not exit
        return -1;
    }
    
    void put(int key, int value) {
        
        //alredy exit
        if(mp.find(key) != mp.end()){

            auto add = mp[key].first;
            dll.erase(add);
            dll.push_front(key);
            mp[key] = {dll.begin() , value};
        }
        else if(n >= 0){
            dll.push_front(key);
            mp[key] = {dll.begin() , value};
            n--;
        }

        if(n < 0){
            int LRU = dll.back();
            dll.pop_back();
            mp.erase(LRU);
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */