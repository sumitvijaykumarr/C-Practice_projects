#include <iostream>
#include <fstream>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/prettywriter.h>  // for formatted output
#include <rapidjson/document.h>


int main(){
    //Create JSON object
    rapidjson::Document doc;
    doc.SetObject();
    rapidjson::Document::AllocatorType& allocator = doc.GetAllocator();
    doc.AddMember("name", "Sumit", allocator);
    doc.AddMember("age", 28, allocator);

    //Add array
    rapidjson::Value skills(rapidjson::kArrayType);
    skills.PushBack("C++", allocator);
    skills.PushBack("Qt", allocator);
    skills.PushBack("AUTOSAR", allocator);
    doc.AddMember("skills", skills, allocator);

    //Convert to JSON
    rapidjson::StringBuffer buffer;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);
    doc.Accept(writer);

    //Write to file
    std::ofstream file("/home/winner/git_projects/C-Practice_projects/json/write_json/output.json");
    file<<buffer.GetString();
    file.close();

    std::cout<<"JSON file created"<<std::endl;
    return 0;
}