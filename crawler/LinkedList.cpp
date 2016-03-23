//
//  LinkedList.cpp
//  crawler
//
//  Created by brooke on 3/12/16.
//  Copyright © 2016 brooke. All rights reserved.
//

#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList(){
    root = new Node;
    root->next = 0;
    conductor = root;
}

LinkedList::~LinkedList(){
    delete [] root;
}

void LinkedList::add_node(const char* my_arr[3]){
    
    if (conductor != 0) {
        while(conductor->next != 0) {
            conductor = conductor->next;
        }
    }
    conductor->post_title = my_arr[0];
    conductor->post_category = my_arr[1];
    conductor->post_url = my_arr[2];
    
    conductor->next = new Node;
    conductor = conductor->next;
    conductor->next = 0;
}

void LinkedList::print_linked_list(){
    conductor = root;
    
    if ( conductor != 0 ) { //Makes sure there is a place to start
        while ( conductor->next != 0 ) {
            std::cout<< conductor->post_title<<std::endl;
            std::cout<< conductor->post_category<<std::endl;
            std::cout<< conductor->post_url<<std::endl<<std::endl;
            conductor = conductor->next;
        }
    }
}

std::string LinkedList::to_string(){
    std::string contents;
    conductor = root;
    
    if ( conductor != 0 ) {
        while ( conductor->next != 0 ) {
            contents.append(conductor->post_title);
            contents.append("\n");
            contents.append(conductor->post_category);
            contents.append("\n");
            contents.append(conductor->post_url);
            contents.append("\n\n");
            conductor = conductor->next;
        }
    }
    return contents;
}
