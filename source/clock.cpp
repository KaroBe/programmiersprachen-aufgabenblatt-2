#include "window.hpp"
#include "circle.hpp"
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

    float pi = (float) M_PI;

    auto t = win.get_time();
    std::string text = std::to_string(t);
    win.draw_text(10, 5, 35.0f, text);

/*
    6.28 s = 2*pi = 1 Umdrehung
    2*pi/60 * t = 60stel Umdrehung * t
*/
    float factor_h = 2*pi/(60*60*24);
    float factor_m = 2*pi/(60*60);
    float factor_s = 2*pi/(60);

    //rot Stunden
    float x1{400 + 240 * std::sin(factor_h * t)};
    float y1{400 + 240 * std::cos(-1 * factor_h * t + pi)};

    //grün Minuten
    float x2{400 + 290 * std::sin(factor_m * t)};
    float y2{400 + 290 * std::cos(-1 * factor_m * t + pi)};

    //blau Sekunden
    float x3{400 + 340 * std::sin(factor_s * t)};
    float y3{400 + 340 * std::cos(-1 * factor_s * t + pi)};

    //Zeiger
    //rot Stunden
    win.draw_line(400, 400, x1, y1, 1.0f, 0.0f, 0.0f);
    //grün Minuten
    win.draw_line(400, 400, x2, y2, 0.0f, 1.0f, 0.0f);
    //blau Sekunden
    win.draw_line(400, 400, x3, y3, 0.0f, 0.0f, 1.0f);

    //Uhrblatt
    Circle uhr {{400.0f,400.0f}, 350.0f, {0.5f, 0.5f, 0.5f}};
    uhr.draw(win);

    win.update();

  }

  return 0;
}