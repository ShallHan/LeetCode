class Item
{
public:
    int k;
    int v;
    Item(int key, int val):k(key), v(val){} 
};

class LRUCache{
public:
    LRUCache(int capacity): m_capacity(capacity) { }
    
    int get(int key) {
        if(m_map.count(key))
        {
            moveToFront(key);
            return m_map[key]->v;
        }
        else
            return -1;
    }
    
    void set(int key, int value) {
        if(!m_map.count(key))
        {
            if(m_list.size() >= m_capacity)
            {
                m_map.erase(m_list.back().k);
                m_list.pop_back();
            }
            Item item(key, value);
            m_list.push_front(item);
            m_map[key] = m_list.begin();
        }
        else
        {
            moveToFront(key);
            m_map[key]->v = value;
        }
    }
private:
    unordered_map<int, list<Item>::iterator> m_map;
    list<Item> m_list;
    int m_capacity;
    void moveToFront(int key)
    {
        Item item = *m_map[key];
        m_list.erase(m_map[key]);
        m_list.push_front(item);
        m_map[key] = m_list.begin();
    }
};
