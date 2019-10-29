//
// Created by ryan7 on 10/22/2019.
//

#include "Song.h"
Song::Song(){
    name = "";
    artist = "";
    size = 0;
}

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
void Song::setName(string _name){
    name = _name;
}
void Song::setArtist(string _artist) {
    artist = _artist;
}
void Song::setSize(int _size) {
    size = _size;
}

bool operator == (Song &s, Song &s1){
    int equal = 0; //equal must be == 3 for songs to be equal
    if(s.getName() == s1.getName()){
        equal += 1;
    }
    if(s.getSize() == s1.getSize()){
        equal += 1;
    }
    if(s.getArtist() == s.getArtist()){
        equal += 1;
    }
    return equal == 3;
}

//returns true if 1st song should come before 2nd song
bool operator > (Song &s1, Song &s2){
    string name1 = s1.getName();
    string name2 = s2.getName();
    int length1 = name1.length();
    int length2 = name2.length();
    int length=0;
    if(length1 < length2){
        length = length1;
    }
    else{
        length = length2;
    }
    for(int i =0; i<length; i++){
        if(name1[i] < name2[i]){
            return true;
        }
        else if(name1[i] > name2[i]){
            return false;
        }
    }
    if(length1 < length2){
        return true;
    }else if(length1 > length2){
        return false;
    }else{
        return false;
    }


}