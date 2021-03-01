#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;
#define ms 1000

std::vector<std::pair<int, int>> mouse_pointer;

void GetCursorPosition()
{
  POINT point;
  if (GetCursorPos(&point)) {
    cout <<"X: "<< point.x << "," <<" Y: "<< point.y << "\n";
    mouse_pointer.push_back(std::pair<int, int>(point.x, point.y));
  }
}

static void SetCursorPosition()
{
  std::cout << "\nOpen the page without closing the console window.\n\
It will start in 15 secs.\n\
To stop the process close the console window.\n";

  Sleep(15 * ms);

  while (true)
  {
    for (auto pointers : mouse_pointer)
    {
      int randomNumber = rand() % 10 + 1;
      SetCursorPos(pointers.first, pointers.second);
      for (int click = 0; click < randomNumber; ++click)
      {
        mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        Sleep(2 * ms);
      }
    }
  }
}

void GetAndSetMousePointer()
{
  unsigned int TotalMousePointers = 0, duration = 0;
  std::cout << "Enter the number of mouse pointers: ";
  std::cin >> TotalMousePointers;
duration:
  std::cout << "Enter the duration to record the next coordinate (greater than 3): ";
  std::cin >> duration;
  if (duration < 3)
  {
    std::cout << "Please enter the duration greated than 3.\n";
    goto duration;
  }
  system("cls");
  while (TotalMousePointers > 0)
  {
    std::cout << "Keep your mouse pointer before "<< duration <<" secs and wait for the sound.\n";
    Sleep(duration * ms);
    GetCursorPosition();
    std::cout << '\a';
    --TotalMousePointers;
  }

}

void SetMousePointer()
{
  unsigned int TotalMousePointers = 0;
  LONG xPoint, yPoint;
  unsigned int count = 1;
  std::cout << "Enter the number of mouse pointers: ";
  std::cin >> TotalMousePointers;
  while (TotalMousePointers > 0)
  {
    std::cout << "Enter the x - coordinate for the mouse point " << count << " : ";
    std::cin >> xPoint;
    std::cout << "Enter the y - coordinate for the mouse point " << count << " : ";
    std::cin >> yPoint;
    mouse_pointer.push_back(std::pair<int, int>(xPoint, yPoint));
    --TotalMousePointers;
    ++count;
  }
}

int main()
{
  unsigned int choice = 0;

  std::cout << "Enter the below option.\n\
    1 - For get and set of the mouse pointer.\n\
    2 - To set the pointer co-ordinates manually." << std::endl;
  std::cout << "Enter your choice: ";
  std::cin >> choice;

  if (choice == 1)
    GetAndSetMousePointer();
  else if (choice == 2)
    SetMousePointer();

  SetCursorPosition();

  system("pause");
}
