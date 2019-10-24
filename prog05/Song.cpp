//
// Created by ryan7 on 10/22/2019.
//

#include "Song.h"

Song::Song(string _artist, string _name, int _size){
    name = _name;
    artist = _artist;
    size = _size;
}
string Song::getName() {
    return name;
}
string Song::getArtist() {
    return artist;
}
int Song::getSize() {
    return size;
}