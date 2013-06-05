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

class Line : public Shape
{
private:
	float x1;
	float y1;
	float x2;
	float y2;

public:
	Line() : x1(0.0f), y1(0.0f), x2(0.0f), y2(0.0f) {}
	float get_x1() { return x1; }
	void set_x1(float x1) { this->x1 = x1; }
	float get_y1() { return y1; }
	void set_y1(float y1) { this->y1 = y1; }
	float get_x2() { return x2; }
	void set_x2(float x2) { this->x2 = x2; }
	float get_y2() { return y2; }
	void set_y2(float y2) { this->y2 = y2; }
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

