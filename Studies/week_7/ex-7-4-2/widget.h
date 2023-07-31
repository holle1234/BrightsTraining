#if !defined(WIDGET)
#define WIDGET


class Widget;


class WidgetInterface
{
public:
    virtual bool add_widget(Widget& w) = 0;
    virtual bool remove_widget() = 0;
    virtual bool on_focus() = 0;
    virtual bool on_mouse_down() = 0;
    virtual bool on_mouse_up() = 0;
    virtual void position(int& x, int& y) = 0;
    virtual bool move_to(int x, int y) = 0;

};


class Widget : public WidgetInterface
{
public:
    int x {0};
    int y {0};


    Widget(){};
    ~Widget(){};

    virtual bool add_widget(Widget& w) override {
        return true;
    }
    virtual bool remove_widget() override {
        return true;
    }
    virtual bool on_focus() override {
        return true;
    }
    virtual bool on_mouse_down() override {
        return true;
    }
    virtual bool on_mouse_up() override {
        return true;
    }
    virtual void position(int& x, int& y) override {
        return;
    }
    virtual bool move_to(int x, int y) override {
        return true;
    }

};



#endif // WIDGET
