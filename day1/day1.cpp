#include <iostream>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <string>
#include <sstream>
using namespace std;

class Elf{
    public:
        std::string name;
        int caloCount;
};

bool compareElf (const Elf& elf1, const Elf& elf2){
    return elf1.caloCount > elf2.caloCount;
}

int main(int argc, char const *argv[]){
    //testInput
    std::string elves = "1000\n2000\n3000\n\n4000\n\n5000\n6000\n\n7000\n8000\n9000\n\n10000";
    std::vector<std::string> elfes;
    std::vector<Elf> elfSums;
    boost::replace_all(elves,"\n\n","@");
    boost::split(elfes, elves,boost::is_any_of("@"));
    int a = 0;
    Elf elf;
    int index = 1;
    for (std::string n : elfes){
        if (!n.empty()){
            std::vector<std::string> cur;
            boost::split(cur, n, boost::is_any_of("\n"));
            for (std::string num : cur){
                int convertedInt = std::stoi(num);
                a += convertedInt;
            }
            elf.name = "Elfling" + std::to_string(index);
            elf.caloCount = a;
            elfSums.push_back(elf);
            index++;
            a = 0;
        }
    }
    std::sort(elfSums.begin(), elfSums.end(), compareElf);
    std::cout << elfSums[0].name << " " << elfSums[0].caloCount;
    return 0;
}
