// https://leetcode.com/problems/count-primes

class Solution {
public:
    int countPrimes(int n) {
        int count=0;
        for(int i=2;i<n;i++){
            if(isPrime(i)){
                count++;
            }
        }
        return count;
    }

    bool isPrime(int m){
        for(int i=2;i<m;i++){
            if(m%i==0){
                return false;
            }
        }
        return true;
    }
};