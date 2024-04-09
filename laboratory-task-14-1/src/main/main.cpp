#include <iostream>
#include <typeinfo>
#include "../Source/Person.hpp"
#include "../Source/Student.hpp"
#include "../Source/Professor.hpp"

int main() 
{   
    size_t size = 0;
    char* tempName = new char[255];
    char* tempDepartment = new char[255];
    int32_t tempCourse;
    int32_t tempGroup;
    int32_t choice;
    int32_t counterStudent = 0;
    int32_t counterProfessor = 0;
    size_t counter = 0;
    
    std::cout << "How many persons there will be:\n";
    std::cin >> size;
    
    Person** arr = new Person*[size];
    
    while (true)
    {
        std::cout << "1. Input student.\n2. Input professor.\n3. Print students.\n4. Print professors.\n5. Finish\n";
        std::cin >> choice;
        
        switch (choice)
        {
            case 1:
            {
                if (counter == size)
                {
                    std::cout << "Too much persons.";
                    break;
                }
                std::cout << "Input name:\n";
                std::cin.ignore();
                std::cin.getline(tempName, 255);
                std::cout << "Input course and group:\n";
                std::cin >> tempCourse >> tempGroup;
                arr[counter++] = new Student(tempName, tempCourse, tempGroup);
                counterStudent++;
                break;
            }
            case 2:
            {
                std::cout << "Input name:\n";
                std::cin.ignore();
                std::cin.getline(tempName, 255);
                std::cout << "Input department:\n";
                std::cin.getline(tempDepartment, 255);
                arr[counter++] = new Professor(tempName, tempDepartment);
                counterProfessor++;
                break;
            }
            case 3:
            {
                if (counterStudent == 0)
                {
                    std::cout << "There are no students.\n";
                    break;
                }
                for (size_t i = 0; i <= counter; ++i)
                {
                    if (dynamic_cast<Student*>(arr[i]))
                    {
                        arr[i]->print(std::cout);
                    }
                }
                break;
            }
            case 4:
            {
                if (counterProfessor == 0)
                {
                    std::cout << "There are no professors.\n";
                }
                for (size_t i = 0; i <= counter; ++i)
                {
                    if (dynamic_cast<Professor*>(arr[i]))
                    {
                        arr[i]->print(std::cout);
                    }
                }
                break;
            }
            case 5:
            {
                delete[] tempName;
                delete[] tempDepartment;
                std::cout << "Have a good day.\n";
                return 0;            
            }
            default:
            {
                delete[] tempName;
                delete[] tempDepartment;
                throw std::invalid_argument("Invalid choice.");
            }
        }   
    }
}
