# Leetcode-2467.-Most-Profitable-Path-in-a-Tree
# 🌲 Most Profitable Path in a Tree

This project implements a C++ solution to the **LeetCode problem [mostProfitablePath](https://leetcode.com/problems/most-profitable-path-in-a-tree/)**, where Alice starts from node `0` and Bob starts from a given node. The goal is for Alice to collect the **maximum profit** as she traverses the tree based on certain conditions.

---

## 🚀 Problem Overview

- You are given an undirected tree with `n` nodes.
- Each node has a certain `amount[i]` that can be collected.
- Alice starts from node `0`, Bob starts from node `bob`.
- Bob always chooses a fixed path to node `0`, and at each time unit, both move to one of their neighboring nodes.
- At a node:
  - If Alice arrives before Bob → Alice gets full amount.
  - If Bob arrives before Alice → Alice gets nothing.
  - If both arrive at the same time → Alice gets half of the amount.
- The goal is to **maximize the total amount Alice can collect** on any path from node `0` to a leaf node.

---

## 🧠 Algorithm

### Step 1: Bob's Path to Node 0

- Use a DFS (`dfstozero`) to find the **exact path** Bob will take from his starting node to node `0`.
- Store the **time taken by Bob** to reach each node in a map.

### Step 2: DFS for Alice's Path

- Perform another DFS (`dfs2`) from node `0`.
- At each step, decide how much Alice can collect at that node depending on when she and Bob arrive.
- Track the maximum value of income at any **leaf node**.

---

## 🧾 Key Functions

- `dfstozero(...)`: Finds Bob's path to node `0` and records his arrival times.
- `dfs2(...)`: Simulates Alice’s path and computes profit based on conditions.
- `mostProfitablePath(...)`: Driver function to build graph, initiate DFSs, and return result.

---

📈 Time and Space Complexity
Time Complexity: O(N), where N is the number of nodes (each node is visited once in both DFS calls).

Space Complexity: O(N) for storing the graph, visited array, and Bob's arrival map.

---

Input:
edges = [[0,1],[1,2],[1,3],[3,4]], bob = 4
amount = [5,2,4,1,3]

Output:
6

---

👨‍💻 Author
Ridham Garg

Thapar Institute of Engineering and Technology (Patiala)


📜 License
This project is licensed under the MIT License.

