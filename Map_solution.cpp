class Solution {
public:
    // Global variable to keep track of the maximum income path
    int maxincome = -100000000;

    // DFS to find path from Bob's node to node 0 and record Bob's time to reach each node
    bool dfstozero(unordered_map<int, vector<int>>& mp, unordered_map<int, int>& mp1, int i, int count, vector<bool>& visited) {
        visited[i] = true;
        mp1[i] = count; // Record time taken by Bob to reach node i

        if (i == 0) // Reached node 0
            return true;

        for (int p : mp[i]) {
            if (!visited[p]) {
                if (dfstozero(mp, mp1, p, count + 1, visited)) // Continue DFS
                    return true;
            }
        }

        mp1.erase(i); // Backtrack if path doesn't reach node 0
        return false;
    }

    // DFS from Alice's perspective to collect maximum income
    void dfs2(int i, vector<bool>& visited, unordered_map<int, vector<int>>& mp, unordered_map<int, int>& mp1, vector<int>& amount, int time, int get) {
        int added = 0;

        // Decide the amount to collect based on Alice's and Bob's arrival times
        if (mp1.find(i) != mp1.end() && mp1[i] == time)
            added = amount[i] / 2; // Both arrive at same time
        else if (mp1.find(i) != mp1.end() && mp1[i] < time)
            added = 0; // Bob already took it
        else
            added = amount[i]; // Alice arrives first

        get += added;
        visited[i] = true;

        bool isLeaf = true;
        for (int p : mp[i]) {
            if (!visited[p]) {
                isLeaf = false;
                dfs2(p, visited, mp, mp1, amount, time + 1, get); // Continue DFS
            }
        }

        if (isLeaf) {
            maxincome = max(maxincome, get); // Update maximum income if at a leaf node
        }
    }

    // Main function
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        unordered_map<int, vector<int>> mp;  // Adjacency list
        unordered_map<int, int> mp1;         // Time taken by Bob to reach each node
        int n = amount.size();

        // Build graph
        for (auto& edge : edges) {
            int from = edge[0];
            int to = edge[1];
            mp[from].push_back(to);
            mp[to].push_back(from);
        }

        vector<bool> visited(n, false);

        // Step 1: Track Bob's path to node 0
        dfstozero(mp, mp1, bob, 0, visited);

        // Step 2: DFS from node 0 to calculate max profit for Alice
        fill(visited.begin(), visited.end(), false);
        dfs2(0, visited, mp, mp1, amount, 0, 0);

        return maxincome;
    }
};
