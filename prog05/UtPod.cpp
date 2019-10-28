//
// Created by ryan7 on 10/22/2019.
//
#include <cstdlib>
#include "UtPod.h"

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

bool operator > (Song& s, Song& s1){
    return false;
}


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
    Song testSong = s;
    //cout<<"name of song at head: " << song->s.getName() << endl;
    SongNode *currentPtr = song;
    SongNode *prvPtr = nullptr;
    bool songRemoved = false;
    if(currentPtr == nullptr){
        return -1;
    }else if(song->s == testSong){
        //cout<<"here we are"<<endl;
        SongNode *nodeNext = song->next;
        if(nodeNext == nullptr){
            cout<<"if statement" << endl;
            free(song);
            song = nullptr;
        }else{
            //cout<<"else statement"<<endl;
            free(song);
            song = currentPtr->next;
        }
    }else{
        prvPtr = currentPtr;
        currentPtr = song->next;
        while(!songRemoved){
            if(currentPtr->s == testSong){
                prvPtr->next = currentPtr->next;
                free(currentPtr);
                songRemoved = true;
            }else{
                prvPtr = currentPtr;
                currentPtr = currentPtr->next;
            }

        }
    }
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
