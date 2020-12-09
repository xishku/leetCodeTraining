class StockSpanner {
private:
    vector<int> ans;
    stack<int> monoStack;
    vector<int> spanner;
public:
    StockSpanner() {

    }

    int next(int price) {
        // cout << "price: " << price << endl;
        spanner.push_back(price);
        while (!monoStack.empty() && spanner[monoStack.top()] <= price) {
            monoStack.pop();
        }

        int i = spanner.size() - 1;
        ans.push_back(monoStack.empty()? i + 1: i - monoStack.top());

        monoStack.push(i);
        // cout << ans[i] << endl;
        return ans[i];
    }
};
