# CrawlReddit
A script that e-mails you (or someone else) links from the front page of [Reddit](https://www.reddit.com/) from subreddits you specify!
___
### Dependencies

[TinyXML2](https://github.com/leethomason/tinyxml2)

[cURL](https://curl.haxx.se/download.html) **libcurl must be linked with the project**

Two e-mail accounts are required (one for sending, one for recieving). 
___
### Usage

In **main.cpp** define the following variables:
```C++
    const std::string to = "you@gmail.com";
    const std::string from = "me@gmail.com";
    const std::string from_pass = "hunter1";
    const std::string smtp = "smtp://smtp.gmail.com:587";
```
In **CurlEmail.h** define the preprocessor directives:
```C++
  #define FROM    "<me@gmail.com>"
  #define TO      "<you@gmail.com>"
```
___
### Scheduling e-mails using Cron
###### Cron Usage
```Cron
# Minute   Hour   Day of Month       Month          Day of Week        Command 
(0-59)    (0-23)     (1-31)    (1-12 or Jan-Dec)  (0-6 or Sun-Sat)     cd mydir
  0         7          *               *                *                        (running daily at 7:00AM)
  0         *          *               *                *                        (running daily, every hour on the hour)
```
___
Navigate to the directory where CurlReddit is
```
cd /Users/brooke/documents/coursework/c++/crawl/crawler/
```
Compile with g++
```
g++ -Wall -Wextra -std=c++11 -L /usr/lib -lcurl -lssl -lcrypto -lz *.cpp
```
Run the resulting executable
```
./a.out
```
Putting it all together you have (running once a day at 7:00AM)
```
0 7 * * * cd /Users/brooke/documents/coursework/c++/crawl/crawler/ && g++ -Wall -Wextra -std=c++11 -L /usr/lib -lcurl -lssl -lcrypto -lz *.cpp && ./a.out
```
Create a Cron job and insert the above text, then save and exit
```
env EDITOR=nano crontab -e
```
The job will be confirmed
```
crontab: installing new crontab
```
To delete a job delete the line containing the job, then save and exit
```
env EDITOR=nano crontab -e
```
