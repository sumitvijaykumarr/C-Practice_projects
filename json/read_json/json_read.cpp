#include<iostream>
#include<fstream>
#include<sstream>
#include<rapidjson/document.h>

int main(){
    //Load file into string
    std::ifstream file("/home/winner/git_projects/C-Practice_projects/json/read_json/output.json");
    if(!file.is_open()){
        std::cerr<<"Could not open JSON file !"<<std::endl;
        return 1;
    }

    
    std::stringstream buffer;
    buffer<<file.rdbuf();
    std::string jsonContent = buffer.str();

    //Parse JSON
    rapidjson::Document doc;
    if(doc.Parse(jsonContent.c_str()).HasParseError()){
        std::cerr<<"Error: Failed to parse JSON!"<<std::endl;
        return 1;
    }

    //Read values
    if(doc.HasMember("name") && doc["name"].IsString()){
        std::cout<<"Name: "<< doc["name"].GetString() <<std::endl;
    }

    if(doc.HasMember("age") && doc["age"].IsInt()){
        std::cout<<"Age:"<<doc["age"].GetInt()<<std::endl;
    }

    if(doc.HasMember("skills") && doc["skills"].IsArray()){
        std::cout<<"Skills: ";
        for(auto& skill : doc["skills"].GetArray()){
            std::cout<< skill.GetString()<< " ";
        }
        std::cout<<std::endl;
    }
    return 0;

}