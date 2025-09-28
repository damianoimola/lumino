//
// Created by damiano on 25/09/25.
//
#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "behaviortree_cpp/bt_factory.h"


class BTree {
public:
    std::string XML_DIR = "../config";
    std::string FILE_PATH = "../config/lumino.xml";
    std::ifstream behavior_file;

    BTree();
    ~BTree();

    int btree_main();

    void register_all_xml_files(BT::BehaviorTreeFactory *factory) const;

    int print();
};