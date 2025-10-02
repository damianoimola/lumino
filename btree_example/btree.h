//
// Created by damiano on 25/09/25.
//
#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "behaviortree_cpp/bt_factory.h"

#include "example_btree.h"
#include "example_btree2.h"

class BTree {
public:
    std::string XML_DIR = "../config/example";
    std::string FILE_PATH = "../config/example/example_main.xml";
    std::ifstream behavior_file;

    BTree();
    ~BTree();

    int btree_main() const;

    void register_all_xml_files(BT::BehaviorTreeFactory *factory) const;

    int print();
};