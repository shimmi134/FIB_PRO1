#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Track {
  string artist, title, genre;
  int year;
};

void merge(vector<Track>&T, int s, int e, int m)
{
    vector<Track>temp(e-s+1);
    int i = s, j = m+1, k =0;
    while (i <= m && j <= e)
    {
        if (T[i].artist < T[j].artist)
        {
            temp[k] = T[i];
            i++;
        }
        else if (T[i].artist == T[j].artist)
        {
            if (T[i].year < T[j].year)
            {
                temp[k] = T[i];
                i++;
            }
            else if (T[i].year == T[j].year)
            {
                if (T[i].title < T[j].title)
                {
                    temp[k] = T[i];
                    i++;
                }
                else
                {
                    temp[k] = T[j];
                    j++;
                }  
            }
            else
            {
                temp[k] = T[j];
                j++;
            }
        }
        else
        {
            temp[k] = T[j];
            j++;
        }
        k++;
    }
    while (i <= m)
    {
        temp[k] = T[i];
        i++;
        k++;
    }
    while (j <= e)
    {
        temp[k] = T[j];
        j++;
        k++;
    }
    for (int n = 0; n < temp.size(); n++)
        T[n+s] = temp[n];
}

void Sort(vector<Track>&T, int start, int end)
{
    if (start < end)
    {
        int m = start + (end-start)/2;
        Sort(T,start,m);
        Sort(T,m+1,end);
        merge(T,start,end,m);
    }
}

void mergeSort(vector<Track>&T)
{
    Sort(T,0,T.size()-1);
}
vector<Track> read_tracks(int n) {
  vector<Track>tracks(n);
  for (int i = 0; i < tracks.size(); i++)
  {
    cin >> tracks[i].artist >> tracks[i].title >> tracks[i].genre >> tracks[i].year;
  }
  return (tracks);
}

void print_track(const Track &t) {
  cout << t.artist;
  cout << " (" << t.year;
  cout << ") " << t.title << " (" << t.genre << ")" << endl;
}

int main() {
  int n;
  cin >> n;
  vector<Track>T = read_tracks(n);
  mergeSort(T);
  string s;
  while (cin >> s)
  {
    for (int i = 0; i < T.size(); i++)
    {
        if (T[i].genre == s)
            print_track(T[i]);
    }
  }
}