#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        for (int i = 1; i < argc; i++)
        {
            std::string arg = argv[i];
            for (long unsigned j = 0; j < arg.size(); j++)
                std::cout << (char)toupper(arg.at(j));
        }
    }
    std::cout << std::endl;
}
