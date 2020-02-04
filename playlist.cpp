// Playlist class demonstrating partially filled arrays
// Can add/remove songs from playlist
// find songs in playlist

#include "playlist.h"
#include <iostream>
#include <cstdlib>
using namespace std;
// constructor with default name
Playlist::Playlist(const string& name) {
    playListName = name;
    numberOfSongs = 0;
}

// destructor
// nothing on heap
Playlist::~Playlist() {
    // destructor
}

// true if song found in playlist
bool Playlist::isInPlaylist(const string& song) const {

    for (int i = 0; i < numberOfSongs; i++) {
        if (songList[i] == song) {
            return true;
        }
    }
    return false;

}

// add a new song
// return true if successful, false if song already in playlist
bool Playlist::addSong(const string &song) {

    if (isInPlaylist(song) == false) {
        songList[numberOfSongs] = song;
        numberOfSongs = numberOfSongs + 1;
        return true;
    }
    else {
        return false;
    }
}

// remove a song
// return true if successfully removed, false if song not in playlist
bool Playlist::removeSong(const string &song) {

    for (int i = 0; i < numberOfSongs; i++) {
        if (songList[i] == song) {
            songList[i] = songList[numberOfSongs - 1];
            numberOfSongs = numberOfSongs - 1;
            return true;
        }

    }
    return false;
}

// list all songs
void Playlist::listAllSongs() const {
    for (int i = 0; i < numberOfSongs; i++) {
        cout << songList[i] << ", ";
    }
}

// list shuffled songs with count
void Playlist::listShuffledSongs(unsigned int count) const {
    
    int randomSong;
    for (int i = 0; i < count; i++) {
        randomSong = rand() % 10;
        cout << songList[randomSong] << ", ";
    }
    cout << endl;
}

ostream& operator<<(ostream& Out, const Playlist& playlist) {
    playlist.listAllSongs();
    return Out;
}