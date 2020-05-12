#include <iostream>
using namespace std;
#include <fstream>
#include <sstream>
#include "GenreHash.hpp"

int main()
{
  GenreHash test(9);
  string title, artist, genre, plays, filename;
  filename = "ReadFile.txt";
  ifstream inFile;
  inFile.open(filename);
  if(inFile.fail())
  {
    cout << "Read File Failed";
    return 0;
  }
  else
  {
    string line;
    while(getline(inFile,line))
    {
        stringstream ss;
        ss<<line;

        getline(ss, title, ',');
        getline(ss, artist, ',');
        getline(ss, genre, ',');
        getline(ss, plays, ',');

        test.add(title, genre, artist, stoi(plays));
    }
  }

  while(true)
  {
  string userN;
  cout << endl << "Please enter your username" << endl;
  getline(cin, userN);


  User *curr_user = test.searchUser(userN);
  if(curr_user == NULL)
  {
    curr_user =test.addUser(userN);
  }

  string sChoice;
  int choice = 1;
  while(choice != 9)
  {
    cout << endl;
    cout << "============Main Menu============" << endl;
    cout << "Please select an option." << endl;
    cout << "1. Print entire library" << endl;
    cout << "2. Get Genre Counts" << endl;
    cout << "3. Add Song to my library" << endl;
    cout << "4. Delete Song from my library" << endl;
    cout << "5. Print my library" << endl;
    cout << "6. Get Recommended Playlist" << endl;
    cout << "7. See Global Top Charts" << endl;
    cout << "8. See Genre Top 10s" << endl;
    cout << "9. Log Out" << endl;
    cout << "0. Quit Program" << endl;
    getline(cin, sChoice);
    choice = stoi(sChoice);

    if(choice == 1)
    {
      test.printTable();
    }
    else if(choice == 2)
    {
      test.getGenreCount();
    }
    else if(choice == 3)
    {
      string stitle, sgenre;
      cout << "Enter a song you would like to add." << endl;
      getline(cin, stitle);
      cout << "What genre is this song? " << endl;
      getline(cin, sgenre);
      Song *sSong = test.searchSong(stitle, sgenre);
      //cout << "sSong " << sSong->title << endl;
      test.addSongToPlaylist(sSong, curr_user);
    }
    else if(choice == 4)
    {
      cout << "Feature not ready yet! Stay tuned!" << endl;
    }
    else if(choice == 5)
    {
      test.printUserPlaylist(curr_user);
    }

    else if(choice == 6)
    {
      //cout << "Feature not ready yet! Stay tuned!" << endl;
      
      cout << endl;
      string sMood;
      int mood;
      cout << "What do you want?" << endl;
      cout << "1. Gloomy" << endl;
      cout << "2. New" << endl;
      cout << "3. Memory" << endl;
      cout << "4. Tired" << endl;
      cout << "5. Love" << endl;

      getline(cin, sMood);
      mood = stoi(sMood);

      if(mood == 1){
        cout << "Modern Loneliness - Lauv" << endl;
      }
      else if(mood == 2){
        cout << "Love Like That - Lauv" << endl;
      }
      else if(mood == 3){
        cout << "Never Not - Lauv" << endl;
      }
      else if(mood == 4){
        cout << "I'm so tired... - Lauv" << endl;
      }
      else if(mood == 5){
        cout << "I Like Me Better - Lauv" << endl;
      }
    }

    else if(choice == 7)
    {
      cout << "Feature not ready yet! Stay tuned!" << endl;
    }
    else if(choice == 8)
    {
        string genre;
        cout << "Which genre's Top 10 would you like to see? " << endl;
        getline(cin, genre);
        test.printGenreTop10(genre);
    }

    if(choice == 0)
    {
      cout << "Goodbye!" << endl;
      return 0;
    }
  }
}

   // test.printTable();
   //test.getGenreCount();


}
