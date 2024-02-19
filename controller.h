#include<iostream>
#include"employee_model.h"
#include"view.h"

class Controller{
    private:
        Employee model;
        View view;
    public:
        Controller(){}
        Controller(Employee employee, View view){
            this->model = employee;
            this->view = view;
        }
        void access_all_data(){
            model.get_all_employee();
        }
        void create_employee(int roll_number, std::string name, std::string specialization, double salary){
            model.create_new_employee(roll_number,name,specialization,salary);
        }
        void remove_employee(int emp_roll_number){
            model.delete_employee(emp_roll_number);
        }
        void search_by_name(std::string emp_name){
            EmpData employee = model.search_by_name(emp_name);
            view.display_employee_data(employee.roll_number,employee.name,employee.specialization,employee.salary);
        }
        void search_by_roll_number(int emp_roll_number){
            EmpData employee = model.search_by_roll_number(emp_roll_number);
            if(employee.name.length() >= 1)
                view.display_employee_data(employee.roll_number,employee.name,employee.specialization,employee.salary);
        }


};