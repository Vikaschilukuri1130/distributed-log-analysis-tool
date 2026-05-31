#include "../include/LogEntry.h"

LogEntry::LogEntry(
    const std::string& timestamp,
    const std::string& level,
    const std::string& message
) {
    this->timestamp = timestamp;
    this->level = level;
    this->message = message;
}