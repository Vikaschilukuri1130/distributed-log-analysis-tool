#include "../include/ReportGenerator.h"

#include <fstream>
#include <iomanip>

bool ReportGenerator::generateReport(
    const std::string& filePath,
    int totalCount,
    int infoCount,
    int warnCount,
    int errorCount,
    int criticalFailureCount,
    const std::string& mostCommonError,
    int peakErrorHour,
    double processingTime
) {
    std::ofstream report(filePath);

    if (!report.is_open()) {
        return false;
    }

    double errorRate = 0.0;

    if (totalCount > 0) {
        errorRate = (static_cast<double>(errorCount) / totalCount) * 100;
    }

    report << "===== Log Analysis Report =====\n\n";

    report << "Total Logs        : " << totalCount << "\n";
    report << "INFO Logs         : " << infoCount << "\n";
    report << "WARN Logs         : " << warnCount << "\n";
    report << "ERROR Logs        : " << errorCount << "\n";
    report << "Critical Failures : " << criticalFailureCount << "\n";
    report << "Most Common Error : " << mostCommonError << "\n";

    if (peakErrorHour == -1) {
        report << "Peak Error Hour   : None\n";
    } else {
        report << "Peak Error Hour   : " << peakErrorHour << ":00\n";
    }

    report << std::fixed << std::setprecision(2);
    report << "Error Rate        : " << errorRate << "%\n";
    report << "Processing Time   : " << processingTime << " seconds\n";

    report.close();
    return true;
}

bool ReportGenerator::generateCSVReport(
    const std::string& filePath,
    int totalCount,
    int infoCount,
    int warnCount,
    int errorCount,
    int criticalFailureCount,
    const std::string& mostCommonError,
    int peakErrorHour,
    double processingTime
) {
    std::ofstream csv(filePath);

    if (!csv.is_open()) {
        return false;
    }

    double errorRate = 0.0;

    if (totalCount > 0) {
        errorRate = (static_cast<double>(errorCount) / totalCount) * 100;
    }

    csv << "Metric,Value\n";
    csv << "Total Logs," << totalCount << "\n";
    csv << "INFO Logs," << infoCount << "\n";
    csv << "WARN Logs," << warnCount << "\n";
    csv << "ERROR Logs," << errorCount << "\n";
    csv << "Critical Failures," << criticalFailureCount << "\n";
    csv << "Most Common Error," << mostCommonError << "\n";

    if (peakErrorHour == -1) {
        csv << "Peak Error Hour,None\n";
    } else {
        csv << "Peak Error Hour," << peakErrorHour << ":00\n";
    }

    csv << std::fixed << std::setprecision(2);
    csv << "Error Rate," << errorRate << "\n";
    csv << "Processing Time," << processingTime << "\n";

    csv.close();
    return true;
}