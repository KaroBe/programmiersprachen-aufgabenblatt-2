#include "window.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "vec2.hpp"
#include "color.hpp"

#include <vector>

#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>


int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    auto t = win.get_time();

    float x1{400 + 380 * std::sin(t)};
    float y1{400 + 380 * std::cos(t)};

    float x2{400 + 380 * std::sin(2.0f*t)};
    float y2{400 + 380 * std::cos(2.0f*t)};

    float x3{400 + 380 * std::sin(t-10.f)};
    float y3{400 + 380 * std::cos(t-10.f)};

    win.draw_point(x1, y1,
        1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    auto m = win.mouse_position();
    if (left_pressed) {
      win.draw_line(30, 30, // from
          m.first, m.second, // to
          1.0,0.0,0.0);
    }

    win.draw_line(0, m.second, 10, m.second, 0.0, 0.0, 0.0);
    win.draw_line(win.window_size().second - 10, m.second, win.window_size().second, m.second, 0.0, 0.0, 0.0);

    win.draw_line(m.first, 0, m.first, 10, 0.0, 0.0, 0.0);
    win.draw_line(m.first, win.window_size().second - 10, m.first, win.window_size().second, 0.0, 0.0, 0.0);

    std::string text = "mouse position: (" + std::to_string(m.first) + ", " + std::to_string(m.second) + ")";
    win.draw_text(10, 5, 35.0f, text);


    Color color2 {0.0f, 1.0f, 0.0f};

    // Draw Rectangle
    Rectangle square1{

      Vec2 {20.0f,200.0f}, 
      Vec2 {200.0f,400.0f},
      /*
      Vec2 {20.0f,400.0f}, 
      Vec2 {200.0f,200.0f}, 
      */
      Color {1.0f, 0.0f, 0.0f}
    };
    square1.draw(win);

    Rectangle square2{
      Vec2 {100.0f,400.0f}, 
      Vec2 {200.0f,500.0f}, 
      Color {1.0f, 0.0f, 0.0f}
    };

    square2.draw(win, color2);

    // Draw Circle
    Circle circle1
    {
      Vec2 {400.0f, 400.0f},
      200.0f,
      Color {1.0f, 0.0f, 0.0f} //rot
    };

    circle1.draw(win);
    
    Circle circle2
    {
      Vec2 {400.0f, 400.0f},
      100.0f,
      Color {1.0f, 0.0f, 0.0f} //rot
    };

    circle2.draw(win, color2);

    //blau zeichenen von Objekten, in denen sich der Mauszeiger
    //befindet

    //blau
    Color blau {0.0f, 0.0f, 1.0f};

    //Listen mit Objetkten
    std::vector<Circle> all_circles = {circle1, circle2};
    std::vector<Rectangle> all_rectangles = {square1, square2};

    //Mauszeiger
    Vec2 zeiger {(float)m.first, (float)m.second};
    
    //Iteration über Listen mit Objekten, Test ob Mauszeiger
    //Punkt in Objekt liegt, wenn ja, Objekt blau zeichnen

    for (int unsigned i = 0; i < all_circles.size(); ++i){
      if(all_circles[i].is_inside(zeiger) == true)
      {
        all_circles[i].draw(win,blau);
      }
    }
    
    for (int unsigned i = 0; i < all_rectangles.size(); ++i){
      if(all_rectangles[i].is_inside(zeiger) == true)
      {
        all_rectangles[i].draw(win,blau);
      }
    }    

    // Update Window
    win.update();
  }
  
  return 0;
}