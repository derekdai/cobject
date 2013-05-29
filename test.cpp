#include <cstdint>

class Shape
{
private:
    uint32_t argb;

protected:
    Shape() : argb(0xffffffff) {}

public:

    uint32_t get_argb() const { return argb; }

    void set_argb(uint32_t argb) { this->argb = argb; }
};

int main()
{
	return 0;
}

