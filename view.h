#include<iostream>

#ifndef VIEW
#define VIEW
class View{
    public:
        void display_employee_data(int roll_number, std::string name, std::string specialization, double salary){
            std::cout << "=> Roll Number: " << roll_number<< ", Name: " << name << ", Specialization: " << specialization << ", Salary: " << salary << std::endl;
        }
};

#endif