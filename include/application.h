#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <algorithm>
#include <thread>
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <GL/glu.h>
#include <windowsgroup.h>
#include <systemgroup.h>
#include <window.h>
#include <mainwindow.h>
#include <astring.h>
#include <colors.h>
#include <wparams.h>
#include <agl.h>
#include <aparams.h>
#include <timeparams.h>
#include <resources.h>

using namespace std;

namespace AbyssCore{
    class Application{
        private:
            static bool isRunning;

            static SDL_Window* window;

            static IWindowsGroup* group;

            static thread* render;

            static bool isResized;

            static SDL_GLContext glContext;

            static unsigned int globalVAO;
            static unsigned int globalVBO;

            static unsigned int framebuffer;
            static unsigned int framebufferTexture;

        private:
            static bool CreateSDLWindow();
            static void DisposeWindow();

            static void DrawWindow(Window* w);

            static void DrawWindowHead(Window* w);
            static void DrawWindowBody(Window* w);
            static void DrawWindowControl(Window* w);

            static void ProcessMouse(SDL_Event event);
            static void OnMouseDown(SDL_MouseButtonEvent event);
            static void OnMouseUp(SDL_MouseButtonEvent event);
            static void OnMouseMove(SDL_MouseMotionEvent event);
            static void OnMouseWheel(SDL_MouseWheelEvent event, aPoint pos);

            static bool WindowHit(Window* w, int x, int y);

            static void Input();
            static void Render();

            static void CreateFramebuffer();

        public:
            static bool Init();
            static void Start();
            static void Dispose();

            static IWindowsGroup* GetGroup();
            static bool IsRunning();

            static void Stop();
    };
}

#endif