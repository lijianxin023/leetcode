/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class LRUCache {
public:
//fisrt AC 2020.03.30 Time#23.66% Memory#100%
    struct listnode{
        int key;
        int val;
        listnode *pre,*next;
        listnode(int k, int v):key(k),val(v),pre(NULL),next(NULL){};
    };

    LRUCache(int capacity) {
        num = 0;
        cap = capacity;
        head = new listnode(0,0);
        tail = new listnode(0,0);
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if(m.count(key)==0)
            return -1;
        puthead(m[key]);
        return m[key]->val;
    }
    
    void put(int key, int value) {
        if(m.count(key)==0){
            if(num<cap)
                ++num;
            else deletenode();
            addval(key,value); 
        }
        else{
            listnode* node = m[key];
            node->val = value;
            puthead(node);
        }
    }

    void puthead(listnode *node) {
        if(node->pre == head)
            return;
        node->next->pre = node->pre;
        node->pre->next = node->next;
        node->next = head->next;
        node->pre = head;
        head->next->pre = node;
        head->next = node;
    }
    void addval(int key, int val) {
        listnode* node = new listnode(key,val);
        m.insert(make_pair(key,node));
        node->next = head->next;
        node->pre = head;
        head->next->pre = node;
        head->next = node;
    }
    void deletenode(){
        listnode* node = tail->pre;
        node->pre->next = tail;
        tail->pre = node->pre;
        m.erase(node->key);
        delete(node);
    }

private:
    int num;
    int cap;
    listnode *head,*tail;
    unordered_map<int, listnode*> m;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

