#include<vector>
#include<string>

struct HashNode
{
    std::string key;
    int value, best_buy, best_sell;
    struct HashNode* next;
    HashNode(std::string key, int value):key(key),value(value),next(NULL),best_buy(-__INT32_MAX__),best_sell(__INT32_MAX__){}  //constructor
};
struct hashMap{
    int numOfElements, capacity;                //number of elements and capacity of the hash map
    struct HashNode** arr;                          //base address array of the linked list

    hashMap(){
        numOfElements=0;
        capacity=50000;
        arr=new HashNode*[capacity];
        for(int i=0;i<capacity;i++)arr[i]=NULL;
    }
    int hashFunction(std::string key) {
        int bucketIndex;
        int sum = 0, factor = 31;
        for (int i = 0; i < key.length(); i++) {
            sum = ((sum % capacity) +((abs(abs((int)key[i]) * factor)) % capacity)) % capacity;
            factor = ((factor % __INT16_MAX__) * (31 % __INT16_MAX__)) % __INT16_MAX__;
        }
        bucketIndex = sum;
        return bucketIndex;
    }
    void insert( std::string key, int value) {
            int bucketIndex = hashFunction(key);
        HashNode* newHashNode=new HashNode(key,value);
        if (arr[bucketIndex] == NULL) {
            arr[bucketIndex] = newHashNode;
        }
        // Collision
        else {
            newHashNode->next = arr[bucketIndex];
            arr[bucketIndex] = newHashNode;
        }
    }
    HashNode* search( std::string key) {
        int bucketIndex = hashFunction(key);
        struct HashNode* bucketHead = arr[bucketIndex]; 
        while (bucketHead != NULL) {       
            // Key is found in the hashMap
            if (bucketHead->key==key) {
                return bucketHead;
            }     
            bucketHead = bucketHead->next;
        }
        return NULL;
    }
};
