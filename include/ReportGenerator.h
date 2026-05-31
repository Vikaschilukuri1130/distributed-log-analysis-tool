#ifndef REPORTGENERATOR_H
#define REPORTGENERATOR_H

#include <string>

class ReportGenerator {
public:
    bool generateReport(
        const std::string& filePath,
        int totalCount,
        int infoCount,
        int warnCount,
        int errorCount,
        int criticalFailureCount,
        const std::string& mostCommonError,
        int peakErrorHour,
        double processingTime
    );

    bool generateCSVReport(
        const std::string& filePath,
        int totalCount,
        int infoCount,
        int warnCount,
        int errorCount,
        int criticalFailureCount,
        const std::string& mostCommonError,
        int peakErrorHour,
        double processingTime
    );
};

#endif