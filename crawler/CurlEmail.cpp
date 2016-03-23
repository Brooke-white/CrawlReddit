//
//  CurlEmail.cpp
//  crawler
//
//  Created by brooke on 3/23/16.
//  Copyright © 2016 brooke. All rights reserved.
//

#include <stdio.h>
#include <curl/curl.h>
#include <iostream>
#include "CurlEmail.h"

static const char *payload_text[8];

static size_t payload_source(void *ptr, size_t size, size_t nmemb, void *userp)
{
    struct upload_status *upload_ctx = (struct upload_status *)userp;
    const char *data;
    
    if((size == 0) || (nmemb == 0) || ((size*nmemb) < 1)) {
        return 0;
    }
    
    data = payload_text[upload_ctx->lines_read];
    
    if(data) {
        size_t len = strlen(data);
        memcpy(ptr, data, len);
        upload_ctx->lines_read++;
        
        return len;
    }
    
    return 0;
}

CurlEmail::CurlEmail(const std::string to_user, const std::string from_user, const std::string password,const std::string smtp_address, const std::string content_xml){
    to = to_user;
    from = from_user;
    from_pass = password;
    smtp = smtp_address;
    content = content_xml;
    send_datetime = get_send_datetime();
    
    std::cout<<send_datetime<<std::endl;
    
    payload_text[0] = send_datetime.c_str();
    payload_text[1] = "To: " TO "\r\n";
    payload_text[2] = "From: " FROM "CrawlReddit\r\n";
    payload_text[3] = "Message-ID: <dcd7cb36-11db-487a-9f3a-e652a9458efd@rmymailerbuddy@gmail.com>\r\n";
    payload_text[4] = "Subject: Today's Frontpage\r\n";
    payload_text[5] = content.c_str();
    payload_text[6] = NULL;
}

int CurlEmail::send_mail(){
    /*
    CURL *curl;
    CURLcode res = CURLE_OK;
    struct curl_slist *recipients = NULL;
    struct upload_status upload_ctx;*/
    
    upload_ctx.lines_read = 0;
    
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_USERNAME, from.c_str());
        curl_easy_setopt(curl, CURLOPT_PASSWORD, from_pass.c_str());
        
        curl_easy_setopt(curl, CURLOPT_URL, smtp.c_str());
        
        curl_easy_setopt(curl, CURLOPT_USE_SSL, (long)CURLUSESSL_ALL);
        
        
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        
        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, from.c_str());
        
        
        recipients = curl_slist_append(recipients, to.c_str());
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
        
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, payload_source);
        curl_easy_setopt(curl, CURLOPT_READDATA, &upload_ctx);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
        
        
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        
        res = curl_easy_perform(curl);
        
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        
        curl_slist_free_all(recipients);
        
        curl_easy_cleanup(curl);
    }
    return (int)res;
}

std::string CurlEmail::get_month(int month){
    switch(month){
        case 1:
            return "Jan";
        case 2:
            return "Feb";
        case 3:
            return "Mar";
        case 4:
            return "Apr";
        case 5:
            return "May";
        case 6:
            return "Jun";
        case 7:
            return "Jul";
        case 8:
            return "Aug";
        case 9:
            return "Sept";
        case 10:
            return "Oct";
        case 11:
            return "Nov";
        case 12:
            return "Dec";
        default:
            return std::to_string(month);
    }
}

std::string CurlEmail::get_week_day(int weekday){
    switch (weekday){
        case 0:
            return "Sun, ";
        case 1:
            return "Mon, ";
        case 2:
            return "Tue, ";
        case 3:
            return "Wed, ";
        case 4:
            return "Thu, ";
        case 5:
            return "Fri, ";
        case 6:
            return "Sat, ";
        default:
            return std::to_string(weekday);
    }
}

std::string CurlEmail::get_send_datetime(){
    time_t t = time(0);
    struct tm * now = localtime(&t);
    return ("Date: " + get_week_day(now->tm_wday) + std::to_string(now->tm_mday) + " " + get_month(now->tm_mon + 1) + " " + std::to_string(now->tm_year+ 1900) + " " + std::to_string(now->tm_hour) + ':' + std::to_string(now->tm_min) + ':' + std::to_string(now->tm_sec) + " \r\n");
}

std::string CurlEmail::get_body_message(){
    return "body message here";
}

std::string CurlEmail::get_to_from(std::string email, std::string to_from){
    return (to_from + email + "\r\n");
}
