class Node {
   public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int k, int v) {
        this->key = k;
        this->val = v;
        prev = NULL;
        next = NULL;
    }
};
class LRUCache {
    int cap;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;
    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }
    void insert(Node* node) {
        Node* prev = tail->prev;
        prev->next = node;
        node->prev = prev;
        node->next = tail;
        tail->prev = node;
    }

   public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.count(key)) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            remove(cache[key]);
        }
        Node* newnode = new Node(key, value);
        cache[key] = newnode;
        insert(newnode);
        if (cache.size() > cap) {
            Node* lru = head->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
