//
// Created by damiano on 25/09/25.
//

#include "btree.h"

int BTree::btree_main() {
    std::ifstream behavior_file("../config/lumino.xml");

    std::string str;
    std::string file_contents;

    while (std::getline(behavior_file, str))
    {
        file_contents += str;
        file_contents.push_back('\n');
    }

    std::cout << file_contents << std::endl;

    behavior_file.close();
    return 0;
};