#ifndef LOGENTRY_H
#define LOGENTRY_H

#include <string>

class LogEntry {
public:
    std::string timestamp;
    std::string level;
    std::string message;

    LogEntry(
        const std::string& timestamp,
        const std::string& level,
        const std::string& message
    );
};

#endif