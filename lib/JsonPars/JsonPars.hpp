#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <locale>

struct Obj_s {
    std::map<std::string, std::string> str;
    std::map<std::string, int> nbr;
    std::map<std::string, Obj_s> obj;

    std::map<std::string, std::vector<std::string>> tabStr;
    std::map<std::string, std::vector<int>> tabNbr;
    std::map<std::string, std::vector<Obj_s>> tabObj;
};

class JsonPars
{
    private:
        std::string path;
        std::ifstream file;

        Obj_s mapJ;

    public:
        JsonPars(std::string p);
        ~JsonPars();

        Obj_s parsingJson();

        Obj_s getJson();
};
