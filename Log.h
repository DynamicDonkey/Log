/*MIT License

Copyright(c) 2020 Chris

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

GITHUB REPO: https://github.com/llchris/Log
AUTHOR GITHUB: https://github.com/llchris
*/
#if !defined(_HEADER_LOG)
#define _HEADER_LOG

//Log's severity types
typedef enum {
	SevNone = -1,
	SevInfo = 0,
	SevWarn = 1,
	SevError = 2,
	SevFatal = 3,
	SevDebug = 4
} LogSeverity;

//Short-typing macros for severity types
#define snon SevNone
#define sinf SevInfo
#define swar SevWarn
#define serr SevError
#define sfat SevFatal
#define sdeb SevDebug

//The log function
//Uses printf() format
extern void Log(LogSeverity sev, char * fmt, ...);

//Rename the log's name
//DEFAULT - "Logger"
extern void LogRename(char * name);

//Reset the console's color
//After calling Log() the console's color gets overridden based on the severity level
//If you want to reset it you have to do it MANUALLY due to performance optim
extern void LogResetConsoleColor(void);

//Enable/Disable Fatal-Exit
//If true when calling Log() with fatal severity the app will shutdown with exitcode 8
//Default - FALSE
extern void LogSetFatalExit(_Bool fs);

//Enable/Disable Auto-FileFlush
//If true after calling Log() the file will be flushed
//Default - TRUE
extern void LogSetAutoFileFlush(_Bool af);

//Open a file for the log to print into
extern void LogOpenFile(char * file);

//Close the stream with the log's file when you are done logging
extern void LogCloseFile(void);

//Flush the log's file
extern void LogFlushFile(void);

#include <assert.h>

//If a test fails, log a message with severity
#define LogAssert(sev, test, ...) if(!test) { Log(sev, __VA_ARGS__); assert(0); }

#endif