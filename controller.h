#include<iostream>
#include"employee_model.h"
#include"employee_data.h"
#include"view.h"

class Controller{
    private:
        Employee* model;
        View view;
    public:
        Controller(){}
        Controller(Employee *employee, View view){
            this->model = employee;
            this->view = view;
        }

        void create_new(const httplib::Request & req, httplib::Response &res){
            std::string roll_number_str=req.get_param_value("roll_number");
            int roll_number= atoi(roll_number_str.c_str());
            std::string name=req.get_param_value("name");
            std::string specialization=req.get_param_value("specialization");
            std::string salary_str = req.get_param_value("salary");
            double salary = std::stod(salary_str);

            model->create_new_employee(roll_number,name,specialization,salary);

              res.set_content("{name : "+name+"} {roll_number: "+roll_number_str+"} {specialization: "+specialization+"} {salary: "+salary_str+"}", "text/plain");
        }

        void search(const httplib::Request & req, httplib::Response &res){
            EmpData employee;
            if(req.has_param("roll_number")){
                std::string roll_number_str=req.get_param_value("roll_number");
                int roll_number= atoi(roll_number_str.c_str());
                employee = model->search_by_roll_number(roll_number);
            }

            if(employee.name.length() >= 1){
                    std::string roll_number = std::to_string(employee.roll_number);
                    std::string salary = std::to_string(employee.salary);
                    res.set_content("{name : "+employee.name+"} {roll_number: "+roll_number+"} {specialization: "+employee.specialization+"} {salary: "+salary+"}", "text/plain");
            }
            else
                res.set_content("employee not found", "text/plain");
        }

        void update(const httplib::Request & req, httplib::Response &res){
            bool check;
            std::string roll_number_str=req.get_param_value("roll_number");
            int roll_number= atoi(roll_number_str.c_str());
            if(req.has_param("roll_number") && req.has_param("name")){
                std::string name=req.get_param_value("name");
                check = model->update_name_by_roll_number(roll_number,name);
            }
            else if (req.has_param("roll_number") && req.has_param("specialization")){
                std::string specialization=req.get_param_value("specialization");
                check = model->update_specialization_by_roll_number(roll_number,specialization);
            }
            else if (req.has_param("roll_number") && req.has_param("salary")){
                std::string salary_str = req.get_param_value("salary");
                double salary = std::stod(salary_str);
                check = model->update_salary_by_roll_number(roll_number,salary);
            }

            if (check){
                res.set_content("updated succesffuly", "text/plain");
            }
            else {
                res.set_content("employee not found", "text/plain");
            }
        }

        void remove(const httplib::Request & req, httplib::Response &res){
            std::string roll_number_str=req.get_param_value("roll_number");
            int roll_number= atoi(roll_number_str.c_str());
            model->delete_employee(roll_number);
        }



        /* void create_new_employee(){
            EmpData employee = view.add_new_employee();
            model->create_new_employee(employee.roll_number,employee.name,employee.specialization,employee.salary);
        }

        void remove_employee(){
            int emp_roll_number = view.get_roll_number();
            model->delete_employee(emp_roll_number);
        }

        void search_by_name(){
            std::string emp_name = view.search_by_name();
            EmpData employee = model->search_by_name(emp_name);
            if(employee.name.length() >= 1)
                view.display_employee_data(employee.roll_number,employee.name,employee.specialization,employee.salary);
            else
                view.display_not_found(emp_name,0);
        }

        void search_by_roll_number(){
            int emp_roll_number = view.search_by_roll_number();
            EmpData employee = model->search_by_roll_number(emp_roll_number);
            if(employee.name.length() >= 1)
                view.display_employee_data(employee.roll_number,employee.name,employee.specialization,employee.salary);
            else
                view.display_not_found("",emp_roll_number);
        }

        void update_name_by_roll(){
            int roll_number = view.get_roll_number();
            std::string new_name = view.get_new_name();
            bool check = model->update_name_by_roll_number(roll_number,new_name);
            if (check){
                view.updated_succesfully();
            }
            else{
                view.display_not_found("",roll_number);
            }
        }
        
        void update_specialization_by_roll(){
            int roll_number = view.get_roll_number();
            std::string new_specialization = view.get_new_specialization();
            bool check = model->update_specialization_by_roll_number(roll_number,new_specialization);
            if (check){
                view.updated_succesfully();
            }
            else{
                view.display_not_found("",roll_number);
            }
        }
        
        void update_salary_by_roll(){
            int roll_number = view.get_roll_number();
            double new_salary = view.get_new_salary();
            bool check = model->update_salary_by_roll_number(roll_number,new_salary);
            if (check){
                view.updated_succesfully();
            }
            else{
                view.display_not_found("",roll_number);
            }
        } */
};