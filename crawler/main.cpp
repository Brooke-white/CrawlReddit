//
//  main.cpp
//  crawler
//
//  Created by brooke on 3/9/16.
//  Copyright © 2016 brooke. All rights reserved.
//


#include <iostream>
#include "LinkedList.h"
#include "CurlSetup.h"
#include "ParseXML.h"
#include <unordered_set>
int main()
{
    const int SIZE = 7;
    std::string list[SIZE];
    list[0] = "feed";
    list[1] = "entry";
    list[2] = "title";
    list[3] = "category";
    list[4] = "term";
    list[5] = "link";
    list[6] = "href";
    
    CurlSetup myCurl("http://www.reddit.com/.xml");
    
    std::unordered_set<std::string> subs = {"news", "worldnews", "mildlyinteresting", "science", "aww", "space", "television", "AskReddit"};
    
    ParseXML myXML(myCurl.readBuffer, list, subs);
    myXML.get_post_attributes();
    
    return 0;
}
