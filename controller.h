#include<iostream>
#include"employee_model.h"
#include"employee_data.h"
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

        void create_new_employee(){
            EmpData employee = view.add_new_employee();
            model.create_new_employee(employee.roll_number,employee.name,employee.specialization,employee.salary);
        }

        void remove_employee(){
            int emp_roll_number = view.get_roll_number();
            model.delete_employee(emp_roll_number);
        }

        void search_by_name(){
            std::string emp_name = view.search_by_name();
            EmpData employee = model.search_by_name(emp_name);
            if(employee.name.length() >= 1)
                view.display_employee_data(employee.roll_number,employee.name,employee.specialization,employee.salary);
            else
                view.display_not_found(emp_name);
        }

        void search_by_roll_number(){
            int emp_roll_number = view.search_by_roll_number();
            EmpData employee = model.search_by_roll_number(emp_roll_number);
            if(employee.name.length() >= 1)
                view.display_employee_data(employee.roll_number,employee.name,employee.specialization,employee.salary);
            else
                view.display_not_found(emp_roll_number);
        }

        void update_name_by_roll(){
            int roll_number = view.get_roll_number();
            std::string new_name = view.get_new_name();
            bool check = model.update_name_by_roll_number(roll_number,new_name);
            if (check){
                view.updated_succesfully();
            }
            else{
                view.display_not_found(roll_number);
            }
        }
        void update_specialization_by_roll(){
            int roll_number = view.get_roll_number();
            std::string new_specialization = view.get_new_specialization();
            bool check = model.update_specialization_by_roll_number(roll_number,new_specialization);
            if (check){
                view.updated_succesfully();
            }
            else{
                view.display_not_found(roll_number);
            }
        }
        void update_salary_by_roll(){
            int roll_number = view.get_roll_number();
            double new_salary = view.get_new_salary();
            bool check = model.update_salary_by_roll_number(roll_number,new_salary);
            if (check){
                view.updated_succesfully();
            }
            else{
                view.display_not_found(roll_number);
            }
        }
};