// Input
// The input to the function/method consists of five arguments - numCompetitors, an integer representing the number of competitors for the Echo device;
// topNCompetitors, is an integer representing the maximum number of competitors that Amazon wants to identify;
// competitors, a list of strings representing the competitors;
// numReviews, an integer representing the number of reviews from different websites that are identified by the automated webcrawler;
// reviews, a list of string where each element is a string that consists of space-separated words representing user reviews.

// Output
// Return a list of strings representing Amazon's top N competitors in order of most frequently mentioned to least frequent.

// Note
// The comparison of strings is case-insensitive. If the value of topNCompetitors is more than the number of competitors discussed in the reviews then output the names of only the competitors mention.
// If competitors have the same count (e.g. newshop=2, shopnow=2, mymarket=4), sort alphabetically. topNCompetitors=2, Output=[mymarket, newshop]

// Example
// Input:
// numCompetitors=6
// topNCompetitors = 2
// competitors = [newshop, shopnow, afashion, fashionbeats, mymarket, tcellular]
// numReviews = 6
// reviews = [
// "newshop is providing good services in the city; everyone should use newshop",
// "best services by newshop",
// "fashionbeats has great services in the city",
// "I am proud to have fashionbeats",
// "mymarket has awesome services",
// "Thanks Newshop for the quick delivery"]

// Output
// ["newshop", "fashionbeats"]

// Explanation
// "newshop" is occurring in 3 different reviews. "fashionbeats" is occuring in 2 different user reviews and "mymarket" is occurring in only 1 review.



public List<string> TopNumCompetitors(int numCompetitors,
                                        int topNCompetitors,
                                        List<string> competitors,
                                        int numReviews, List<string> reviews)
{
	// Your code here
}

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <sstream>

using namespace std;

unordered_set<string> getSetValue(string &s){
    if(s.size() ==0) return {};
    unordered_set<string> revSet;
    stringstream ss(s);
    string word;
    while(ss>>word){
        transform(word.begin(),word.end(),word.begin(),::tolower);
        revSet.insert(word);
    }
    return revSet;

}
vector<string> TopNumCompetitors(int numCompetitors,int topNCompetitors,vector<string> competitors,vector<string> reviews){
    if(topNCompetitors == numCompetitors) return competitors;
    vector<unordered_set<string>> revSet;
    unordered_map<int,vector<string>> m;
    priority_queue<pair<int,vector<string>>> pq;
    vector<string> result;

    for(auto &r: reviews){
        unordered_set<string> s= getSetValue(r);
        revSet.push_back(s);
    }

    for(auto &c:competitors){
        transform(c.begin(),c.end(),c.begin(),::tolower);
        int count=0;
        for(auto a:revSet){
            if(a.find(c) != a.end()){
                count++;
            }
        }
        if(count >0) m[count].push_back(c);
    }

    for(auto p:m){
        sort(p.second.begin(),p.second.end());
        pq.push({p.first,p.second});
    }

    while(!pq.empty() && topNCompetitors){
        pair<int,vector<string>> q = pq.top();
        pq.pop();
        int len = q.second.size();
        for(int i=0;i<len && topNCompetitors ; i++){
            result.push_back(q.second[i]);
            topNCompetitors--;
        }
    }
    return result;

}


int main() {
    vector<string> reviews {"newshop is providing good services in the city; everyone should use newshop",
                            "best services by newshop",
                            "fashionbeats has great services in the city",
                            "I am proud to have fashionbeats",
                            "mymarket has awesome services",
                            "Thanks Newshop for the quick delivery"};

    vector<string> competitors {"newshop", "shopnow", "afashion", "fashionbeats", "mymarket", "tcellular"};
    vector<string> result = TopNumCompetitors(6,2,competitors,reviews);

    for(auto a: result){
        cout<<a<<endl;
    }
    return 0;
}
