// Accounts Merge (Leetcode)
// Leetcode Link : https://leetcode.com/problems/accounts-merge/description/

// Time Complexity : O((n * k) + (e * Loge)) - [n = number of accounts, k = average no. of emails per account, e = number of emails]
// Space Complexity : O(n + e)

class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        // Step 1: Initialize parent and size arrays
        parent.resize(n);
        size.resize(n, 1);

        // Step 2: Each element is its own parent initially
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        // Step 1: Path compression for efficient find
        if(parent[x] == x) return parent[x];
        return parent[x] = find(parent[x]);
    }

    void unionBySize(int u, int v) {
        // Step 1: Find roots of both elements
        int a = find(u);
        int b = find(v);

        // Step 2:  If both elements are from different set, merge smaller set into larger set
        if(a != b) {
            if(size[a] < size[b]) {
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mailToName;

        // Step 1: Map each email to an account index & union accounts with common emails
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mailToName.find(mail) == mailToName.end()) {
                    mailToName[mail] = i; // Map email to account
                } else {
                    ds.unionBySize(i, mailToName[mail]); // Union accounts
                }
            }
        }

        // Step 2: Group emails by their root account
        vector<vector<string>> mergedMail(n);
        for (auto it : mailToName) {
            string mail = it.first;
            int name = ds.find(it.second); // Find root account
            mergedMail[name].push_back(mail);
        }

        // Step 3: Prepare the final result with sorted emails and account names
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mergedMail[i].size() == 0) continue;
            string name = accounts[i][0];
            sort(mergedMail[i].begin(), mergedMail[i].end()); // Sort emails

            vector<string> temp;
            temp.push_back(name);
            for (string mail : mergedMail[i]) {
                temp.push_back(mail);
            }
            ans.push_back(temp);
        }

        // Step 4: Return the final merged account list
        return ans;
    }
};