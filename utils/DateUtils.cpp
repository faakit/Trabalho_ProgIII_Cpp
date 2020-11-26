/*
 * DateUtils.cpp
 *
 * Utility functions for date manipulation.
 *
 *  Created on: Jul 9, 2014
 *      Author: Vítor E. Silva Souza (vitorsouza@gmail.com)
 */

#include "DateUtils.h"

#include <iostream>
#include <iomanip>

using namespace std;

/* Maximum size of the string buffer used to format dates. */
#define MAX_DATE_STRING_SIZE 100

// Código que imita o strptime no windows
extern "C" char* strptime(const char* s,
                          const char* f,
                          struct tm* tm) {
    // Isn't the C++ standard lib nice? std::get_time is defined such that its
    // format parameters are the exact same as strptime. Of course, we have to
    // create a string stream first, and imbue it with the current C locale, and
    // we also have to make sure we return the right things if it fails, or
    // if it succeeds, but this is still far simpler an implementation than any
    // of the versions in any of the C standard libraries.
    std::istringstream input(s);
    input.imbue(std::locale(setlocale(LC_ALL, nullptr)));
    input >> std::get_time(tm, f);
    if (input.fail()) {
        return nullptr;
    }
    return (char*)(s + input.tellg());
}

namespace utils {

/* Converts dates in human-readable format to machine-processable format for storing in objects. */
time_t parseDate(const string& str, const string& format) {
	// Creates an empty calendar.
	struct tm calendar = {0, 0, 0, 0, 0, 0, 0, 0, 0};

	// Fills the calendar fields (year, month, day, etc.) based on the date string following the given format.
	strptime(str.c_str(), format.c_str(), &calendar);

	// Creates a time_t, machine-friendly date value from the calendar and returns.
	time_t t = mktime(&calendar);
	return t;
}

/* Converts dates in machine-processable format to human-readable format for printing. */
string formatDate(const time_t& t, const string& format) {
	// Creates a calendar structure from the machine-friendly time value.
	struct tm *tm = localtime(&t);

	// Writes in a string buffer the date from the calendar following the given format.
	char buffer[MAX_DATE_STRING_SIZE];
	strftime(buffer, MAX_DATE_STRING_SIZE, format.c_str(), tm);

	// Returns the buffer, which gets copied to the receiving string via copy constructor or assignment operator.
	return buffer;
}

bool validDate(const string& str, const string& formato) {
	struct tm tm;
	return strptime(str.c_str(), formato.c_str(), &tm);
}

}
