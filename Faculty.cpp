#include "Faculty.hpp"


Faculty::Faculty() : Person(){
    level = "";
    department = "";
    advisees = new GenList<int>();
}

Faculty::Faculty(int id, string n, string l, string d, GenList<int>* list) : Person(n, id){

    level = l;
    department = d;
    advisees = list;
}

string Faculty::getLevel(){
    return level;
}

string Faculty::getDepartment(){
    return department;
}

GenList<int>* Faculty::getAdviseeList(){
    return advisees;
}

void Faculty::setLevel(string l){
    level = l;
}

void Faculty::setDepartment(string d){
    department = d;
}

void Faculty::setAdviseeList(GenList<int>* list){
    advisees = list;
}


string Faculty::printPerson(){
    string str = "";
    str += to_string(getID());
    str += "-" + getName();
    str += "-" + level;
    str += "-" + department;
    str += "-" + advisees->toString();
    return str;
}
