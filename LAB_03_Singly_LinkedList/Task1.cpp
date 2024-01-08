#include <iostream>
#include <string>
using namespace std;
class SongCollection
{
public:
    string name;
    int favoriteLevel;
    SongCollection *next;

    SongCollection(string name, int favoriteLevel)
    {
        this->name = name;
        this->favoriteLevel = favoriteLevel;
        this->next = nullptr;
    }
};

class PlaylistManager
{
private:
    SongCollection *head;

public:
    PlaylistManager()
    {
        head = nullptr;
    }

    void addSong(string name, int favoriteLevel)
    {
        SongCollection *newSong = new SongCollection(name, favoriteLevel);

        if (!head || favoriteLevel == 2)
        {
            newSong->next = head;
            head = newSong;
        }
        else
        {
            SongCollection *current = head;
            SongCollection *previous = nullptr;

            while (current && current->favoriteLevel != 2)
            {
                previous = current;
                current = current->next;
            }

            if (previous)
            {
                previous->next = newSong;
            }

            newSong->next = current;
        }
    }

    void deleteSong(string name)
    {
        if (!head)
        {
            cout << "Playlist is empty." << endl;
            return;
        }

        if (head->name == name)
        {
            SongCollection *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        SongCollection *current = head;
        SongCollection *previous = nullptr;

        while (current && current->name != name)
        {
            previous = current;
            current = current->next;
        }

        if (!current)
        {
            cout << "Song not found in the playlist." << endl;
            return;
        }

        previous->next = current->next;
        delete current;
    }

    void searchSong(string name)
    {
        SongCollection *current = head;

        while (current)
        {
            if (current->name == name)
            {
                cout << "Song Name: " << current->name << ", Favorite Level: " << current->favoriteLevel << endl;
                return;
            }
            current = current->next;
        }

        cout << "Song not found in the playlist." << endl;
    }

    void printPlaylist()
    {
        if (!head)
        {
            cout << "Playlist is empty." << endl;
            return;
        }

        SongCollection *current = head;
        int position = 1;

        while (current)
        {
            cout << position << ". Song Name: " << current->name << ", Favorite Level: " << current->favoriteLevel << endl;
            current = current->next;
            position++;
        }
    }

    void playPlaylist()
    {
        SongCollection *current = head;

        while (current)
        {
            cout << "Now Playing: " << current->name << endl;
            cout << "Press 'n' to play the next song or any other key to stop: ";
            char choice;
            cin >> choice;

            if (choice != 'n')
            {
                cout << "Playback stopped." << endl;
                break;
            }

            current = current->next;
        }
    }

    ~PlaylistManager()
    {
        while (head)
        {
            SongCollection *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    PlaylistManager playlist;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Add a Song\n";
        cout << "2. Delete a Song\n";
        cout << "3. Search for a Song\n";
        cout << "4. Print Playlist\n";
        cout << "5. Play Playlist\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string name;
            int favoriteLevel;

            cout << "Enter the song name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Choose favorite level (1: Top Favorite,  2: Custom, 3: Least Favorite): ";
            cin >> favoriteLevel;

            if (favoriteLevel == 3)
            {
                int customLevel;
                cout << "Enter custom favorite level: ";
                cin >> customLevel;
                playlist.addSong(name, customLevel);
            }
            else
            {
                playlist.addSong(name, favoriteLevel);
            }

            cout << "Song added successfully." << endl;
            break;
        }
        case 2:
        {
            string name;
            cout << "Enter the song name to delete: ";
            cin.ignore();
            getline(cin, name);
            playlist.deleteSong(name);
            cout << "Song deleted successfully." << endl;
            break;
        }
        case 3:
        {
            string name;
            cout << "Enter the song name to search: ";
            cin.ignore();
            getline(cin, name);
            playlist.searchSong(name);
            break;
        }
        case 4:
            playlist.printPlaylist();
            break;
        case 5:
            playlist.playPlaylist();
            break;
        case 6:
            cout << "Exiting the program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
