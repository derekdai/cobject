#include <cstdint>
#include <iostream>

using namespace std;

class Shape
{
private:
    uint32_t argb;

protected:
    Shape() : argb(0xffffffff) {}

public:
    uint32_t get_argb() const { return argb; }
    void set_argb(uint32_t argb) { this->argb = argb; }
    virtual void draw() = 0;
};

class Point : public Shape
{
private:
	float x;
	float y;
	
public:
	Point() : x(0.0f), y(0.0f) {}
	float get_x() const { return x; }
	void set_x(float x) { this->x = x; }
	float get_y() const { return y; }
	void set_y(float y) { this->y = y; }
	virtual void draw() { cout << "Point\n"; }
};

class Circle : public Point
{
private:
	float radius;
	
public:
	Circle() : radius(0.0f) {}
	float get_radius() const { return radius; }
	void set_radius(float radius) { this->radius = radius; }
	virtual void draw() { cout << "Circle\n"; }
};

int main()
{
	Shape * shapes[] = { new Point(), new Circle() };
	for(int i = 0; i < sizeof(shapes) / sizeof(shapes[0]); i ++) {
		shapes[i]->draw();
		delete shapes[i];
	}
	
	return 0;
}

