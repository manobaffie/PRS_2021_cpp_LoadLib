#include "JsonPars.hpp"


JsonPars::JsonPars(std::string p) : path(p), file(p)
{
    if (this->file) {
        this->mapJ = this->parsingJson();
    }
}

JsonPars::~JsonPars()
{
    this->file.close();
}

Obj_s JsonPars::parsingJson()
{
    bool inStr = false, inVal = false, inTab = false;
    std::string name = "", val = "", valType = "";

    Obj_s Obj;
    char i;

    while (this->file.get(i)) {
        if (i == '\"') inStr = inStr ? false : true;
        if (i == ':') inVal = true;

        if (i == ',' || i == '}' || i == ']') {
            if (!inTab) {
                if (valType == "str") Obj.str[name] = val;
                if (valType == "int") Obj.nbr[name] = std::stoi(val);
                // std::cout << "1 n : " << name << " v : " << val << std::endl;
                name = "";
                inVal = false;
            } else {
                if (valType == "str") Obj.tabStr[name].push_back(val);
                if (valType == "int") Obj.tabNbr[name].push_back(std::stoi(val));
                // std::cout << "2 n : " << name << " v : " << val << std::endl;
            }

            if (i == '}') return (Obj);
            if (i == ']') inTab = false;
            valType = val = "";
        }

        if (inVal && i != ' ' && valType.size() == 0) {
            if (std::isdigit(i)) valType = "int";
            if (inStr) valType = "str";
            if (i == '[') inTab = true;

            if (!inTab) {
                if (i == '{') Obj.obj[name] = this->parsingJson();
                // std::cout << "3 n : " << name << " v : " << val << std::endl;
            } else {
                if (i == '{') Obj.tabObj[name].push_back(this->parsingJson());
                // std::cout << "4 n : " << name << " v : " << val << std::endl;
            }
        }

        if (i != '\"') {
            if (!inTab && inStr && !inVal) name += i;
            if (inVal && (valType == "str" || valType == "int")) val += i;
        }
    }
    return (Obj);
}

Obj_s JsonPars::getJson()
{
    return (this->mapJ);
}