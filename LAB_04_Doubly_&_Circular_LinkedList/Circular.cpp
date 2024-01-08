#include <iostream>
#include <string>
using namespace std;

class Song
{
public:
    string title;
    Song *next;
    Song *prev;

    Song(const string &songTitle) : title(songTitle), next(nullptr), prev(nullptr) {}
};

class MusicPlayer
{
private:
    Song *currentSong;
    Song *playlist;

public:
    MusicPlayer() : currentSong(nullptr), playlist(nullptr) {}

    void addSong(const string &title)
    {
        Song *newSong = new Song(title);

        if (playlist == nullptr)
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
        if (currentSong == nullptr)
        {
            cout << "No songs in the playlist." << endl;
            return;
        }

        currentSong = currentSong->next;
        playCurrentSong();
    }

    void playPreviousSong()
    {
        if (currentSong == nullptr)
        {
            cout << "No songs in the playlist." << endl;
            return;
        }

        currentSong = currentSong->prev;
        playCurrentSong();
    }

    void deleteSong(const string &title)
    {
        if (playlist == nullptr)
        {
            cout << "No songs in the playlist." << endl;
            return;
        }

        Song *current = playlist;

        do
        {
            if (current->title == title)
            {
                Song *songToDelete = current;

                if (songToDelete == currentSong)
                {
                    currentSong = currentSong->next;
                }

                if (playlist->next == playlist)
                {
                    playlist = nullptr;
                    currentSong = nullptr;
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
                return;
            }
            current = current->next;
        } while (current != playlist);

        cout << "Song not found in the playlist." << endl;
    }

    ~MusicPlayer()
    {
        // Clean up memory by deleting all remaining songs
        while (playlist != nullptr)
        {
            Song *songToDelete = playlist;
            playlist = playlist->next;
            delete songToDelete;
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
