#include <iostream>
#include "Playlist.h"
#include <string>
using namespace std;

PlaylistNode::PlaylistNode(){
  uniqueID = "none";
  songName = "none";
  artistName = "none";
  songLength = 0;
  nextNodePtr = 0;
}

PlaylistNode::PlaylistNode(string id, string song, string artist, int length){
  this->uniqueID = id;
  this->songName = song;
  this->artistName = artist;
  this->songLength = length;
  nextNodePtr = nullptr;
}

void PlaylistNode::InsertAfter(PlaylistNode *nextPtr){
  PlaylistNode* temp = nullptr;
  temp = this->nextNodePtr;
  this->SetNext(nextPtr);
  nextPtr->SetNext(temp);
}

void PlaylistNode::SetNext(PlaylistNode* nextPtr){
  if (nextPtr == nullptr){
    nextNodePtr = nullptr;
  }
  else{
    nextNodePtr = nextPtr;
  }
}

string PlaylistNode::GetID(){
  return this->uniqueID;
}

string PlaylistNode::GetSongName(){
  return this->songName;
}

string PlaylistNode::GetArtistName(){
  return this->artistName;
}

int PlaylistNode::GetSongLength(){
  return this->songLength;
}

PlaylistNode* PlaylistNode::GetNext(){
  return nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode(){
  cout << "Unique ID: " << uniqueID << endl;
  cout << "Song Name: " << songName << endl;
  cout << "Artist Name: " << artistName << endl;
  cout << "Song Length (in seconds): " << songLength << endl;
  //cout << endl;
}



