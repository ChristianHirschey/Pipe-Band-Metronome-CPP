#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <Windows.h>

using namespace std;

void playMetronome(int bpm, int duration, string output) {
    chrono::milliseconds interval(static_cast<int>(60000.0 / (bpm + 1)));//the function ends up running about 1 bpm slow due to the time it takes to call PlaySound() so the input bpm gets incremented prior to dividing for the interval

    for (int i = 0; i < duration; i++) {
        cout << output;
        PlaySound("C:\\Users\\Chris\\source\\repos\\Console Metronome\\assets\\metronome.wav", NULL, SND_FILENAME | SND_ASYNC);
        this_thread::sleep_for(interval);
    }
}

void msr() {
    int mTempo, mPart, sTempo, sPart, rTempo, rPart; //initialize variables for the march, strathspey and reel tempos & part #'s

    cout << "What is the tempo of your march?\n";
    cin >> mTempo;
    cout << "How many parts is your march?\n";
    cin >> mPart;
    int mLen = (mPart * 32) + 15; //8 beats for tempo, 8 for attack roll - 1 at end for transition to strathspey, 32 per part

    cout << "What is the tempo of your strathspey?\n";
    cin >> sTempo;
    cout << "How many parts is your strathspey?\n";
    cin >> sPart;
    int sLen = (sPart * 32) + 1; //32 per part + 1 for transition to reel

    cout << "What is the tempo of your reel?\n";
    cin >> rTempo;
    cout << "How many parts is your reel?\n";
    cin >> rPart;
    int rLen = (rPart * 16) + 1; //16 per part + 1 for transition

    system("cls"); //clears the console to improve visibility

    playMetronome(mTempo, mLen, "|||||"); //calling metronome function with march tempo and length
    playMetronome(sTempo, sLen, "\\\\\\\\\\"); //calling metronome function with strathspey tempo and length
    playMetronome(rTempo, rLen, "!!!!!"); //calling metronome function with reel tempo and length
}

void medley() {
    int oTempo, oPart, jTempo, jPart, slTempo, slLen, sTempo, sPart, rTempo, rPart; //initialize variable for the tempo and part count of the opener, jig(s), slow air, strathspey(s), and reel(s), as well as empty int for extra beats

    cout << "What is the tempo of your opener?\n";
    cin >> oTempo;
    cout << "How many parts is your opener?\n";
    cin >> oPart;
    int oLen = (oPart * 32) + 15; //8 for tempo, 8 for attack rolls - 1 for jig transition, 32 per part

    cout << "What is the tempo of your jig(s)?\n";
    cin >> jTempo;
    cout << "How many parts are your jig(s)?\n";
    cin >> jPart;
    int jLen = (jPart * 32) + 2; //32 per part + 2 for transition

    cout << "What is the tempo of your slow air?\n";
    cin >> slTempo;
    cout << "How many beats is your slow air?\n";
    cin >> slLen;

    cout << "What is the tempo of your strathspeys?\n";
    cin >> sTempo;
    cout << "How many parts are your strathspeys?\n";
    cin >> sPart;
    int sLen = (sPart * 32) + 2; //32 per part + 2 for transition

    cout << "What is the tempo of your reels?\n";
    cin >> rTempo;
    cout << "How many parts are your reels?\n";
    cin >> rPart;
    int rLen = (rPart * 16) + 1; //16 per part + 1 for transition

    system("cls"); //clears the console to improve visibility

    playMetronome(oTempo, oLen, "|||||");
    playMetronome(jTempo, jLen, "^^^^^");
    playMetronome(slTempo, slLen, "_____");
    playMetronome(sTempo, sLen, "\\\\\\\\\\");
    playMetronome(rTempo, rLen, "!!!!!");
}

int main() {
    int bpm, duration;
    string metType;

    cout << "Normal, MSR, or Medley Metronome?\n";
    cin >> metType;

    if (metType == "MSR") {
        msr();
    }
    else if (metType == "Medley") {
        medley();
    }
    else if (metType == "Normal") {
        cout << "What tempo do you want the metronome to run at?\n";
        cin >> bpm;

        cout << "How many beats should the metronome run for?\n";
        cin >> duration;

        playMetronome(bpm, duration, "|||||");
    }
    else {
        cout << "Invalid Type";
    }

    return 0;
}