// https://leetcode.com/problems/counting-bits

class Solution {
public:
  vector<int> countBits(int n) {
    vector <int> a;
    a.push_back(0);
    for(int decimal = 1;decimal<=n;decimal++){
    bitset<32> binary(decimal); // convert decimal to binary using bitset
    string b = binary.to_string();
    string ans = b.substr(b.find('1'));

    int count=0;
    for (int i = 0; i < ans.size(); i++) {
      if (ans[i] == '1') {
        count++;
      }
    }
    a.push_back(count);
    }
    return a;
  }
};