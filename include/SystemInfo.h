#include <string>
#include <cstdlib>

class sys
{
public:
	std::string m_cwd;
	std::uint16_t m_cores;
	std::uint16_t m_ram;

public:
	sys();
	sys(const sys& other) = delete;
	sys(sys&& other) = delete;
};

[[nodiscard]] std::string get_current_dir();
