#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include "utils.cpp"

using namespace std;
using namespace DataStructure;

// using bfs, push data to min

class Solution
{

public:
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        queue<TreeNode *> q;
        auto cmp = [](long long &a, long long &b)
        {
            return a < b;
        };
        priority_queue<long long, vector<long long>, decltype(cmp)> pq(cmp);
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            long long sum = 0;
            while (size--)
            {
                sum += q.front()->val;
                if (q.front()->left)
                    q.push(q.front()->left);
                if (q.front()->right)
                    q.push(q.front()->right);
                q.pop();
            }
            pq.push(sum);
        }
        if (k > pq.size())
            return -1;
        while (--k > 0)
        {
            pq.pop();
        }
        return pq.top();
    }
};

int main()
{
    Tree t;
    Solution sln;
    int k;

    t = Tree("[5,8,9,2,1,3,7,4,6]");
    cout << sln.kthLargestLevelSum(t.getRoot(), 2) << endl;
    t = Tree("[1,2,null,3]");
    cout << sln.kthLargestLevelSum(t.getRoot(), 1) << endl;
    return 0;
}