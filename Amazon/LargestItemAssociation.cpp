//   In order to improve customer experience, Amazon has developed a system to provide recommendations to the customer regarding the item they can purchase. Based on historical customer purchase information, an item association can be defined as - If an item A is ordered by a customer, then item B is also likely to be ordered by the same customer (e.g. Book 1 is frequently orderered with Book 2). All items that are linked together by an item association can be considered to be in the same group. An item without any association to any other item can be considered to be in its own item association group of size 1.

// Given a list of item association relationships(i.e. group of items likely to be ordered together), write an algorithm that outputs the largest item association group. If two groups have the same number of items then select the group which contains the item that appears first in lexicographic order.

// Input
// The itput to the function/method consists of an argument - itemAssociation, a list containing paris of string representing the items that are ordered together.

// Output
// Return a list of strings representing the largest association group sorted lexicographically.

// Example
// Input:
// itemAssociation: [
// [Item1, Item2],
// [Item3, Item4],
// [Item4, Item5]
// ]

// Output:
// [Item3, Item4, Item5]

// Explanation:
// There are two item association groups:
// group1: [Item1, Item2]
// group2: [Item3,Item4,Item5]
// In the available associations, group2 has the largest association. So, the output is [Item3, Item4, Item5]. 


  //C++ DFS method 1
    #include<iostream>
    #include<vector>
    #include<unordered_set>
    #include<map>
    #include<queue>

    
    using namespace std;

    void dodfs(string s,unordered_map<string,vector<string>> &g,map<string,int> &m,vector<string> &out){
            m[s] =0;
            out.push_back(s);
            for(auto a: g[s]){
                if(m[a]) dodfs(a,g,m,out);
            }
    }
    
    
    
    vector<string> getLargestItem(vector<vector<string>> &list){
        unordered_map<string,vector<string>> graph;
        map<string,int> m;
        for(auto a:list){
            graph[a[0]].push_back(a[1]);
            graph[a[1]].push_back(a[0]);
            m[a[0]]++;
            m[a[1]]++;
        }
        queue<string> q;
        vector<string> res;
        int maxi =0;
        for(auto &a : m){
            if(a.second){
                vector<string> out;
                dodfs(a.first,graph,m,out);
                if(out.size() > maxi){
                    res =out;
                    maxi = out.size();
                }
            }
        }

        return res;

    }

     int main() {
         vector<vector<string>> list {{"item1","item2"},{"item1","item6"},{"item4","item5"}};
         vector<string> res = getLargestItem(list);
         for(auto a: res){
             cout<<a<<endl;
         }
         return 0;
    }


//C++ BFS
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <queue>
#include <sstream>

using namespace std;

vector<string> getLargestItem(vector<vector<string>> &list){
    unordered_map<string,vector<string>> graph;
    map<string,int> m;
    for(auto a:list){
        graph[a[0]].push_back(a[1]);
        graph[a[1]].push_back(a[0]);
        m[a[0]]++;
        m[a[1]]++;
    }
    queue<string> q;
    vector<string> res;
    int maxi =0;
    for(auto &a : m){
        if(a.second){
            q.push(a.first);
        }
        vector<string> out;
        while(!q.empty()){
            string p = q.front();
            q.pop();
            out.push_back(p);
            if(out.size() > maxi){
                res =out;
                maxi = out.size();
            }
            m[p] =0;
            for(auto s: graph[p]){
                if(m[s]) q.push(s);
            }

        }
    }

    return res;

}


 int main() {
     vector<vector<string>> list {{"item1","item2"},{"item1","item6"},{"item4","item5"}};
     vector<string> res = getLargestItem(list);
     for(auto a: res){
         cout<<a<<endl;
     }
     return 0;
}
