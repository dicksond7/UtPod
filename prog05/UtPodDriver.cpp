/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    srand(time(NULL));



    //below is the actual driver

    UtPod t(512);
    cout << "shuffling..." << endl;
    t.shuffle();
    cout <<endl;
    cout <<"sorting..." <<endl;
    t.sortSongList();
    cout<<endl;

    Song s1("PlayBoi Carti", "4Real", 3);
    Song s2("PlayBoi Carti", "Magnolia", 3);
    Song s3("Post Malone", "Rockstar", 3);
    Song s4("Kodak Balck", "Dreamin", 3);
    Song s5("Drake", "Marvin's room", 3);
    Song s6("Kendrick Lamar", "Swimming Pools", 3);
    Song s7("Travis Scott", "Highest in the Room", 5);
    Song s8("Frank Ocean", "DHL", 6);
    Song s9("Kendrick Lamar", "Swimming Pools (extended remix)", 5);

    cout<< "adding more songs" << endl;
    cout<<endl;
    int result1 = t.addSong(s1);
    int result2 = t.addSong(s2);
    int result3 = t.addSong(s3);
    int result4 = t.addSong(s4);
    t.showSongList();
    cout << endl;
    cout<< "adding more songs" << endl;
    cout<<endl;
    int result5 = t.addSong(s5);
    int result6 = t.addSong(s6);
    int result7 = t.addSong(s7);
    int result8 = t.addSong(s8);
    int result9 = t.addSong(s9);
    t.showSongList();
    cout<< t.getRemainingMemory() << " MB left in UtPod" <<endl;
    cout << endl;
    cout << "sorting song list..." << endl;
    cout << endl;
    t.sortSongList();

    t.showSongList();
    cout << "\nShuffle 1: \n" << endl;
    t.shuffle();
    t.showSongList();
    cout << "\nShuffle 2: \n" << endl;
    t.shuffle();
    t.showSongList();
    cout << "\nShuffle 3: \n" << endl;
    t.shuffle();
    t.showSongList();

    cout << endl;
    cout << "sorting list..." <<endl << endl;
    t.sortSongList();
    t.showSongList();

    cout <<endl;
    cout << "removing " <<s4.getName() << " by " << s4.getArtist() <<endl;
    cout <<endl;
    t.removeSong(s4);

    t.showSongList();



    /*
    t.showSongList();
    Song s2("Beatles", "Hey Jude2", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;

    t.showSongList();

    Song s3("Beatles", "Hey Jude3", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;

    Song s4("Beatles", "Hey Jude4", 7);
    result = t.addSong(s4);
    cout << "result = " << result << endl;

    Song s5("Beatles", "Hey Jude5", 241);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    t.showSongList();

    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    t.showSongList();

    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;


    t.showSongList();

    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;
*/
    return 0;
}