#ifndef __GKERNEL_HPP_OBJECTS
#define __GKERNEL_HPP_OBJECTS

#include "helpers.hpp"
#include <iostream>

namespace gkernel {

class SegmentsSetCommon;
class SegmentsSet;
class Intersection;
class Converter;
class AreaAnalyzer;

struct Point {
    Point() : _x(max_data_type_value), _y(max_data_type_value) {};
    Point(data_type x, data_type y) : _x(x), _y(y) {}

    bool operator==(const Point& other) const {
        return this->_x == other._x && this->_y == other._y;
    }
    bool operator!=(const Point& other) const {
        return !(*this == other);
    }
    bool operator<(const Point& other) const {
        return this->_x < other._x ||
            (this->_x == other._x && this->_y < other._y);
    }
    bool operator>(const Point& other) const {
        return this->_x > other._x ||
            (this->_x == other._x && this->_y > other._y);
    }

    data_type x() const { return _x; }
    data_type y() const { return _y; }

private:
    data_type _x, _y;
};

inline std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.x() << ", " << point.y() << ")";
    return os;
}

struct Segment {
    Segment() : _begin_point(), _end_point() {};
    Segment(const Point& start, const Point& end) : _begin_point(start), _end_point(end) {}

    bool is_point() const {
        return _begin_point == _end_point;
    }

    bool operator==(const Segment& other) const {
        return (this->_begin_point == other._begin_point && this->_end_point == other._end_point) ||
            (this->_begin_point == other._end_point && this->_end_point == other._begin_point);
    }

    bool operator!=(const Segment& other) const {
        return !(*this == other);
    }

    const Point& start() const { return _begin_point; }

    const Point& end() const { return _end_point; }

    const Point& min() const {
        return _begin_point < _end_point ? _begin_point : _end_point;
    }

    const Point& max() const {
        return _begin_point > _end_point ? _begin_point : _end_point;
    }

private:
    Point _begin_point, _end_point;
    segment_id id;

    friend class SegmentsSetCommon;
    friend class SegmentsSet;
    friend class Intersection;
    friend class Converter;
    friend class AreaAnalyzer;
};

inline std::ostream& operator<<(std::ostream& os, const Segment& segment) {
    os << "[" << segment.start() << ", " << segment.end() << "]";
    return os;
}

} // namespace gkernel
#endif // __GKERNEL_HPP_OBJECTS
