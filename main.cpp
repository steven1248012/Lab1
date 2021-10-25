#include <iostream>
#include <string>
#include "Playlist.h"
using namespace std;


void PrintMenu(string title);

int main(){
  string title = " ";
  cout << "Enter playlist's title:" << endl;
  getline(cin,title);
  cout << endl;
  PrintMenu(title);
  return 0;
}

void PrintMenu(string title){
  char userChoice = ' ';
  string id = " ";
  string songName = " ";
  string artistName = " ";
  int songLength = 0;
  PlaylistNode* head = nullptr;
  PlaylistNode* tail = nullptr;
  PlaylistNode* curr;
  PlaylistNode* prev;
  PlaylistNode* temp = nullptr;
  PlaylistNode* node = nullptr;

  while (userChoice != 'q'){
    userChoice = ' ';
    cout << title << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
  
    while (userChoice != 'a' && userChoice != 'd' && userChoice != 'c'  &&userChoice != 's' && userChoice != 't' && userChoice != 'o' &&   userChoice != 'q'){
      cout << "Choose an option:" << endl;
      cin >> userChoice;
    }
  switch(userChoice){
    case 'a':{
      cout << "ADD SONG" << endl;
      cout << "Enter song's unique ID:" << endl;
      cin >> id;
      cin.ignore();
      cout << "Enter song's name:" << endl;
      getline(cin,songName);
      cout << "Enter artist's name:" << endl;
      getline(cin,artistName);
      cout << "Enter song's length (in seconds):" << endl;
      cin >> songLength;

      node = new PlaylistNode(id,songName,artistName,songLength);
      if (head == nullptr){
        head = node;
        tail = node;
      }
      else{
        tail->InsertAfter(node);
        tail = tail->GetNext();
      }
      cout << endl;
      break;
    }
    
    case 'd':{
      string removeUniqueID;
      bool x;
      cout << "REMOVE SONG" << endl;
      cout << "Enter song's unique ID:" << endl;
      cin >> removeUniqueID;
      if (head == nullptr){
        cout << "Playlist is empty" << endl;
        break;
      }
      curr = head;
      prev = nullptr;

      while (curr->GetID() != removeUniqueID){
        prev = curr;
        curr = curr->GetNext();
      }
      if (curr->GetID() == removeUniqueID){
        x = true;
      }
      if (x == true){
        if (prev != nullptr){
          temp = curr;
          prev->SetNext(temp->GetNext());
          delete temp;
          cout << "\"" << curr->GetSongName() << "\" removed." << endl;
          cout << endl;
        }   
      }
      break;
    }

    case 'c':{
      int songPosition;
      int newPosition;
      cout << "CHANGE POSITION OF SONG" << endl;
      cout << "Enter song's current position:" << endl;
      cin >> songPosition;
      cout << "Enter new position for song:" << endl;
      cin >> newPosition;

      if (songPosition < 1){
        songPosition = 1;
      } 
      if (head == nullptr){
        cout << "Playlist is empty" << endl;
        cout << endl;
      }
      prev = nullptr;
      curr = head;
      if (songPosition == 1){
        temp = head;
        head = head->GetNext();
      }

      for (int i = 1; i < songPosition; ++i){
        prev = curr;
        curr = curr->GetNext();
      }

      if ((curr != nullptr) && (songPosition != 1)){
        temp = curr;
        curr = curr->GetNext();
        prev->SetNext(curr);
      }
      curr = head;
      prev = nullptr;

      for (int j = 1; j < newPosition - 1; ++j){
        prev = curr;
        curr = curr->GetNext();
        
        if (curr == nullptr){
          curr = tail;
        }
      }

      if ((curr != nullptr) && (newPosition != 1)){
        if (curr->GetNext() != nullptr){
          curr->InsertAfter(temp);
        }
        if (curr->GetID() == tail->GetID()){
          curr->SetNext(temp);
          temp->SetNext(nullptr);
          tail = temp;
        }
        cout << "\"" << temp->GetSongName() << "\"" << " moved to position " << newPosition << endl;
        cout << endl;
      }
      if (newPosition == 1){
        curr = head;
        head = temp;
        head->SetNext(curr);
      }
      break;
    }

    case 's':{
      string artist;
      cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
      cout << "Enter artist's name:" << endl;
      cout << endl;
      cin.ignore();
      getline(cin,artist);
      int counter = 1;
      curr = head;
      if (head == nullptr){
        cout << "Playlist is empty" << endl;
      }
      while (curr != nullptr){
        if (curr->GetArtistName() == artist){
          cout << counter << "." << endl;
          curr->PrintPlaylistNode();
          cout << endl;
        }
        curr = curr->GetNext();
        ++counter;
      }
      break; 
    }

    case 't':{
      int totalTime = 0;
      cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
      curr = head;
      
      while (curr != nullptr){
        totalTime += curr->GetSongLength();
        curr = curr->GetNext();
      }
      cout << "Total time: " << totalTime << " seconds" << endl;
      cout << endl;
      break;
    }
    
    case 'o':{
      cout << title << " - OUTPUT FULL PLAYLIST" << endl;
      if (head == nullptr){
        cout << "Playlist is empty" << endl;
      }
      else{
        int count = 1;
        for (PlaylistNode* i = head; i != nullptr; i = i->GetNext()){
          cout << count << "." << endl;
          i->PrintPlaylistNode();
          if (i->GetNext() != nullptr){
            cout << endl;
          }
          ++count;
        }
      } 
      cout << endl; 
    }
  }
  }
}
