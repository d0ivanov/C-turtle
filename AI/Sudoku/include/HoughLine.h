#ifndef HOUGHLINE_H
#define HOUGHLINE_H

//The structure represents a Hough Transform line
typedef struct Line
{
    float r;
    float phi;
    unsigned int len;

    bool Intersects(const Line& other, cv::Point2f& intersection)
    {
        if(fabs(sin(phi - other.phi)) < 0.01)
        {
            return false;
        }
        else
        {
            intersection.x = (sin(other.phi) * r - sin(phi) * other.r) / sin(other.phi - phi);
            intersection.y = (cos(other.phi) * r - cos(phi) * other.r) / sin(phi - other.phi);
            return true;
        }

    }

    bool IsVertical() const
    {
        if((0 <= phi && phi < M_PI_4) ||
           (0.75 * M_PI <= phi && phi < M_PI) ||
           (1.75 * M_PI <= phi && phi < 2.25 * M_PI))
           {
                return true;
           }
           else
           {
               return false;
           }
    }

} Line;

//Used to sort lines with respect to their angle.
inline bool compare_lines_phi(const Line& lhs, const Line& rhs)
{
    if(lhs.IsVertical() && rhs.IsVertical())
    {
        return lhs.phi < rhs.phi;
    }
    else
    {
        if(lhs.IsVertical()) return true;
        else return false;
    }
}

//Used to sort lines with respect to their angle.
inline bool compare_lines_r(const Line& lhs, const Line& rhs)
{
    return lhs.r < rhs.r;
}
#endif
