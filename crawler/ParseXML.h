//
//  ParseXML.h
//  crawler
//
//  Created by brooke on 3/12/16.
//  Copyright © 2016 brooke. All rights reserved.
//

#ifndef ParseXML_h
#define ParseXML_h
#include <unordered_set>
#include "ParseXML.h"
#include "tinyxml2/tinyxml2.h"
#include "LinkedList.h"

class ParseXML{
public:
    const char * post_attributes[3];
    std::string xml_elements[7];
    std::unordered_set<std::string> subreddit_list;
    ParseXML(std::string readBuffer, std::string elements[7], std::unordered_set<std::string> subreddits);
    void get_post_attributes();
private:
    tinyxml2::XMLDocument document;
    tinyxml2::XMLElement* child_element;
    tinyxml2::XMLElement* levelElement;
    LinkedList linked_post_list;
};
#endif /* ParseXML_h */
