std::string _2cVersion    = "1.0";
std::string _2cCommitHash;  //UNDONE
std::string _2cBuildDate  = __DATE__;
std::string _2cBuildTime  = __TIME__;

const char *_2cHomeUrl    = "http://wiki.dep111.rtc.local/tools:2c";
const char *_2cDistrPath  = "\\\\dep111\\Releases\\rdlc_stable\\latest\\distr";

#if defined(WIN32) || defined(_WIN32)
    const char *_2cSubPath    = "bin/2c.exe";
#else
    const char *_2cSubPath    = "bin/2c";
#endif