#include<iostream>
#include<map>
using namespace std;

std::map<int,std::string>name_map;

int main()
{
    //inserting values into maps
    name_map[1] = "Bob";
    name_map[2] = "Afwata";
    name_map[3] = "Robert";
    name_map[4] = "James";
    //clearing a map use .clear();
    //name_map.clear();
    name_map[5] = "Comey";
    //printing or displaying values in a map
    std::cout<<name_map[3]<<std::endl;
    //using the iterator to list members of a map
    for(std::map< int, std::string>::iterator it=name_map.begin(); it !=name_map.end(); it++){
        std::cout<<it->first<<"=>"<<it->second<<std::endl;
    }
    //std::cout<<"Hello world"<<std::endl;
    cout<<"map size : "<<name_map.size()<<endl;
    return 0;
}