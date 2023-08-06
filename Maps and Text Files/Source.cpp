#include <map>
#include <fstream>
#include <iostream>

int main()
{
    std::ifstream file("shuffled_words.txt");
    if (file.fail() == true)
    {
        std::cout << "File unable to open." << std::endl;
        exit(1);
    }


    std::map<std::string, std::string> m;

    while (file.eof() == false)
    {
        std::string a, b;
        file >> a >> b;
        m[a] = b;
    }


    file.close();

    std::string longest;

    for (const std::pair<std::string, std::string>& p : m)
    {
        bool print = false;
        std::string phrase = p.first + " ";
        std::string last = p.second;
        std::map<std::string, std::string>::iterator next = m.find(p.second);
        while (next != m.end())
        {
            phrase += next->first + " ";
            last = next->second;
            next = m.find(next->second);
        }
        phrase += last;
        
        if (phrase.size() > longest.size())
        {
            longest = phrase;
        }
    }
    std::cout << longest << std::endl;

    system("PAUSE");
    return 0;
}