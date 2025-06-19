#include <iostream>
using namespace std;
/*
    Abstraction - Hiding internal details and only show relevent information to user.
    We are going to create a TeleVision Class.

    <------- Need to think------->
    1. To start television why a user need to know that red and green wire need to connect, we simply provide a interface(button) for this
    2. Same for change channel , volume up & down and start and stop TV.
*/

class Television
{
private:
    bool isOn;
    int currentChannel;
    int currentVolume;
    string brand;

public:
    // constructor to initialise tv
    Television(const string& name)
    {
        // let's suppose when tv is manufactured this is default setting they provide.

        this->brand = name;
        isOn = false;
        currentChannel = 1;
        currentVolume = 10;
    }

    // first on tv
    void TurnOn()
    {
        // why anyone to need how tv ON under the hood. if anyone know then that is right.
        if (isOn)
        {
            cout << "TV is already ON. Enjoy your day!." << endl;
            return;
        }
        else
        {
            isOn = true;
            cout << "TV is ON , now . Enjoy your day !. " << endl;
            cout << "Current Channel is: " << currentChannel << endl;
            cout << "Current volume is: " << currentVolume << endl;
        }
    }

    // first on tv
    void TurnOFF()
    {
        if (!isOn)
        {
            cout << "TV is already OFF." << endl;
            return;
        }
        else
        {
            isOn = false;
            cout << "TV is OFF . " << endl;
        }
    }

    // change channel
    void NextChannel()
    {
        if (!isOn)
        {
            cout << "Turn ON first." << endl;
        }
        else
        {
            if (currentChannel >= 100)
            {
                cout << "Sorry!. This is last channel . You can visit previous channels " << endl;
                return;
            }
            else
            {
                currentChannel++;
                cout << "Your channel is changed to : " << currentChannel << endl;
            }
        }
    }

    // change channel
    void PrevChannel()
    {
        if (!isOn)
        {
            cout << "Turn ON first." << endl;
        }
        else
        {
            if (currentChannel <= 1)
            {
                cout << "Sorry! This is the first channel. Try going forward instead." << endl;

                return;
            }
            else
            {
                currentChannel--;
                cout << "Your channel is changed to : " << currentChannel << endl;
            }
        }
    }

    // change volume
    void VolumeUp()
    {
        if (!isOn)
        {
            cout << "Turn ON first." << endl;
        }
        else
        {
            if (currentVolume >= 50)
            {
                cout << "Max VolumeⓂ️Ⓜ️Ⓜ️. Max VolumeⓂ️Ⓜ️Ⓜ️ " << endl;
                return;
            }
            else
            {
                currentVolume++;
                cout << "Volume up . current volume is " << currentVolume << endl;
            }
        }
    }

    void VolumeDown()
    {
        if (!isOn)
        {
            cout << "Turn ON first." << endl;
        }
        else
        {
            if (currentVolume <= 0)
            {
                cout << "Min VolumeⓂ️Ⓜ️Ⓜ️. Min VolumeⓂ️Ⓜ️Ⓜ️ " << endl;
                return;
            }
            else
            {
                currentVolume--;
                cout << "Volume down . current volume is " << currentVolume << endl;
            }
        }
    }

    void DisplayStatus() const
    {
        cout << "Brand: " << brand << endl;
        cout << "Power: " << (isOn ? "On" : "Off") << endl;
        cout << "Channel: " << currentChannel << endl;
        cout << "Volume: " << currentVolume << endl;
    }

    ~Television()
    {
        cout<<"**********************"<<endl;
        cout << "Television object (" << brand << ") destroyed." << endl;
    }
};

int main()
{
    // create a TV with new brand
    Television sony("Sony New");
    sony.TurnOn();
    cout << "================" << endl;
    sony.NextChannel();
    sony.PrevChannel();

    sony.VolumeUp();
    sony.VolumeDown();
    return 0;
}