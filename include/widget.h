#ifndef WIDGET_H
#define WIDGET_H

#include <SDL.h>
#include <colors.h>
#include <style.h>
#include <map>
#include <renderer.h>
#include <timeparams.h>

using namespace std;

namespace MediumCore{
    class Window;

    typedef struct{
        Window* parent;
        int x;
        int y;
        int xrel;
        int yrel;
        Uint32 button;
    }ActionEvent;

    class Widget{
        protected:
            typedef void (*Action)(Widget*, ActionEvent);

        protected:
            string name;
            SDL_Rect rect;
            Window* parent;
            
            bool isVisible;
            bool isDisabled;

        public:
            /**
             * \brief Widget style
             */
            Style style;

        public:
            Widget(Window* parent);

            virtual string GetName();
            virtual SDL_Rect GetRect();
            virtual bool IsVisible();
            virtual bool IsDisabled();

            virtual void SetName(string name);
            virtual void SetPos(int x, int y);
            virtual void SetSize(int w, int h);
            virtual void SetRect(SDL_Rect rect);
            virtual void SetVisible(bool v);
            virtual void SetDisable(bool d);

            virtual bool WidgetHit(int x, int y);

            virtual void OnKeyPressed(SDL_KeyboardEvent event);
            virtual void OnKeyReleased(SDL_KeyboardEvent event);

            virtual void OnMouseDown(SDL_MouseButtonEvent event);
            virtual void OnMouseUp(SDL_MouseButtonEvent event);
            virtual void OnMouseMove(SDL_MouseMotionEvent event);
            virtual void OnMouseWheel(SDL_MouseWheelEvent event, aPoint pos);

            virtual void Paint(Renderer &renderer) = 0;
    };
}

#endif