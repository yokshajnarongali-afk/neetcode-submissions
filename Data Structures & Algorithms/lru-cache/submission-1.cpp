class LRUCache {
public:

  struct Node 
    {
        int key , val ;
        Node* next ;
        Node* prev ;

        Node (int k , int v)
        {
            key = k ;
            val = v ;
            prev = next = NULL ;
        }
    } ;
   
    int capacity ;
    unordered_map<int , Node*> m ;
    Node* head ;
    Node* tail ;

    LRUCache(int capacity) {
        this -> capacity = capacity ;
        head = new Node (0 , 0) ;
        tail = new Node (0 , 0) ;
        head -> next = tail ;
        tail -> prev = head ;
    }
    
    void remove (Node* node)
    {
        node -> prev -> next = node -> next ;
        node -> next -> prev = node -> prev ;
    }

    void insert (Node* node)
    {
        node -> next = tail ;
        node -> prev = tail -> prev ;
        tail -> prev -> next = node ;
        tail -> prev = node ;
    }

    int get(int key) {
           if (m.find (key) == m.end ())
        {
            return -1 ;
        }
        Node* node = m[key] ; 
        remove (node) ;
        insert (node) ;

        return node -> val ;
    }
    
    void put(int key, int value) {
         if (m.find (key) != m.end ())
        {
            Node* node1 = m[key] ;
            node1 -> val = value ;
            remove (node1) ;
            insert (node1) ;
        }
        else
        {
            if (m.size () == capacity)
            {
                Node* lru = head -> next ;
                remove (lru) ;
                m.erase (lru -> key) ;
            }
            Node* node = new Node(key, value);
            insert(node);
            m[key] = node;
        }

    }
};
