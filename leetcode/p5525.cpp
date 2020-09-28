#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class ThroneInheritance {
public:
    unordered_map<string,vector<string>> a;
    string king;
    vector<string> deathlist;
    ThroneInheritance(string kingName) {
        king = kingName;
        vector<string> temp;
        a[kingName] = temp;
    }
    
    void birth(string parentName, string childName) {
        a[parentName].push_back(childName);
    }
    
    void death(string name) {
        a[name].push_back("");
    }

    void dfs(vector<string>& order, string currName) {
        order.push_back(currName);
        if (a[currName].size() > 0 && a[currName][a[currName].size()-1] == "")
            order.pop_back();
        for (auto name : a[currName]) {
            if (name != "")
                dfs(order, name);
        }
    }

    vector<string> getInheritanceOrder() {
        vector<string> order;
        dfs(order, king);
        return order;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */