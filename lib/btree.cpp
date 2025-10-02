//
// Created by damiano on 25/09/25.
//

#include "btree.h"

#include "example_btree.h"
#include "example_btree2.h"


BTree::BTree() {this->behavior_file = std::ifstream(this->FILE_PATH);};

BTree::~BTree() {this->behavior_file.close();};



void BTree::register_all_xml_files(BT::BehaviorTreeFactory *factory) const {
    // Find all the XML files in a folder and register all of them.
    // We will use std::filesystem::directory_iterator

    using std::filesystem::directory_iterator;
    for (auto const& entry : directory_iterator(this->XML_DIR))
    {
        if(entry.path().extension() == ".xml")
        {
            factory->registerBehaviorTreeFromFile(entry.path().string());
        }
    }
}

int BTree::print() {
    std::string str;
    std::string file_contents;

    while (std::getline(this->behavior_file, str))
    {
        file_contents += str;
        file_contents.push_back('\n');
    }

    std::cout << file_contents << std::endl;

    this->behavior_file.close();

    return 0;
};




int BTree::btree_main() const {
    BT::BehaviorTreeFactory factory;

    // --- MAIN TREE ---
    MainTree main_tree_obj;
    main_tree_obj.register_tree(&factory);

    // --- GRASP OBJECT TREE ---
    GraspObjectTree grasp_tree_obj;
    grasp_tree_obj.register_tree(&factory);


    // registering all `.xml` files
    this->register_all_xml_files(&factory);


    // tick the main tree
    std::cout << "\t ######## MAIN TREE ########" << std::endl;
    auto main_tree = factory.createTree("MainTree");
    main_tree.tickWhileRunning();

    // tick the subtree GraspObject
    std::cout << "\t ######## GRASP OBJECT TREE ########" << std::endl;
    auto grasp_tree = factory.createTree("GraspObject");
    grasp_tree.tickWhileRunning();

    return 0;
}

