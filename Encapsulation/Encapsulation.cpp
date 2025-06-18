#include <iostream>
using namespace std;

// this is concreate class
// encapsulation means binding data and member function in single class + data security.
// we make data private and function as public so that we can validate input

class MusicPlayer
{
private:
    string playerName;
    int currentSong;

    int volume;
    bool isOn;

public:
    MusicPlayer(string playerName)
    {
        isOn = false;
        currentSong = 1;
        volume = 10;
        setPlayerName(playerName);
    }

    // set player name
    void setPlayerName(string name)
    {
        this->playerName = name;
    }

    // start player
    void StartPlayer()
    {
        if (isOn)
        {
            cout << "Player is already on. Enjoy with play song " << endl;
        }
        else
        {
            isOn = true;
            cout << "Player started now " << endl;
        }
    }

    // start player
    void TurnOffPlayer()
    {
        if (!isOn)
        {
            cout << "Player is already off." << endl;
        }
        else
        {
            isOn = false;
            cout << "Player off now " << endl;
        }
    }

    //  play music player
    void playSong()
    {
        if (!isOn)
        {
            cout << "Please start music player first." << endl;
        }
        else
        {
            cout << "Music player start " << currentSong << endl;
            cout << "Volume " << volume << endl;
        }
    }

    // change song
    void NextSong()
    { // let's suppose there are 100 songs
        if (!isOn)
        {
            cout << "Please start music player first." << endl;
        }
        else
        {
            if (currentSong >= 100)
            {
                cout << "Next song is not available. " << endl;
                return;
            }
            else
            {
                currentSong++;
                cout << "Song changed . current song is " << currentSong << endl;
            }
        }
    }

    // prev song
    void PrevSong()
    { // first song at 1
        if (!isOn)
        {
            cout << "Please start music player first." << endl;
        }
        else
        {
            if (currentSong <= 1)
            {
                cout << "It is already at min song . please click on next button " << currentSong << endl; // later we create shuffle
                return;
            }
            else
            {
                currentSong--;
            }
        }
    }

    // volume up
    void VolumeUp()
    {
        if (!isOn)
        {
            cout << "Player is Off. Start first " << endl;
        }
        else
        {
            if (volume >= 100)
            {
                cout << "volume is already at max capacity . " << endl;
                return;
            }
            else{
                volume++;
                cout << "Volume increased. Current volume: " << volume << endl;

            }
            

        }
    }

    // volume down
    void VolumeDown()
    {
        if (!isOn)
        {
            cout << "Player is Off. Start first " << endl;
        }
        else
        {

            if (volume <= 0)
            {
                cout << "Can't decrease now. It is already at min sound." << endl;
                return;
            }
            else{
                volume--;
                cout << "Volume decreased. Current volume: " << volume << endl;

            }
            
        }
    }

    // display music player status
    void DisplayStatus() const
    {
        cout << "Player Name: " << playerName << endl;
        cout << "Current Song: " << currentSong << endl;
        cout << "Volume: " << volume << endl;
        cout << "Player is " << (isOn ? "On" : "Off") << endl;
    }

    // destructor
    ~MusicPlayer()
    {
        cout << "Destructor for music player " << playerName << endl;
    }
};

int main()
{
    MusicPlayer m1("MIVI");
    m1.StartPlayer(); // start player isOn = true
    m1.NextSong();    // song changed to 2
    m1.PrevSong();    // song changed to 1
    

    m1.VolumeDown(); // volume down
    m1.VolumeUp();   // volume up

    m1.playSong(); // play music
    cout<<"============="<<endl;
    m1.DisplayStatus();
    return 0;
}