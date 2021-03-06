#ifndef WINDOWSGROUP_H
#define WINDOWSGROUP_H

#include <SDL.h>
#include <window.h>
#include <vector>

#define START_ID 0

using namespace std;

namespace MediumCore{
    class IWindowsGroup{
        public:
            virtual vector<Window*> GetPull() = 0;
            virtual vector<Window*> GetInvertedPull() = 0;
            virtual bool Create(Window* window, string byName) = 0;
            virtual bool Destroy(Window* window) = 0;
            virtual Window* Find(string byName) = 0;
            virtual void FocusWindow(Window* window) = 0;
            // virtual void SetBackground(Window* window) = 0;
            virtual Window* CurrentFocus() = 0;
            // virtual Window* Background() = 0;
            virtual void ProcessWindows() = 0;
    };
}

#endif