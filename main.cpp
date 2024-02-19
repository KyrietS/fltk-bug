#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_draw.H>
#include <iostream>

struct MyWidget : Fl_Widget
{
    MyWidget(int x, int y, int w, int h, const char* label) : Fl_Widget(x, y, w, h, label) {}
    virtual ~MyWidget() = default;

    void draw() override
    {
        fl_rectf( x(), y(), w(), h(), FL_BACKGROUND_COLOR );
        fl_color( FL_FOREGROUND_COLOR );
        fl_font( FL_HELVETICA, FL_NORMAL_SIZE );


        const char firstLine[] = "First line";
        const char secondLine[] = "Second line";

        fl_draw( firstLine, 50, 100 );
        fl_draw( secondLine, 50, 100 + fl_height());

        fl_draw( firstLine, 130, 100 );

        // The font becomes smaller after each call to fl_height
        std::cout << fl_size() << ", " << fl_height() << std::endl; // prints: 13, 15
        fl_height( FL_HELVETICA , FL_NORMAL_SIZE );
        std::cout << fl_size() << ", " << fl_height() << std::endl; // prints: 12, 14
        fl_height( FL_HELVETICA , FL_NORMAL_SIZE );
        std::cout << fl_size() << ", " << fl_height() << std::endl; // prints: 12, 13
        fl_height( FL_HELVETICA , FL_NORMAL_SIZE );
        std::cout << fl_size() << ", " << fl_height() << std::endl; // prints: 12, 13
        fl_height( FL_HELVETICA , FL_NORMAL_SIZE );
        std::cout << fl_size() << ", " << fl_height() << std::endl; // prints: 12, 13

        fl_draw(secondLine, 130, 100 + fl_height());
	}
};

int main()
{
    auto* window = new Fl_Window( 300, 300 );

    auto* myWidget = new MyWidget(25, 25, 50, 50, "mywidget");

    window->show();

    return Fl::run();
}