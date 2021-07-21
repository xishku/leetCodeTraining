#include "gtest/gtest.h"
#include <iostream>
#include "../src/convertNum.h"
#include "../src/foo.h"
#include <vector>
#include <set>
#include <sstream>
#include "../src/DFSConnect.h"
#include "../src/MyTrace.h"

using namespace std;
char mainConvertStr(char source)
{
    if (source <= 'Z' && source >= 'A') {
        if (source != 'A' &&
            source != 'E' &&
            source != 'I' &&
            source != 'O' &&
            source != 'U'){
            return source - ('A' - 'a');
        }
    }
    else if (source <= 'z' && source >= 'a') {
        if (source == 'a' ||
            source == 'e' ||
            source == 'i' ||
            source == 'o' ||
            source == 'u'){
            return source + ('A' - 'a');
        }
    }

    return source;
}

string mainVowelString(const string input)
{
    string resultStr;
    for(int i = 0; i < input.length(); ++i) {
        resultStr.push_back(mainConvertStr(input.at(i)));
    }
    return resultStr;
}

/*
 * 题目描述
有N个城市，A B C D …。其中城市可以两两通过光纤相连通信。如A-B，B-C，则认为A可以与C通信。现要新建光纤，将已存在的城市网络打通，使得所有城市可以相互通信。求最少需要多少根光纤。
例如：A-B B-C D-E，需要至少新建一根光纤可以使得所有城市可以相互通信。
解答要求
时间限制：3000ms, 内存限制：64MB
输入
第一行为两个整数N和M（1 <= N，M <= 100）开头。
N表示城市的数量，城市从1到N标记;
M为表示关系的数据行数。
从第二行开始，每行包含两个整数A和B（A！= B），这意味着城市A和城市B彼此相连。
输出
输出至少需要新建多个光纤连接。
样例
输入样例 1 复制
5 3
1 2
2 3
4 5
输出样例 1
1
输入样例 2 复制
5 1
2 5
输出样例 2
3
 */
void dfs(int i, vector<bool>& used, vector<vector<int>>& edges) {
    cout << "dfs : " << i << endl;
    used[i] = true;
    for(auto&& v: edges[i]) {
        if(!used[v]) {
            dfs(v, used, edges);
        }
    }
}

void connectCity()
{
    int length = 0;
    int edgeNum = 0;
    string line;
    if (getline(cin, line)) {
        std::istringstream ss(line);
        ss >> length >> edgeNum;
        cout << length << edgeNum << endl;
    }
    if (length < 1) {
        cout << 0 << endl;
        return;
    }

    vector<vector<int>> connections;
    for (int i = 0; i < edgeNum; ++i) {
        if (getline(cin, line)) {
            int num1;
            int num2;
            std::istringstream ss(line);
            ss >> num1 >> num2;
            connections.push_back({num1, num2});
            cout << num1 << " " << num2 << endl;
        }
    }

    vector<vector<int>> edges;
    edges.resize(length + 1); //No. begins 1
    for(auto&& a: connections) {
        cout << a[0] << " " << a[1] << endl;
        edges.at(a[0]).push_back(a[1]);
        edges.at(a[1]).push_back(a[0]);
    }

    vector<bool> used;
    used.resize(length + 1);
    cout << "length: " << length << endl;
    int part = 0;
    for (int i = 1 ; i < length + 1; ++i) {
        if(!used.at(i)) {
            ++part;
            cout << "part: " << part << endl;
            dfs(i, used, edges);
        }
    }

    //need part - 1 to connect
    cout << part - 1 << endl;
}

/*
 * 题目描述
有 n （0 < n <= 20）个不同金额的红包叠成的红包塔。两个人轮流从上往下依次拿走1或2个红包，直到拿完。计算两个人分别拿到的红包总价值，价值高的人获胜。
请判定先手玩家必胜还是必败，并输出相应的结果。
若必胜, 输出 true, 否则输出 false.
解答要求
时间限制：10000ms, 内存限制：64MB
输入
第1个数字表示红包个数，后面的数字表示从上到下的红包的金额。
两个玩家可以玩多局，一行表示一局的红包塔。
输出
对于每个用例，输出true或false
样例
输入样例 1 复制
3 1 2 2
3 1 2 4
输出样例 1
true
false
提示
第一个用例，3个红包，先手直接拿走两个红包即可。
第二个用例，3个红包，无论先手拿一个还是两个, 后手可以拿完, 然后总价值更高。
 * */
void pickPackage()
{
    foo f;
    vector<vector<int>> package;

    string line;
    while (getline(cin, line)) {
        int num1;
        int num2;
        std::istringstream ss(line);
        vector<int> innerPackage;

        while (ss >> num1) {
            innerPackage.push_back(num1);
        }
        package.push_back(innerPackage);

        //cout << num << endl;
    }

    cout << "loop out" << endl;
    for(auto it = package.begin(); it != package.end(); ++it) {
        cout << "line:" << endl;
        for (auto innerIt = it->begin(); innerIt != it->end(); ++innerIt) {
            cout << *innerIt << endl;
        }

    }

}

/*
 * 题目描述
有一堆樱桃，分别从中拿出n颗樱桃，往一些篮子里放。要求：每个篮子里的樱桃最少为1个；
不能全部放到一个篮子里；
每个篮子的樱桃数量不能相同；
不区分篮子的顺序，篮子的数量足够多。
求一共有多少种分法。
解答要求
时间限制：1000ms, 内存限制：64MB
输入
樱桃的数量
输出
分法的总数
样例
输入样例 1 复制
10
输出样例 1
9
提示
10个樱桃一共有如下9种分法
1: 1 9
2: 1 2 7
3: 1 2 3 4
4: 1 3 6
5: 1 4 5
6: 2 8
7: 2 3 5
8: 3 7
9: 4 6
 */
void orchCherry()
{
    foo f;
    int num;
    cin >> num;
    cout << f.orchCherry(num) << endl;
}


void getChoiceNum(int num)
{
    int stpes;
}


int main(int argc, char *argv[]) {
    set<int> pointSet;
    pointSet.insert(1);
    pointSet.insert(1);
    for(auto& a: pointSet) {
        cout << a << endl;
    }
    //vector<vector<int>> edges = {{1,2},{2,3},{1,3}};

    //DFSConnect dfsConnect;
    //cout << dfsConnect.makeConnected(4, edges) << endl;
    connectCity();
    cout << "hello world" << endl;
    return 0;

    //string input;
    //getline(cin,input);
    //cout << mainVowelString(input) << endl;

    //foo f;
    //vector<string> banned = {"hit"};
    //cout << f.mostCommonWord("Bob hit a ball, the hit BALL flew far after it was hit.", banned) << endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;
}
