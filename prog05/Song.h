//
// Created by ryan7 on 10/22/2019.
//

#ifndef PROG05_SONG_H
#define PROG05_SONG_H
#include <string>
#include <iostream>
using namespace std;

class Song{
private:
    string artist;
    string name;
    int size;
    static const int MAX_SIZE = 512;
public:
    Song();
    Song(string artist, string name, int size);
    string getArtist();
    string getName();
    int getSize();
    void setArtist(string _artist);
    void setName(string _name);
    void setSize(int _size);
    friend bool operator == (Song& s, Song& s1);
    friend bool operator > (Song& s, Song& s1);

};

#endif //PROG05_SONG_H
