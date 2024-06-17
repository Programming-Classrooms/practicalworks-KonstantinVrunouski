#ifndef STUDENTYEAR_HPP
#define STUDENTYEAR_HPP

#include "StudentFirstSession.hpp"

class StudentYear : public StudentFirstSession
{
protected:
    int32_t marksYear[5];

public:
    StudentYear() = delete;
    StudentYear(const std::string, 
                const int32_t, 
                const int32_t, 
                const int32_t, 
                int32_t*,
                int32_t*);
    StudentYear(const StudentYear&);

    ~StudentYear(){};

    void setMarks(int32_t*);

    int32_t* getMarks();

    friend std::ostream& operator<<(std::ostream&, const StudentYear&);

    virtual double mediumMark() override;
};

#endif