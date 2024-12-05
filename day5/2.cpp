#include <bits/stdc++.h>
using namespace std;

// nem eu nem o copilot tankamos este input
void parseInput(istream& input, vector<pair<int, int>>& rules, vector<vector<int>>& updates) {
    string line, input_data, rules_section, updates_section;

    // not sure if this template is good
    // Had to redo the input :\

    while (getline(input, line)) {
        input_data += line + "\n";
    }

    // Find \n\n
    size_t separator = input_data.find("\n\n");
    if (separator != string::npos) {
        rules_section = input_data.substr(0, separator);
        updates_section = input_data.substr(separator + 2);
    }

    // Parse rules
    stringstream rules_stream(rules_section);
    while (getline(rules_stream, line)) {
        size_t delimiter = line.find('|');
        if (delimiter != string::npos) {
            int x = stoi(line.substr(0, delimiter));
            int y = stoi(line.substr(delimiter + 1));
            rules.emplace_back(x, y); // testing this the same as push_back
        }
    }

    // Parse updates
    stringstream updates_stream(updates_section);
    while (getline(updates_stream, line)) {
        if (line.empty()) continue;
        vector<int> update;
        stringstream lineStream(line);
        string page;
        while (getline(lineStream, page, ',')) {
            update.push_back(stoi(page));
        }
        updates.push_back(update);
    }
}

// Check if an update is valid based on rules
bool isUpdateValid(const vector<int>& update, const vector<pair<int, int>>& rules) {
    unordered_map<int, int> indexMap;
    for (int i = 0; i < update.size(); ++i) {
        indexMap[update[i]] = i;
    }

    for (const auto& rule : rules) {
        int x = rule.first, y = rule.second;
        if (indexMap.count(x) && indexMap.count(y)) {
            if (indexMap[x] >= indexMap[y]) {
                return false;
            }
        }
    }

    return true;
}


vector<int> reorderUpdate(const vector<int>& update, const vector<pair<int, int>>& rules) {
    unordered_map<int, vector<int>> graph;
    unordered_map<int, int> inDegree;
    unordered_set<int> nodes(update.begin(), update.end());

    // copilot carried the shit out of this tbh
    for (const auto& rule : rules) {
        int x = rule.first, y = rule.second;
        if (nodes.count(x) && nodes.count(y)) {
            graph[x].push_back(y);
            inDegree[y]++;
            if (inDegree.find(x) == inDegree.end()) inDegree[x] = 0;
        }
    }

    // Topological sort using a queue
    queue<int> q;
    for (int node : nodes) {
        if (inDegree[node] == 0) {
            q.push(node);
        }
    }

    vector<int> sortedUpdate;
    // did not trust graphs would solve this,  
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        sortedUpdate.push_back(current);

        for (int neighbor : graph[current]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return sortedUpdate;
}


int solve(istream& input) {
    vector<pair<int, int>> rules;
    vector<vector<int>> updates;
    parseInput(input, rules, updates);

    int total = 0;
    for (const auto& update : updates) {
        // take non valid updates correct them and get the middle
        if (!isUpdateValid(update, rules)) {
            vector<int> reordered = reorderUpdate(update, rules);
            total += reordered[reordered.size() / 2];
        }
    }

    return total;
}

int main() {
    cout << solve(cin) << endl;
    return 0;
}