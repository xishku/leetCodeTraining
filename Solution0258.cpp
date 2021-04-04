class Solution0258 {
public:
    int addDigits(int num) {
        int ans = 0;
        while (num > 0) {
            ans += num % 10;
            num /= 10;
        }

        if (ans >= 10) {
            return addDigits(ans);
        }

        return ans;
    }

    void Test() {
        cout << addDigits(123456) << endl;
    }
};
