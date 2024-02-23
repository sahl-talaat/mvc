#include<iostream>
#include"employee_model.h"
#include"controller.h"
#include"view.h"

int main(){
    std::string file_name = "employee.txt";
    Employee employee(file_name);
    View view;
    Controller controller(employee, view);
    controller.access_all_data();
    /* controller.access_all_data();
    controller.create_employee(120,"sahl","enginerr",2050.20);
    controller.create_employee(150,"sami","developper",3020.20);
    controller.create_employee(80,"rami","security",1080.20);
    controller.create_employee(99,"hani","manager",8040.20);
    controller.search_by_roll_number(120);
    controller.remove_employee(120);
    controller.search_by_roll_number(120);
    controller.search_by_name("hani"); */
    while (1)
    {
        int choice{};
        std::cout<<"\t\tmain page\n";
        std::cout<<"\t1. add new employee\n";
        std::cout<<"\t2. search by employee roll number\n";
        std::cout<<"\t3. search by employee name\n";
        std::cout<<"\t4. update employee name\n";
        std::cout<<"\t5. update employee specialization\n";
        std::cout<<"\t6. update employee salary\n";
        std::cout<<"\t7. delete employee\n";
        std::cin>>choice;
        switch (choice)
        {
        case 1:{
            controller.create_new_employee();
            break;
        }
        case 2:{
            controller.search_by_roll_number();
            break;
        }
        case 3:{
            controller.search_by_name();
            break;
        }
        case 4:{
            controller.update_name_by_roll();
            break;
        }
        case 5:{
            controller.update_specialization_by_roll();
            break;
        }
        case 6:{
            controller.update_salary_by_roll();
            break;
        }
        case 7:{
            controller.remove_employee();
            break;
        }
        default:
            break;
        }
    }
    


    return 0;
}