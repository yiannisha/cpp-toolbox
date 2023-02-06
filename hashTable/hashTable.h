#include <vector>
#include <utility>
#include <string>

template <typename K, typename V>
using list = std::vector<std::pair<K, V> >;

template <typename K, typename V>
class HashTable {
public:
    HashTable ( int size = 20 );
    HashTable ( const HashTable &h );

    /**
     * Value of element `key`.
     * 
     * @param key of value to get, must be a int, char or string
     * 
     * @throws runtime_error if key does not exist.
     * 
     * @return value that matches `key`
    */
    V operator[] ( const K &key );

    /**
     * Add element in hashmap.
     * 
     * @param key element's key
     * @param value element's value
     * 
     * @return true if element is added successfully, false otherwise
    */
    bool add ( K key, V value );

    /**
     * Debug hash function.
     * 
     * @param key to pass to hash function.
     * 
     * @return whatever the hash function returns
    */
    // int getHash ( K key );

private:

    /**
     * Hash function.
     * 
     * @param key element's key
     * 
     * @return `key`'s hash
    */
    int hash ( int key );
    int hash ( char key );
    int hash ( std::string key );

    list<K, V> *array;
    int size;

};
