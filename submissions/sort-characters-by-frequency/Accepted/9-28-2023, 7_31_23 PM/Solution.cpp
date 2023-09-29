// https://leetcode.com/problems/sort-characters-by-frequency

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> um; //store (char,freq)
        for(auto ch:s){
            um[ch]++;
        }

        // maxheap of freq
        priority_queue<pair<int,char>> pq;
        for(auto x:um){
            pq.push(make_pair(x.second,x.first));
        }

        s="";
        // build string using maxheap
        while(!pq.empty()){
            auto curr = pq.top();
            s += string(curr.first, curr.second);
            pq.pop();
        }
        return s;
    }
};