# Distributed Log Analysis Tool

## Overview

The Distributed Log Analysis Tool is a C++-based analytics application designed to process and analyze application log files efficiently. The tool parses structured log entries, classifies log events by severity level, detects critical failures, identifies recurring issues, calculates error metrics, and generates analytical reports in both text and CSV formats.

This project demonstrates object-oriented design principles, efficient file processing, STL container utilization, log analytics, and report generation techniques commonly used in monitoring and observability systems.

---

## Features

### Log Processing

* Reads application log files from the command line.
* Processes structured log entries containing timestamps, log levels, and messages.
* Supports large-scale log file analysis through stream-based file processing.

### Log Classification

* Identifies and classifies:

  * INFO events
  * WARN events
  * ERROR events

### Error Analytics

* Calculates total log count.
* Detects critical failures.
* Calculates error rate percentage.
* Identifies the most common error.
* Determines peak error hour based on error occurrence frequency.

### Report Generation

Generates analytical reports in multiple formats:

#### Text Report

```text
reports/summary.txt
```

#### CSV Report

```text
reports/summary.csv
```

### Performance Monitoring

* Measures processing time for log analysis execution.
* Provides execution metrics for performance evaluation.

---

## Project Architecture

```text
distributed-log-analysis-tool
│
├── docs
│
├── include
│   ├── LogEntry.h
│   ├── LogParser.h
│   └── ReportGenerator.h
│
├── logs
│   └── application.log
│
├── reports
│   ├── summary.txt
│   └── summary.csv
│
├── src
│   ├── LogEntry.cpp
│   ├── LogParser.cpp
│   ├── ReportGenerator.cpp
│   └── main.cpp
│
├── .gitignore
├── LICENSE
└── README.md
```

---

## System Design

### LogEntry

Represents a structured log record.

Attributes:

* Timestamp
* Log Level
* Message

Example:

```text
2026-05-31 10:02:30 ERROR Database connection failed
```

---

### LogParser

Responsible for:

* Reading log files
* Parsing log entries
* Storing log records
* Computing analytics
* Detecting critical failures
* Tracking error frequencies
* Calculating peak error hours

---

### ReportGenerator

Responsible for:

* Generating text reports
* Generating CSV reports
* Calculating error rates
* Formatting analytical output

---

## Sample Input

```text
2026-05-31 10:00:01 INFO Service started
2026-05-31 10:01:15 WARN High memory usage
2026-05-31 10:02:30 ERROR Database connection failed
2026-05-31 10:03:10 INFO Retry initiated
```

---

## Sample Output

```text
===== Log Analysis Report =====

Total Logs        : 4
INFO Logs         : 2
WARN Logs         : 1
ERROR Logs        : 1
Critical Failures : 1
Most Common Error : Database connection failed
Peak Error Hour   : 10:00
Error Rate        : 25.00%
Processing Time   : 0.00 seconds
```

---

## Build Instructions

### Prerequisites

* C++17 Compatible Compiler
* MSYS2 GCC
* Visual Studio Code

Verify installation:

```bash
g++ --version
```

---

### Compile

```bash
g++ src/main.cpp src/LogParser.cpp src/ReportGenerator.cpp src/LogEntry.cpp -o log_analyzer.exe
```

---

### Execute

```bash
./log_analyzer.exe logs/application.log
```

Windows PowerShell:

```powershell
.\log_analyzer.exe logs/application.log
```

---

## CSV Export Example

```csv
Metric,Value
Total Logs,4
INFO Logs,2
WARN Logs,1
ERROR Logs,1
Critical Failures,1
Most Common Error,Database connection failed
Peak Error Hour,10:00
Error Rate,25.00
Processing Time,0.00
```

---

## Technologies Used

* C++
* Object-Oriented Programming (OOP)
* STL Containers

  * Vector
  * Unordered Map
* File Streams
* String Processing
* Data Analytics
* Command-Line Interfaces (CLI)

---

## Key Learning Outcomes

* Object-Oriented Design
* File Processing
* Log Parsing Techniques
* Data Aggregation
* Performance Measurement
* Report Generation
* Analytics Development
* C++ STL Utilization

---

## Future Enhancements

* JSON Report Export
* Top 5 Error Analytics
* Real-Time Log Monitoring
* Multi-threaded Log Processing
* Dashboard Integration
* Unit Testing Framework
* Large-Scale Log Benchmarking
* Distributed Log Aggregation

---

## License

This project is licensed under the MIT License.

---

## Author

Vikas Mohan Chilukuri

GitHub Portfolio Project demonstrating log analytics, object-oriented programming, and scalable file-processing techniques using C++.
