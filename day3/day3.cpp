#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

class Rucksack
{
private:
    
public:
 std::vector<std::vector<char>> content1;
 Rucksack(const std::vector<std::vector<char>>& content1){
    this->content1 = content1;
 }
 Rucksack(){
    //empty 
 }
 std::vector<std::vector<char>> getContent1(){
    return content1;
 }
 void setContent1(std::vector<std::vector<char>> comtent1){
    content1 = content1; 
 }

};

int getSum(Rucksack elfRucksack){
    std::vector<char> intersectChar;
    std::vector<char> cur_char = elfRucksack.getContent1()[0];
    std::cout << cur_char[0];
    std::set_intersection(elfRucksack.getContent1()[0].begin(), elfRucksack.getContent1()[0].end()
    , elfRucksack.getContent1()[1].begin(), elfRucksack.getContent1()[1].end(), std::back_inserter(intersectChar));
    std::cout << intersectChar.data();
    return 0;
}

int main(){
    std::ifstream myfile ("day3.txt");
    std::vector<Rucksack> elvesRucksack;
    if(myfile.is_open()){
        std::string line;
        while (std::getline(myfile, line)){
            Rucksack elfRuck;
            std::vector<std::vector<char>> lineChar;
            std::vector<std::string> lines;
            lines.push_back(line.substr(0, line.length()/2));
            lines.push_back(line.substr(line.length()/2));

            for (int i = 0; i < lines.size(); i++){
                std::vector<char> v(lines[i].begin(), lines[i].end());
                std::sort(v.begin(), v.end());
                lineChar.push_back(v);
                std::cout << lineChar.size() << std::endl;

            }
            elfRuck.content1 = lineChar;
            std::cout << elfRuck.content1.size();
            elvesRucksack.push_back(elfRuck);
        }
    }
    myfile.close();
    //getSum(elvesRucksack[0]);
        /*for (int i = 0; i < elvesRucksack.size(); i++){
            getSum(elvesRucksack[i]);
        }*/

    for (const Rucksack& rucksack : elvesRucksack) {
        for (const std::vector<char>& innerVec : rucksack.content1) {
            for (char c : innerVec) {
                    std::cout << c << " ";
                }
                std::cout << std::endl;
                std::cout << "a";
            }
        }
    std::cout << "a";
}


