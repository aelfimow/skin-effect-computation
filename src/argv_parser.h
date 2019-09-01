#ifdef ARGV_PARSER_H
#error Already included
#else
#define ARGV_PARSER_H

#include <vector>
#include <string>

class argv_parser
{
    public:
        explicit argv_parser(int argc, char *argv[]);
        ~argv_parser();

        double frequency() const;
        std::string prefix() const;
        double sigma() const;

    private:
        std::vector<std::string> m_argv;
};

#endif
