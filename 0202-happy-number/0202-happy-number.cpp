class Solution {
public:
    
    int getSq(int val) {
        int temp =val;
        val = 0;
        while(temp) {
            int a = temp%10;
            val += a*a;
            temp/=10;
        }
        return val;
    }
    
    bool isHappy(int n) {
        int fast = n;
        int slow = fast;
        do {
            fast = getSq(fast);
            fast = getSq(fast);
            slow = getSq(slow);
            if(slow == 1 || fast == 1) return true;
        }while(slow!=fast);
        return false;
    }
};