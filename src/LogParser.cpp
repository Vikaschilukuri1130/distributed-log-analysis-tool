#include "../include/LogParser.h"
#include "../include/LogEntry.h"

#include <fstream>
#include <iostream>
#include <sstream>

LogParser::LogParser() {
    totalCount = 0;
    infoCount = 0;
    warnCount = 0;
    errorCount = 0;
    criticalFailureCount = 0;
}

bool LogParser::parseFile(const std::string& filePath) {

    std::ifstream logFile(filePath);

    if (!logFile.is_open()) {
        std::cerr << "Failed to open log file: "
                  << filePath << std::endl;
        return false;
    }

    std::string line;

    while (getline(logFile, line)) {

        totalCount++;

        std::stringstream ss(line);

        std::string date;
        std::string time;
        std::string level;

        ss >> date >> time >> level;

        std::string message;
        getline(ss, message);

        std::string timestamp = date + " " + time;

        LogEntry entry(
            timestamp,
            level,
            message
        );

        logEntries.push_back(entry);

        if (level == "INFO") {
            infoCount++;
        }
        else if (level == "WARN") {
            warnCount++;
        }
        else if (level == "ERROR") {

            errorCount++;

            errorFrequency[message]++;

            int hour = std::stoi(time.substr(0, 2));

            errorHourFrequency[hour]++;

            if (message.find("Database") != std::string::npos ||
                message.find("Connection") != std::string::npos ||
                message.find("Critical") != std::string::npos ||
                message.find("Fatal") != std::string::npos) {

                criticalFailureCount++;
            }
        }
    }

    logFile.close();

    return true;
}

int LogParser::getTotalCount() const {
    return totalCount;
}

int LogParser::getInfoCount() const {
    return infoCount;
}

int LogParser::getWarnCount() const {
    return warnCount;
}

int LogParser::getErrorCount() const {
    return errorCount;
}

int LogParser::getCriticalFailureCount() const {
    return criticalFailureCount;
}

std::string LogParser::getMostCommonError() const {

    if (errorFrequency.empty()) {
        return "None";
    }

    int maxCount = 0;
    std::string mostCommonError = "None";

    for (const auto& entry : errorFrequency) {

        if (entry.second > maxCount) {
            maxCount = entry.second;
            mostCommonError = entry.first;
        }
    }

    return mostCommonError;
}

const std::vector<LogEntry>& LogParser::getLogEntries() const {
    return logEntries;
}

int LogParser::getPeakErrorHour() const {

    int peakHour = -1;
    int maxErrors = 0;

    for (const auto& entry : errorHourFrequency) {

        if (entry.second > maxErrors) {

            maxErrors = entry.second;
            peakHour = entry.first;
        }
    }

    return peakHour;
}