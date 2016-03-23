//
//  LinkedList.h
//  crawler
//
//  Created by brooke on 3/12/16.
//  Copyright © 2016 brooke. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h
#include <string>
struct Node {
    const char* post_title;
    const char* post_category;
    const char* post_url;
    Node *next;
};

class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    Node *root;
    Node *conductor;
    void add_node(const char* post_info[3]);
    void print_linked_list();
    std::string to_string();
};
#endif /* LinkedList_h */
