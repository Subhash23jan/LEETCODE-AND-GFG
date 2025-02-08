#include <unordered_map>
#include <set>

class NumberContainers
{
    unordered_map<int, int> ind;
    unordered_map<int, set < int>> mp;

    public:
        NumberContainers() {}

    void change(int index, int number)
    {
        if (ind.count(index))
        {
            if (ind[index] == number) return;
            mp[ind[index]].erase(index);
            if (mp[ind[index]].empty()) mp.erase(ind[index]);
        }
        mp[number].insert(index);
        ind[index] = number;
    }

    int find(int number)
    {
        if (!mp.count(number) || mp[number].empty()) return -1;
        return *mp[number].begin();
    }
};