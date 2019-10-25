//
// Created by ryan7 on 10/22/2019.
//

#include "UtPod.h"

UtPod::UtPod(int _size){

    song->next = nullptr;

    if(_size>MAX_MEMORY || _size <= 0){
        memSize = MAX_MEMORY;
    }
    else{
        memSize = _size;
    }
}

int UtPod::addSong(Song const &s) {
    /*
    if(( s.getSize() + memSize) > MAX_MEMORY){
        return 0;
    }
    else{
        SongNode *newNode = new UtPod::SongNode();
        newNode->next = song;
        newNode->s = s;
        song = newNode;
    }
     */
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
