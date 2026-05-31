#include <iostream>
#include <chrono>

#include "../include/LogParser.h"
#include "../include/ReportGenerator.h"

int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cerr << "Usage: log_analyzer.exe <log_file_path>" << std::endl;
        return 1;
    }

    std::string logFilePath = argv[1];

    auto startTime = std::chrono::high_resolution_clock::now();

    LogParser parser;

    if (!parser.parseFile(logFilePath)) {
        return 1;
    }

    std::cout << "\n===== Parsed Log Entries =====\n" << std::endl;

for (const auto& entry : parser.getLogEntries()) {

    std::cout
        << "Timestamp: " << entry.timestamp
        << " | Level: " << entry.level
        << " | Message:" << entry.message
        << std::endl;
}

    auto endTime = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = endTime - startTime;
    double processingTime = duration.count();

    ReportGenerator reportGenerator;

    bool success = reportGenerator.generateReport(
        "reports/summary.txt",
        parser.getTotalCount(),
        parser.getInfoCount(),
        parser.getWarnCount(),
        parser.getErrorCount(),
        parser.getCriticalFailureCount(),
        parser.getMostCommonError(),
        parser.getPeakErrorHour(),
        processingTime
    );

    bool csvSuccess = reportGenerator.generateCSVReport(
    "reports/summary.csv",
    parser.getTotalCount(),
    parser.getInfoCount(),
    parser.getWarnCount(),
    parser.getErrorCount(),
    parser.getCriticalFailureCount(),
    parser.getMostCommonError(),
    parser.getPeakErrorHour(),
    processingTime
);

if (!csvSuccess) {
    std::cerr << "Failed to generate CSV report." << std::endl;
    return 1;
}

    if (!success) {
        std::cerr << "Failed to generate report." << std::endl;
        return 1;
    }

    std::cout << "Log file analyzed successfully!" << std::endl;
    std::cout << "Report generated at: reports/summary.txt" << std::endl;
    std::cout << "CSV report generated at: reports/summary.csv" << std::endl;

    return 0;
}