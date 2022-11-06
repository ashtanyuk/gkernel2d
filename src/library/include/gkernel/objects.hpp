#ifndef __GKERNEL_HPP_OBJECTS
#define __GKERNEL_HPP_OBJECTS
#include "helpers.hpp"

namespace gkernel {

struct Point {
    Point() : _x(max_data_type_value), _y(max_data_type_value) {};
    Point(data_type x, data_type y) : _x(x), _y(y) {}

    bool operator==(const Point& other) const {
        return this->_x == other._x && this->_y == other._y;
    }
    bool operator!=(const Point& other) const {
        return !(*this == other);
    }

    data_type x() const { return _x; }
    data_type y() const { return _y; }

private:
    data_type _x, _y;
};

struct Segment {
    Segment() : _begin_point(), _end_point() {};
    Segment(const Point& begin_point, const Point& end_point) : _begin_point(begin_point), _end_point(end_point) {}

    bool operator==(const Segment& other) const {
        return this->_begin_point == other._begin_point && this->_end_point == other._end_point;
    }
    bool operator!=(const Segment& other) const {
        return !(*this == other);
    }

    bool operator<(const Segment& c1) const {
        if (this->begin_point().x() < c1.begin_point().x())
            return true;
        else if (this->begin_point().x() == c1.begin_point().x()) {
                if (this->begin_point().y() < c1.begin_point().y()) {
                    return true;
                } else if (this->begin_point().y() == c1.begin_point().y()) {
                    if (this->end_point().x() < c1.end_point().x()) {
                        return true;
                    } else if (this->end_point().x() == c1.end_point().x()) {
                            if (this->end_point().y() < c1.end_point().y()) {
                                return true;
                            } else return false;
                    } else return false;
            } else return false;
        } else return false;
    }

    const Point& begin_point() const { return _begin_point; }
    const Point& end_point() const { return _end_point; }

private:
    Point _begin_point, _end_point;
};

} // namespace gkernel
#endif // __GKERNEL_HPP_OBJECTS