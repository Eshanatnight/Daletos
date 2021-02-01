#include <windows.h>
#include <string>
#include <iostream>

class sys
{

    private:
        std::string m_cwd;

    public:
        sys();

    private:
        const std::string& get_current_dir();
};

std::string get_current_dir();
