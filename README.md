# Log
A simple neat log system written in C with ASCII colors
![Screen](https://github.com/llchris/Log/blob/master/img/console.PNG)
# Example Code
```
#include "log.h"

int main(void) {
	LogRename("MyEpicLogger");
	LogSetAutoFileFlush(0);
	LogSetFatalExit(0);

	LogOpenFile("log.txt");

	Log(SevNone, "This should not have a prefix");
	Log(SevInfo, "Printf-like format ! %d %s", 100, "donuts");
	Log(SevWarn, "This is a warning");
	Log(SevError, "ERRRRRRRRRR");
	Log(SevFatal, "Ouch thats a fatal");
	Log(SevDebug, "You should only see this in debug mode");

	LogRename("Loader");
	Log(sinf, "Loading assets!");
	Log(sinf, "Loading levels!");
	LogRename("Engine");
	Log(sdeb, "Version 1.0");

	int i = 23132;
	LogAssert(serr, i, "i == 0");

	LogFlushFile();
	LogCloseFile();
	LogResetConsoleColor();
	return 0;
}
```
# What gets written into the file
![Screen](https://github.com/llchris/Log/blob/master/img/file.PNG)
# Macros
The log system detects debug mode if one of those macros is defined: ```_DEBUG``` ```DEBUG``` ```BUILD_DEBUG```
You can also define ```LOG_NO_COLORS``` if you dont want the ASCII colors
