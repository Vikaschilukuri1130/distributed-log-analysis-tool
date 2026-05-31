#ifndef LOGPARSER_H
#define LOGPARSER_H

#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_map>
#include "LogEntry.h"

class LogParser {
private:
    int totalCount;
    int infoCount;
    int warnCount;
    int errorCount;
    int criticalFailureCount;

    std::unordered_map<std::string, int> errorFrequency;

    std::unordered_map<int, int> errorHourFrequency;

    std::vector<LogEntry> logEntries;

public:
    LogParser();

    bool parseFile(const std::string& filePath);

    int getTotalCount() const;
    int getInfoCount() const;
    int getWarnCount() const;
    int getErrorCount() const;
    int getCriticalFailureCount() const;
    int getPeakErrorHour() const;

    std::string getMostCommonError() const;

    const std::vector<LogEntry>& getLogEntries() const;
};

#endif