#pragma once
#include<iostream>
#include<string>
#include<optional>
using namespace std;


template <typename T>
struct Item {
    int hash;
    T value;

    Item(int hash, T value) {
        Item::hash = hash;
        Item::value = value;
    }

    Item() {}

};
template <typename T>
struct ItemList {
    Item<T> values[10];
    int right = -1;

    Item<T> getItem(int ind) {
        return values[ind];
    }

    int getSize() {
        return right + 1;
    }

    void add(Item<T> v) {
        right++;
        values[right] = v;
    }


};
template <typename T>
struct HashTable {
    int n = 10;
    int k = 7;
    ItemList<T> table[10] = {};

    int hash(string key) {
        int r = 0;
        for (int i = 0; i < key.length(); i++) {
            r += int(key[i]) * (i + 1);
        }

        return r;
    }

    optional<T>  getValue(string key) {
        int h = hash(key);
        int ind = h % k;

        for (int i = 0; i < table[ind].getSize(); i++) {
            Item<T> v = table[ind].getItem(i);
            if (v.hash == h) {
                return v.value;
            }
        }

        return {};
    }

    void add(string key, T value) {
        int h = hash(key);
        int ind = h % k;
        table[ind].add(Item<T>(h, value));
    }
};

