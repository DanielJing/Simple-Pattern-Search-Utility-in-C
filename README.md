Simple Pattern Search Utility in C

This is a basic command-line utility written in C that searches for lines containing a specified pattern in a given file or standard input (stdin). It mimics a simplified version of the grep command.
Features

    Searches for a user-specified pattern in a file or from stdin.

    Prints all lines that contain the pattern to standard output.

    Supports reading from a file or from standard input if no file is specified.

    Handles errors such as missing arguments or failure to open a file.

Usage

bash
./pattern_search pattern [filename]

    pattern - The string pattern to search for in the input lines.

    filename (optional) - The name of the file to search. If omitted, the program reads from standard input.

Example

Search for the word "error" in a file named log.txt:

bash
./pattern_search error log.txt

Search for the pattern "hello" from standard input (e.g., piped input):

bash
cat file.txt | ./pattern_search hello

How it Works

    The program checks if at least one argument (the pattern) is provided.

    If a filename is given, it attempts to open the file; otherwise, it reads from stdin.

    It reads the input line-by-line, searching each line for the specified pattern using strstr().

    If the pattern is found in a line, the line is printed to stdout.

    The program closes the file (if opened) and exits.

Compilation

Compile the program using gcc:

bash
gcc -o pattern_search pattern_search.c

Notes

    The maximum line length supported is 1024 characters.

    The search is case-sensitive.

    The program does not support regular expressions, only simple substring matching.
