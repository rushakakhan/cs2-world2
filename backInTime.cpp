#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Defining a time of day
struct timeStruct
{
  string meridian; // Accepts either "AM" or "PM"
  int hour;
  int minute;
  int second;
};

timeStruct addMinutesToTime(timeStruct timeToChange, int minsToAdd) {
  int totalMins = timeToChange.minute + minsToAdd;
  timeToChange.hour = totalMins / 60 + timeToChange.hour;
  timeToChange.minute = totalMins % 60;
  if (timeToChange.hour > 12) {
    timeToChange.hour = timeToChange.hour - 12;
    if (timeToChange.meridian == "AM" || timeToChange.meridian == "am") {
      timeToChange.meridian = "PM";
    } else {
      timeToChange.meridian = "AM";
    }
  }
  return timeToChange;
}

// Adds 15 mins to time 
void snoozeAlarm(timeStruct & timeToChange) {
  timeToChange = addMinutesToTime(timeToChange, 15);
}

void printTime(timeStruct time) {
  cout << time.hour << ":";
  cout << setw(2) << setfill('0') << time.minute;
  if (time.second != 0) {
    cout << ":";
    cout << setw(2) << setfill('0') << time.second;
  }
  cout << " " << time.meridian;
}


int main() {

  timeStruct alarm = { "AM", 7, 30, 0 };
  int minutesToGetReady = 90;

  cout << "I'll be waking up at ";
  printTime(alarm);
  cout << " and I can start work at ";
  printTime(addMinutesToTime(alarm, minutesToGetReady));
  snoozeAlarm(alarm);
  cout << " unless I hit snooze, in which case I'd start at ";
  printTime(addMinutesToTime(alarm, minutesToGetReady));
  cout << "." << endl;
}