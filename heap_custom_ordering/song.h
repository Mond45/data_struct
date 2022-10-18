#ifndef __SONG_H__
#define __SONG_H__

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include "priority_queue.h"

using namespace std;

class Song
{
public:
    std::string artist, title;
    int count;

    Song() {}
    Song(const Song &s) : artist(s.artist), title(s.title), count(s.count) {}
    Song(std::string artist, std::string title, int count) : artist(artist), title(title), count(count) {}

    friend std::ostream &operator<<(std::ostream &out, const Song &s)
    {
        return out << "Artist: " << s.artist << " Title: " << s.title << " count: " << s.count;
    }
};

//  you have to write something below this line
//  you *MIGHT* have to change the declaration of pq1 and pq2

struct Comp1
{
    bool operator()(const Song &a, const Song &b) const
    {
        // artist then song
        if (a.artist == b.artist)
            return a.title > b.title;
        return a.artist > b.artist;
    }
};

struct Comp2
{
    bool operator()(const Song &a, const Song &b) const
    {
        // sales
        if (a.count < b.count)
            return true;
        else if (a.count > b.count)
            return false;
        else if (a.artist > b.artist)
            return true;
        else if (a.artist < b.artist)
            return false;
        else if (a.title > b.title)
            return true;
        return false;
    }
};

CP::priority_queue<Song, Comp1> pq1;
CP::priority_queue<Song, Comp2> pq2;

#endif
