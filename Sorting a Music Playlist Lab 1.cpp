#include<bits/stdc++.h>
using namespace std;

class Song
{
public:
    string name;
    string singer;
    double duration;
    int release_year;

    Song(string n,string s, double d, int r)
        : name(n), singer(s), duration(d), release_year(r) {}
};

vector<Song> createPlaylist()
{
    vector<Song> playlist;
    playlist.push_back(Song("Song1", "SingerA", 3.5, 2020));
    playlist.push_back(Song("Song2", "SingerB", 4.0, 2019));
    playlist.push_back(Song("Song3", "SingerA", 2.8, 2021));
    playlist.push_back(Song("Song4", "SingerC", 3.2, 2018));
    playlist.push_back(Song("Song5", "SingerB", 3.9, 2020));
    return playlist;
}

bool compareByName(const Song &a, const Song &b)
 {
    return a.name < b.name;
}

bool compareBySinger(const Song &a, const Song &b)
{
    return a.singer < b.singer;
}

bool compareByDuration(const Song &a, const Song &b)
 {
    return a.duration > b.duration;
}

bool compareByReleaseYear(const Song &a, const Song &b)
{
    return a.release_year > b.release_year;
}

void sortPlaylist(vector<Song> &playlist, const string &criterion)
{
    if (criterion == "name")
        {
        sort(playlist.begin(), playlist.end(), compareByName);
    }
    else if (criterion == "singer")
        {
        sort(playlist.begin(), playlist.end(), compareBySinger);
    }
    else if (criterion == "duration")
        {
        sort(playlist.begin(), playlist.end(), compareByDuration);
    }
    else if (criterion == "release_year")
        {
        sort(playlist.begin(), playlist.end(), compareByReleaseYear);
    }
}

void displayPlaylist(const vector<Song> &playlist)
 {
    for (const auto &song : playlist)
        {
        cout << "Name: " << song.name
                  << ", Singer: " << song.singer
                  << ", Duration: " << song.duration
                  << ", Release Year: " << song.release_year << endl;
    }
}

void userInterface()
{
    vector<Song> playlist = createPlaylist();
    string criterion;

    cout << "Original Playlist:" << endl;
    displayPlaylist(playlist);

    cout << "\nSelect sorting criterion (name, singer, duration, release_year): ";
    cin >> criterion;

    sortPlaylist(playlist, criterion);

    cout << "\nSorted Playlist by " << criterion << ":" << endl;
    displayPlaylist(playlist);
}

int main()
 {
    userInterface();
    return 0;
}
