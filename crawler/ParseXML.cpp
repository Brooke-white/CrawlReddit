//
//  ParseXML.cpp
//  crawler
//
//  Created by brooke on 3/12/16.
//  Copyright © 2016 brooke. All rights reserved.
//
#include <iostream>
#include <iterator>
#include "ParseXML.h"
#include "tinyxml2/tinyxml2.h"
#include "tinyxml2/tinyxml2.cpp"

ParseXML::ParseXML(std::string readBuffer, std::string elements[7], std::unordered_set<std::string> subreddits){
    std::copy(elements, elements+7, xml_elements);
    subreddit_list = subreddits;
    document.Parse(readBuffer.c_str());
    levelElement = document.FirstChildElement(elements[0].c_str());
    child_element = levelElement->FirstChildElement(elements[1].c_str());
}
void ParseXML::get_post_attributes(){
    for (tinyxml2::XMLElement* child = child_element; child != NULL; child = child->NextSiblingElement()){
        
        // if the HTMl element 'term' is a white listed sub-reddit, add to linked list
        if (subreddit_list.count(child->FirstChildElement(xml_elements[3].c_str())->Attribute(xml_elements[4].c_str()))){
            post_attributes[0] = child->FirstChildElement(xml_elements[2].c_str())->GetText();
            post_attributes[1] = child->FirstChildElement(xml_elements[3].c_str())->Attribute(xml_elements[4].c_str());
            post_attributes[2] = child->FirstChildElement(xml_elements[5].c_str())->Attribute(xml_elements[6].c_str());
            linked_post_list.add_node(post_attributes);
        }
    }
    linked_post_list.print_linked_list();
}
