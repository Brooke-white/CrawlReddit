//
//  CurlSetup.h
//  crawler
//
//  Created by brooke on 3/12/16.
//  Copyright © 2016 brooke. All rights reserved.
//

#ifndef CurlSetup_h
#define CurlSetup_h
#include <curl/curl.h>

class CurlSetup{
public:
    CurlSetup(std::string);
    std::string readBuffer;
    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
private:
    CURL *curl;
    CURLcode res;
};

#endif /* CurlSetup_h */
