#ifndef STUDENTFIRSTSESSION_HPP
#define STUDENTFIRSTSESSION_HPP

#include "Student.hpp"

class StudentFirstSession : public Student
{
protected:
    int32_t marks[4];

public:
    StudentFirstSession() = delete;
    StudentFirstSession(const std::string, 
                        const int32_t, 
                        const int32_t, 
                        const int32_t, 
                        int32_t*);
    StudentFirstSession(const StudentFirstSession&);

    virtual ~StudentFirstSession(){};

    void setMarks(int32_t*);

    int32_t* getMarks();

    friend std::ostream& operator<<(std::ostream&, const StudentFirstSession&);

    virtual double mediumMark();

};

#endif