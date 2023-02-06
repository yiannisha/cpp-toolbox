#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include "hashTable.h"

template <typename K, typename V>
using hashPair = std::pair<K, V>;
template <typename K, typename V>
using hashList = std::vector<hashPair<K, V> >;

template <typename K, typename V>
HashTable<K, V>::HashTable ( int size ) {
    array = new hashList<K, V>[size];
}

template <typename K, typename V>
V HashTable<K, V>::operator[] ( const K &key ) {
    int hash = HashTable<K, V>::hash(key);
    hashList<K, V> l = array[hash];

    for (int i=0; i<l.size(); i++) {
        if (l[i].first == key) {
            return l[i].second;
        }
    }

    throw std::runtime_error("Can't find element with this key.");
}

template <typename K, typename V>
bool HashTable<K, V>::add ( K key, V value ) {
    try {
        hashPair<K, V> pair;
        pair.first = key;
        pair.second = value;

        int hash = HashTable::hash(key);
        
        array[hash].push_back(pair);

        return true;
    }
    catch (std::exception) {
        return false;
    }
}

template <typename K, typename V>
int HashTable<K, V>::hash ( int key ) {
    return key % 20;
}

template <typename K, typename V>
int HashTable<K, V>::hash ( char key ) {
    return (char)key % 20;
}

template <typename K, typename V>
int HashTable<K, V>::hash ( std::string key ) {
    int sum;
    for (int i=0; i<key.length(); i++) {
        sum += (int)key[i];
    }

    return sum % 20;
}

// template <typename K, typename V>
// int HashTable<K, V>::getHash ( K key ) {
//     return HashTable::hash(key);
// }
