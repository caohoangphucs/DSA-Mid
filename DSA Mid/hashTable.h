#pragma once
#include <iostream>
#include <string>
#include <optional>
//#include <stdexcept> 

using namespace std;

template <typename T>
struct Item {
    int hash;
    string key;
    T value;

    Item(int hash, string key, T value) {
        Item::hash = hash;
        Item::key = key;
        Item::value = value;
    }

    Item() : hash(0), value(T{}) {}
};

template <typename T>
struct ItemList {
    Item<T> values[10];
    int right = -1;

    Item<T> getItem(int ind) {
        if (ind < 0 || ind > right) {
            throw out_of_range("getItem(): index is out of range");
        }
        return values[ind];
    }

    int getSize() {
        return right + 1;
    }

    void add(Item<T> v) {
        if (right >= 9) {
            throw overflow_error("add(): list is full");
        }
        right++;
        values[right] = v;
    }

    void clear() {
        right = -1;
    }

    void removeAt(int ind) {
        if (ind < 0 || ind > right) {
            throw out_of_range("removeAt(): index is out of range");
        }
        for (int i = ind; i < right; i++) {
            values[i] = values[i + 1];
        }
        right--;
    }
};

template <typename T>
struct HashTable {
    int n = 10;
    int k = 7;
    ItemList<T> table[10] = {};

    int hash(string key) {
        if (key.empty()) {
            throw invalid_argument("hash(): key cannot be empty");
        }
        int r = 0;
        for (int i = 0; i < key.length(); i++) {
            r += int(key[i]) * (i + 1);
        }
        return r;
    }

    optional<T> getValue(string key) {
        int h = hash(key);
        int ind = h % k;

        for (int i = table[ind].getSize() - 1; i >= 0; i--) {
            Item<T> v = table[ind].getItem(i);
            if (v.hash == h && v.key == key) {
                return v.value;
            }
        }

        // not found
        return {};
    }

    void clear() {
        for (int i = 0; i < k; i++) {
            table[i].clear();
        }
    }

    void add(string key, T value) {
        int h = hash(key);
        int ind = h % k;

        if (table[ind].getSize() >= 10) {
            throw overflow_error("add(): bucket is full");
        }

        table[ind].add(Item<T>(h, key, value));
    }

    void print() {
        for (int i = 0; i < k; i++) {
            cout << "Bucket " << i << ": ";
            for (int j = 0; j < table[i].getSize(); j++) {
                cout << "(" << table[i].values[j].key << ", "
                    << table[i].values[j].value << ") ";
            }
            cout << endl;
        }
    }

    void remove(string key) {
        int h = hash(key);
        int ind = h % k;

        for (int i = 0; i < table[ind].getSize(); i++) {
            if (table[ind].values[i].hash == h && table[ind].values[i].key == key) {
                T val = table[ind].values[i].value;
                table[ind].removeAt(i);
                return;
            }
        }

        throw runtime_error("remove(): key not found");
    }

    optional<string> getKey(T value) {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < table[i].getSize(); j++) {
                if (table[i].values[j].value == value) {
                    return table[i].values[j].key;
                }
            }
        }
        return {};
    }
};
