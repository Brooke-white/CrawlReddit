//
//  main.cpp
//  crawler
//
//  Created by brooke on 3/9/16.
//  Copyright © 2016 brooke. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "LinkedList.h"
#include "CurlSetup.h"
#include "ParseXML.h"
#include "CurlEmail.h"
#include <unordered_set>
#include <ctime>
#include <curl/curl.h>

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
    
    const std::string website = "http://www.reddit.com/.xml";
    std::unordered_set<std::string> subs = {"news", "worldnews", "mildlyinteresting", "science", "aww", "space", "AskReddit"};
    
    const std::string to = "recipient_email";
    const std::string from = "sender_email";
    const std::string from_pass = "sender_password";
    const std::string smtp = "senders_email_client";
    
    CurlSetup myCurl(website);
    
    ParseXML myXML(myCurl.readBuffer, list, subs);
    myXML.get_post_attributes();
    
    const std::string content = myXML.linked_post_list.to_string();
    
    CurlEmail myEmail(to, from, from_pass,smtp, content);
    myEmail.send_mail();
    
    return 0;
}
