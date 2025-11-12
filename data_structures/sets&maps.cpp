#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <iostream>
using namespace std;

void bucketLoad()
{
    unordered_set<int> s;
    for (int i = 0; i < 100; i++)
    {
        s.insert(i);
        cout << "size=" << s.size()
                  << " buckets=" << s.bucket_count()
                  << " load=" << s.load_factor() << endl;
    }
}

void unorderedVsOrdered()
{
    set<int> s = {5, 3, 9};
    unordered_set<int> us = {5, 3, 9};
    map<int, string> m = {{5, "a"}, {3, "b"}, {9, "c"}};
    unordered_map<int, string> um = {{5, "a"}, {3, "b"}, {9, "c"}};

    cout << "set: ";
    for (int x : s)
        cout << x << " "; // sorted
    cout << "\nunordered_set: ";
    for (int x : us)
        cout << x << " "; // hash order

    cout << "\nmap: ";
    for (auto &p : m)
        cout << "(" << p.first << "," << p.second << ") ";
    cout << "\nunordered_map: ";
    for (auto &p : um)
        cout << "(" << p.first << "," << p.second << ") ";
}

int main(int argc, char const *argv[])
{
    // bucketLoad();
    unorderedVsOrdered();
    return 0;
}
