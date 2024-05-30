#include <iostream>
#include "../funcs/Student.hpp"
#include "../funcs/TDeque.hpp"


int main()
{
    try
    {
        TDeque<int32_t> intDeque;

        intDeque.InsFront(1);
        intDeque.InsFront(2);

        intDeque.InsRear(3);
        intDeque.InsRear(4);
        int item = 0;
        intDeque.DelFront(item);
        std::cout << item << '\n';
        intDeque.DelRear(item);
        std::cout << item << '\n';

        std::cout << "First element: " << intDeque.GetByIndex(0) << '\n';

        intDeque.SetByIndex(5, 0);
        std::cout << "First element after change: " << intDeque.GetByIndex(0) << '\n';



        intDeque.Browse(std::function<void(int32_t)>([](int32_t element) {std::cout << element << '\t'; }));
        std::cout << '\n';

        int frontItem = 0;
        if (intDeque.DelFront(frontItem)) {
            std::cout << "Removed item from the head of the deck: " << frontItem << '\n';
        }

        int rearItem = 0;
        if (intDeque.DelRear(rearItem)) {
            std::cout << "Removed element from the tail of the deck: " << rearItem << '\n';
        }
        TDeque <int32_t> anotherDeque;
        anotherDeque = intDeque;

        // Добавление элемента int
        OrderedLinkedList<int> intList;
        intList.addElement(5);
        intList.addElement(3);
        intList.addElement(7);
        intList.addElement(1);

        // Добавление элемента Student
        OrderedLinkedList<Student> studentList;
        studentList.addElement(Student("Alice", 101));
        studentList.addElement(Student("Bob", 102));
        studentList.addElement(Student("Charlie", 103));
        studentList.addElement(Student("David", 104));

        return 0;
    }
    catch (std::exception& a)
    {
        std::cout << a.what();
    }
}
