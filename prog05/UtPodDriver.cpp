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
    srand(time(nullptr));


    //below is the actual driver

    UtPod t(512);
    Song s1("PlayBoi Carti", "Lean4Real", 3);
    Song s2("PlayBoi Carti", "Magnolia", 3);
    Song s3("Post Malone", "Rockstar", 3);
    Song s4("Kodak Balck", "Codine Dreamin", 3);
    Song s5("Drake", "Marvin's room", 3);
    Song s6("Kendrick Lamar", "Swimming Pools", 3);
    int result1 = t.addSong(s1);
    int result2 = t.addSong(s2);
    int result3 = t.addSong(s3);
    int result4 = t.addSong(s4);
    int result5 = t.addSong(s5);
    int result6 = t.addSong(s6);
    t.showSongList();
    cout << "\n" << endl;
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

    cout << "\n" << endl;
    t.sortSongList();
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