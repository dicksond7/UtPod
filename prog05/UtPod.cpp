//
// Created by ryan7 on 10/22/2019.
//
#include <cstdlib>
#include <string>
#include <cstring>
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
    }
    else if(length1 > length2){
        return false;
    }


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
        cout << "net yet sorted. checking whole list" << endl;
        isSorted = true;
        if(nextNode->s > checkNode->s){
            cout << "swapping!" << endl;
            //swap the nodes
            //SongNode *HolderNode = headNode;
            checkNode->next = nextNode->next;
            song = nextNode;
            song->next = checkNode;
            isSorted = false;
            continue;
        }

        prvNode = checkNode;
        checkNode = checkNode->next;
        nextNode = checkNode->next;
        //headNode = checkNode;
        //nextNode = checkNode->next;
        cout << "song node: " << song->s.getName() <<endl;
        cout << "previous Node: " << prvNode->s.getName() << endl;
        cout << "check Node: " << checkNode->s.getName() <<endl;
        cout << "next Node:" << nextNode->s.getName() << endl;

        while (checkNode->next != nullptr) {
            cout << "checking nodes!" << endl;
            //nextNode = checkNode->next;
            if(nextNode->s > checkNode->s){
                cout << "swapping while if" << endl;
                //swap the nodes
                //SongNode *HolderNode = headNode;
                headNode = checkNode->next;
                prvNode->next = nextNode;
                checkNode->next = nextNode->next;
                nextNode->next = checkNode->next;

                isSorted = false;
            }
            cout << "completed checking a node" << endl;
            prvNode = checkNode;
            checkNode = checkNode->next;
            showSongList();
        }
        cout << "completed checking the list" << endl;

    }
    cout << "list is sorted!" << endl;
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
