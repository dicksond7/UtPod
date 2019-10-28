//
// Created by ryan7 on 10/22/2019.
//

#include "UtPod.h"
UtPod::UtPod() {
    song = nullptr;
    memSize = 512;
    currentMem = 0;
}

UtPod::UtPod(int _size){
    song = nullptr;
    if(_size>MAX_MEMORY || _size <= 0){
        memSize = MAX_MEMORY;
    }
    else{
        memSize = _size;
    }
    currentMem = 0;

}

int UtPod::addSong(Song const &s) {

    Song testSong = s;
    if(testSong.getSize() + (currentMem) > memSize){
        return -1;
    }
    else{
        SongNode *newNode;
        newNode = new UtPod::SongNode();
        newNode->next = song;
        newNode->s = s;
        song = newNode;
    }

    return 0;
}

int UtPod::removeSong(Song const &s) {
    return 0;
}
void UtPod::shuffle() {

}
void UtPod::showSongList(){

}

void UtPod::sortSongList(){

}

void UtPod::clearMemory(){

}

int UtPod::getRemainingMemory(){
    return 0;
}
UtPod::~UtPod() {

}
