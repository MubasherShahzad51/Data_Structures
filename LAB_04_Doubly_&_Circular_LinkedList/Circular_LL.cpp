#include <iostream>
#include <string>
using namespace std;
class Song
{
public:
    string title;
    Song *next;
    Song *prev;

    Song(const string &songTitle)
    {
        this->title = songTitle;
        this->next = NULL;
        this->prev = NULL;
    }
};

class MusicPlayer
{
private:
    Song *currentSong;
    Song *playlist;

public:
    MusicPlayer()
    {
        this->currentSong = NULL;
        this->playlist = NULL;
    }

    void addSong(const string &title)
    {
        Song *newSong = new Song(title);

        if (playlist == NULL)
        {
            playlist = newSong;
            playlist->next = playlist;
            playlist->prev = playlist;
            currentSong = playlist;
        }
        else
        {
            newSong->next = playlist;
            newSong->prev = playlist->prev;
            playlist->prev->next = newSong;
            playlist->prev = newSong;
        }
    }

    void playCurrentSong()
    {
        if (currentSong)
        {
            cout << "Playing: " << currentSong->title << endl;
        }
        else
        {
            cout << "No songs in the playlist." << endl;
        }
    }

    void playNextSong()
    {
        if (currentSong == NULL)
        {
            cout << "No songs in the playlist." << endl;
            return;
        }

        currentSong = currentSong->next;
        playCurrentSong();
    }

    void playPreviousSong()
    {
        if (currentSong == NULL)
        {
            cout << "No songs in the playlist." << endl;
            return;
        }

        currentSong = currentSong->prev;
        playCurrentSong();
    }
    void deleteSong(const string &title)
    {
        if (playlist == NULL)
        {
            cout << "No songs in the playlist." << endl;
            return;
        }

        Song *songToDelete = NULL;
        Song *current = playlist;

        do
        {
            if (current->title == title)
            {
                songToDelete = current;
                break;
            }
            current = current->next;
        } while (current != playlist);

        if (songToDelete)
        {
            if (songToDelete == currentSong)
            {
                currentSong = currentSong->next;
            }

            if (playlist->next == playlist)
            {
                playlist = NULL;
                currentSong = NULL;
            }
            else
            {
                songToDelete->prev->next = songToDelete->next;
                songToDelete->next->prev = songToDelete->prev;
                if (songToDelete == playlist)
                {
                    playlist = songToDelete->next;
                }
            }

            delete songToDelete;
            cout << "Song '" << title << "' deleted successfully." << endl;
        }
        else
        {
            cout << "Song not found in the playlist." << endl;
        }
    }
};

int main()
{
    MusicPlayer player;
    int choice;

    do
    {
        cout << "\nMenu Options:" << endl;
        cout << "1. Add Song" << endl;
        cout << "2. Play Current Song" << endl;
        cout << "3. Play Next Song" << endl;
        cout << "4. Play Previous Song" << endl;
        cout << "5. Delete Song" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            string title;
            cout << "Enter song title: ";
            getline(cin, title);
            player.addSong(title);
            break;
        }
        case 2:
            player.playCurrentSong();
            break;
        case 3:
            player.playNextSong();
            break;
        case 4:
            player.playPreviousSong();
            break;
        case 5:
        {
            string title;
            cout << "Enter the song title to delete: ";
            cin.ignore();
            getline(cin, title);
            player.deleteSong(title);
            break;
        }

        case 6:
            cout << "Exiting the music player." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
