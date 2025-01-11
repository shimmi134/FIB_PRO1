#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Define the Track structure
struct Track {
    string artist, title, genre;
    int year;
};

// Function to read tracks from input
vector<Track> read_tracks(int n) {
    vector<Track> tracks(n);
    for (int i = 0; i < n; ++i) {
        cin >> tracks[i].artist >> tracks[i].title >> tracks[i].genre >> tracks[i].year;
    }
    return tracks;
}

// Function to print a single track
void print_track(const Track &t) {
    cout << t.artist << " (" << t.year << ") " << t.title << " (" << t.genre << ")" << endl;
}

// Comparator for sorting tracks
bool track_comparator(const Track &a, const Track &b) {
    if (a.artist != b.artist) return a.artist < b.artist;
    if (a.year != b.year) return a.year < b.year;
    return a.title < b.title;
}

// Main function
int main() {
    int n;
    cin >> n;

    // Read all tracks
    vector<Track> tracks = read_tracks(n);

    // Sort tracks globally by artist, year, and title
    sort(tracks.begin(), tracks.end(), track_comparator);

    string genre;
    while (cin >> genre) {
        bool found = false;

        // Filter and print tracks of the specified genre
        for (const Track &track : tracks) {
            if (track.genre == genre) {
                if (!found) {
                    found = true;
                    cout << genre << " tracks:" << endl;
                }
                print_track(track);
            }
        }

        // If no tracks of the genre were found, output a message
        if (!found) {
            cout << "No tracks found for genre: " << genre << endl;
        }
    }

    return 0;
}

