//
// Created by ryan7 on 10/22/2019.
//
#include <cstdlib>
#include "UtPod.h"
UtPod::UtPod() {
    song = nullptr;
    memSize = 512;
}

UtPod::UtPod(int _size){
    song = nullptr;
    if(_size>MAX_MEMORY || _size <= 0){
        memSize = MAX_MEMORY;
    }
    else{
        memSize = _size;
    }

}

int UtPod::addSong(Song const &s) {

    Song testSong = s;
    if(testSong.getSize() + (getRemainingMemory()) > memSize){
        return -1;
    }
    else{
        SongNode *newNode;
        newNode = new UtPod::SongNode();
        newNode->next = UtPod::song;
        newNode->UtPod::SongNode::s = s;
        UtPod::song = newNode;
    }
    return 0;
}

int UtPod::removeSong(Song const &s) {

    return 0;
}
void UtPod::shuffle() {
    

}
void UtPod::showSongList(){
    SongNode *node = song;
    if(node == NULL){
        cout <<"no songs in Ut Pod" <<endl;
    }
    else{
        cout <<"songs in Ut Pod:" <<endl;
        while(node != nullptr){
            Song songOfNode = node->s;
            cout << songOfNode.getName() << " by " << songOfNode.getArtist() << endl;
            node = node->next;
        }
    }

}

void UtPod::sortSongList(){

}

void UtPod::clearMemory(){
    SongNode *node = song;
    while(node != nullptr){
        free(song);
        node = node->next;
        UtPod::song = node;
    }

}

int UtPod::getRemainingMemory(){
    SongNode *node = song;
    int mem = 0;
    while(node != nullptr){
        Song songOfNode = node->s;
        mem+= songOfNode.getSize();
        node = node->next;
    }
    return mem;
}
UtPod::~UtPod() {

}
