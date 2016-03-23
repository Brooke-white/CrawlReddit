//
//  CurlEmail.h
//  crawler
//
//  Created by brooke on 3/23/16.
//  Copyright © 2016 brooke. All rights reserved.
//

#ifndef CurlEmail_h
#define CurlEmail_h
#define FROM    "<senders_email>"
#define TO      "<recipient_email>"

struct upload_status {
    int lines_read;
};

class CurlEmail{
public:
    CurlEmail(const std::string to_user, const std::string from_user, const std::string password,
              const std::string smtp_address, const std::string content_xml);
    int send_mail();
private:
    std::string to;
    std::string from;
    std::string from_pass;
    std::string smtp;
    std::string content;
    std::string send_datetime;
    
    std::string get_month(int month);
    std::string get_week_day(int weekday);
    std::string get_send_datetime();
    std::string get_body_message();
    std::string get_to_from(std::string email, std::string to_from);
};

#endif /* CurlEmail_h */
