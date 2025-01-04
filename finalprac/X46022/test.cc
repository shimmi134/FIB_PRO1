#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Player {
    string name;
    int level;
    int wins; // Tracks number of matches won
    
    // Constructor to initialize 'wins' to 0
    Player(string n, int l) : name(n), level(l), wins(0) {}
};

bool compareByLevel(const Player& a, const Player& b) {
    return a.level < b.level; // Sort players by their level in ascending order
}

int main() {
    int n;
    while (cin >> n) {
        // Read Russian players
        vector<Player> russianPlayers;
        vector<int> russianIndices(n);
        for (int idx = 0; idx < n; idx++) {
            string name;
            int level;
            cin >> name >> level;
            russianPlayers.push_back(Player(name, level));
            russianIndices[idx] = idx; // Store original indices
        }

        // Read USA players
        vector<Player> usaPlayers;
        vector<int> usaIndices(n);
        for (int idx = 0; idx < n; idx++) {
            string name;
            int level;
            cin >> name >> level;
            usaPlayers.push_back(Player(name, level));
            usaIndices[idx] = idx; // Store original indices
        }

        // Sort both teams by the level of the players
        sort(russianPlayers.begin(), russianPlayers.end(), compareByLevel);
        sort(usaPlayers.begin(), usaPlayers.end(), compareByLevel);

        // Two-pointer technique to simulate matches
        int i = 0, j = 0;
        while (i < n && j < n) {
            if (russianPlayers[i].level < usaPlayers[j].level) {
                // Russian player i loses both matches
                russianPlayers[i].wins += 0; // No wins for this player
                usaPlayers[j].wins += 2; // USA player j wins both matches
                i++; // Move to the next Russian player
            } else if (russianPlayers[i].level > usaPlayers[j].level) {
                // USA player j loses both matches
                russianPlayers[i].wins += 2; // Russian player i wins both matches
                usaPlayers[j].wins += 0; // No wins for this player
                j++; // Move to the next USA player
            } else {
                // Both players have the same level, each wins 1 match
                russianPlayers[i].wins += 1;
                usaPlayers[j].wins += 1;
                i++; // Move to the next Russian player
                j++; // Move to the next USA player
            }
        }

        // Output results in the original order
        vector<int> russianWins(n);
        vector<int> usaWins(n);

        // Map the results back to the original indices
        for (int idx = 0; idx < n; idx++) {
            russianWins[russianIndices[idx]] = russianPlayers[idx].wins;
            usaWins[usaIndices[idx]] = usaPlayers[idx].wins;
        }

        // Print Russian team results
        for (int idx = 0; idx < n; idx++) {
            cout << russianPlayers[idx].name << " " << russianWins[idx] << " ";
        }
        cout << endl;

        // Print USA team results
        for (int idx = 0; idx < n; idx++) {
            cout << usaPlayers[idx].name << " " << usaWins[idx] << " ";
        }
        cout << endl;
        cout << endl; // Blank line between test cases
    }
    
    return 0;
}
