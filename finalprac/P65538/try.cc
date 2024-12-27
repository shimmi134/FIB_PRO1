#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Word {
    string word;
    int count;
};

void read_vector(int n) {
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    sort(words.begin(), words.end());

    vector<Word> v;
    string current_word = words[0];
    int current_count = 1;

    for (int i = 1; i < n; i++) {
        if (words[i] == current_word) {
            current_count++;
        } else {
            Word wrd;
            wrd.word = current_word;
            wrd.count = current_count;
            v.push_back(wrd);
            current_word = words[i];
            current_count = 1;
        }
    }
    Word wrd;
    wrd.word = current_word;
    wrd.count = current_count;
    v.push_back(wrd);

    string most_freq_word;
    int max_count = 0;

    for (size_t i = 0; i < v.size(); i++) {
        if (v[i].count > max_count || (v[i].count == max_count && v[i].word > most_freq_word)) {
            most_freq_word = v[i].word;
            max_count = v[i].count;
        }
    }

    cout << most_freq_word << endl;
}

int main() {
    int size;
    cin >> size;

    while (size != 0) {
        read_vector(size);
        cin >> size;
    }

    return 0;
}

