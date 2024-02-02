// Example program
#include <iostream>
#include <string>
#include <list>


std::list<std::string> process_names(std::string input) {
    char delimiter = ',';
    int start = 0;
    int delimiter_pos = 0;
    std::list<std::string> names;
    while(delimiter_pos >= 0) {
      delimiter_pos = input.find(delimiter, start);
      int size = delimiter_pos - start;
      
      std::string name = input.substr(start, size);
      
      name.erase(remove_if(name.begin(), name.end(), isspace), name.end());
      
      start = delimiter_pos + 1;
      names.insert(names.end(), name);
    }
    return names;
}

int main()
{
  std::string name_input;
  std::cout << "What are your names? ";
  getline (std::cin, name_input);
  
  std::list<std::string> names = process_names(name_input);
  
  std::cout << "The contents of names are: ";
  for (std::list<std::string>::iterator it = names.begin(); it != names.end(); it++)
    std::cout << *it << ", ";

    std::cout << '\n';
}


