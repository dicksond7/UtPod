//
// Created by ryan7 on 10/22/2019.
//
#include <cstdlib>
#include <string>
#include <cstring>
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

    for(int i = 0; i < (2*numberOfSongs()); i++){
        SongNode *tempNode1 = song;
        SongNode *tempNode2 = song;
        int random1 = rand() % numberOfSongs();
        int random2 = rand() % numberOfSongs();

        for(int j = 0; j < random1 ; j++){
            tempNode1 = tempNode1->next;

        }

        for(int j = 0; j < random2; j++){
            tempNode2 = tempNode2->next;
        }
        Song tempSong = tempNode2->s;
        tempNode2->s = tempNode1->s;
        tempNode1->s = tempSong;

    }


}
void UtPod::showSongList(){
    SongNode *node = song;
    if(node == nullptr){
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
//WILL SWAP THE FIRST 2 NODES BUT ISSUES WHEN SWAPPING MORE
void UtPod::sortSongList(){
    //first check the first 2 nodes
    SongNode *prvNode;
    SongNode *headNode = song;
    SongNode *nextNode = song->next;
    /*
    if(nextNode->s > headNode->s){
        cout << "swapping!" << endl;
        //swap the nodes
        //SongNode *HolderNode = headNode;
        headNode->next = nextNode->next;
        song = nextNode;
        song->next = headNode;
    }
    */

    bool isSorted = false;
    SongNode *checkNode = song;
    while(!isSorted) {
        checkNode = song;
        //headNode = song;
        nextNode = song->next;
        //cout << "net yet sorted. checking whole list" << endl;
        isSorted = true;
        if(nextNode->s > checkNode->s){
            Song tempSong = nextNode->s;
            //cout << "swapping!" << endl;
            //swap the nodes
            //SongNode *HolderNode = headNode;
            nextNode->s = checkNode->s;
            checkNode->s = tempSong;

            isSorted = false;
            continue;
        }

        checkNode = checkNode->next;
        nextNode = checkNode->next;
        //headNode = checkNode;
        //nextNode = checkNode->next;


        while (checkNode->next != nullptr) {
            //cout << "checking nodes!" << endl;
            //nextNode = checkNode->next;
            if(nextNode->s > checkNode->s){
                Song tempSong = nextNode->s;
                //cout << "swapping while if" << endl;
                //swap the nodes
                //SongNode *HolderNode = headNode;
                nextNode->s = checkNode->s;
                checkNode->s = tempSong;

                isSorted = false;
            }
            //cout << "completed checking a node" << endl;
            checkNode = checkNode->next;
            nextNode = checkNode->next;

        }
        //cout << "completed checking the list" << endl;

    }
    //cout << "list is sorted!" << endl;
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

int UtPod::numberOfSongs(){
    SongNode *tempNode = song;
    int numSongs = 0;
    while(tempNode->next != nullptr){
        numSongs++;
        tempNode = tempNode->next;
    }
    numSongs += 1;
    return numSongs;
}


UtPod::~UtPod() {
    clearMemory();

}
